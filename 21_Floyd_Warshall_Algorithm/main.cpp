//
//  main.cpp
//  21_Floyd_Warshall_Algorithm
//
//  Created by 세광 on 2021/08/20.
//

#include <iostream>

using namespace std;

int number = 4;
int INF = 10000000;

// 자료 배열 초기화
int a[4][4] = {
    { 0, 5, INF, 8 },
    { 7, 0, 9, INF },
    { 2, INF, 0, 4 },
    { INF, INF, 3, 0 }
};

void FloydWarshall() {
    // 결과 그래프 초기화
    int d[number][number];
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            d[i][j] = a[i][j];
        }
    }
    
    // k = 거쳐가는 노드
    for (int k = 0; k < number; k++) {
        // i = 출발 노드
        for (int i = 0; i < number; i++) {
            // j = 도착 노드
            for (int j = 0; j < number; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            cout << d[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() {
    FloydWarshall();
}

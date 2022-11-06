#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

const int MAXN = 1005;

char g[MAXN][MAXN], col[MAXN][MAXN];
int dis[MAXN][MAXN];
int r, c;

queue<int> qi, qj;

void bfs(int i, int j){
    int i1, j1, i2, j2;
    qi.push(i);
    qj.push(j);
    while(!qi.empty()){
        i = qi.front();
        j = qj.front();
        qi.pop();
        qj.pop();
        for(i1 = -1; i1 <= 1; i1++){
            for(j1 = -1; j1 <= 1; j1++){
                if (abs(i1) + abs(j1) != 1)
                    continue;
                i2 = i + i1;
                j2 = j + j1;
                if (col[i2][j2] == 0 && (g[i2][j2] >= '0' && g[i2][j2] <= '9' || g[i2][j2] == 'S')){
                    qi.push(i2);
                    qj.push(j2);
                    dis[i2][j2] = dis[i][j] + 1;
                    col[i2][j2] = 1;
                }
            }
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int i, j, i0, j0, ans = 0;
    scanf("%d%d", &r, &c);
    for(i = 1; i <= r; i++){
        scanf("%s", &g[i][1]);
    }
    for(i = 1; i <= r; i++){
        for(j = 1; j <= c; j++){
            if (g[i][j] == 'E'){
                bfs(i, j);
            }
        }
    }
    for(i = 1; i <= r; i++){
        for(j = 1; j <= c; j++){
            if (g[i][j] == 'S'){
                i0 = i;
                j0 = j;
                for(i = 1; i <= r; i++){
                    for(j = 1; j <= c; j++){
                        if (g[i][j] >= '0' && g[i][j] <= '9' && dis[i][j] <= dis[i0][j0] && dis[i][j] > 0){
                            ans += g[i][j] - '0';
                        }
                    }
                }
                printf("%d", ans);
                return 0;
            }
        }
    }
}
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

char dp[MAXN][11][11];
char prv2[MAXN][11][11], prv3[MAXN][11][11];

char c[15];

stack<int> ans;

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int m, i, j, k, l, j1;
    scanf("%s%d", &c[1], &m);
    for(i = 1; i <= 10; i++){
        dp[0][i][i] = c[i] - '0';
    }
    for(i = 0; i < m - 1; i++){
        for(j = 1; j <= 10; j++){
            for(k = 1; k <= 10; k++){
                if (dp[i][j][k] == 0)
                    continue;
                for(l = j + 1; l <= 10; l++){
                    if (c[l] == '0' || l == k)
                        continue;
                    j1 = l - j;
                    dp[i + 1][j1][l] = 1;
                    prv2[i + 1][j1][l] = j;
                    prv3[i + 1][j1][l] = k;
                }
            }
        }
    }
    for(j = 1; j <= 10; j++){
        for(k = 1; k <= 10; k++){
            if (dp[m - 1][j][k] == 1){
                goto ll;
            }
        }
    }
    printf("NO");
    return 0;
ll: 
    printf("YES\n");
    for(i = m - 1; i >= 0; i--){
        ans.push(k);
        j1 = prv2[i][j][k];
        k = prv3[i][j][k];
        j = j1;
    }
    //ans.push(k);
    while(!ans.empty()){
        printf("%d ", ans.top());
        ans.pop();
    }
}
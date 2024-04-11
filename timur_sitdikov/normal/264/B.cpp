#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

const int maxn = 100000;
int nxt[maxn + 5][7], top[maxn + 5];

int dp[maxn + 5];
char good[maxn + 5], p[maxn + 5];

int main()
{   
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, i, j, a, last, ans, maxi;
    for(i = 2; i * i <= maxn; i++){
        if (!p[i]){
            for(j = i * i; j <= maxn; j += i){
                p[j] = 1;
            }
        }
    }
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a);
        good[a] = 1;
        dp[a] = 1;
    }
    for(i = 2; i <= maxn; i++){
        if (p[i])
            continue;
        last = 0;
        for(j = i; j <= maxn; j += i){
            if (good[j]){
                if (last != 0){
                    nxt[last][top[last]++] = j;
                }
                last = j;
            }
        }
    }
    for(i = 1; i <= maxn; i++){
        if (!good[i])
            continue;
        for(j = 0; j < top[i]; j++){
            dp[nxt[i][j]] = max(dp[nxt[i][j]], dp[i] + 1);
        }
    }
    ans = 0;
    for(i = 1; i <= maxn; i++){
        if (good[i]){
            if (dp[i] > ans)
                ans = dp[i];
        }
    }
    printf("%d", ans);
}
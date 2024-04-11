#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <algorithm>
#include <complex>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair<int, int>

#define file "cycle"

const int MAXN = 3e4 + 1, MAXV = 600;

int cnt[MAXN];
int dp[MAXN][MAXV];

void solve(){
    int n, d, i, j, k, a, l, offset = 300, ind;
    scanf("%d%d", &n, &d);
    for(i = 0; i < n; i++){
        scanf("%d", &a);
        cnt[a]++;   
    }
    dp[d][offset] = cnt[d] + 1;
    int ans = cnt[d] + 1;
    for(i = d; i < MAXN; i++){
        for(k = 0; k < MAXV; k++){
            if (dp[i][k] == 0){
                continue;
            }
            l = k - offset + d;
            if (l <= 0){
                continue;
            }
            for(j = max(l - 1, 1); j <= l + 1; j++){
                ind = j - d + offset;
                if (i + j < MAXN){
                    dp[i + j][ind] = max(dp[i + j][ind], dp[i][k] + cnt[i + j]);
                    ans = max(ans, dp[i + j][ind]);
                }
            }
        }
    }
    printf("%d\n", ans - 1);
}   

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    while(t--){
        solve();    
    }
}
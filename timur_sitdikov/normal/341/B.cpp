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

const int MAXN = 100005, INF = 1e9;

int dp[MAXN], a[MAXN];

void solve(){
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i <= n; i++){
        dp[i] = INF;
    }
    dp[0] = 0;
    for(i = 0; i < n; i++){
        int offset = upper_bound(dp, dp + n, a[i]) - dp;
        dp[offset] = a[i];
    }
    int ans = 0;
    for(i = 1; i <= n; i++){
        if (dp[i] < INF){
            ans = i;
        }
    }
    printf("%d", ans);
}

int main(){ 
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int t;
    t = 1;
    while(t){
        t--;
        solve();
    }
}
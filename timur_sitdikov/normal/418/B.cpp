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
#include <cassert>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>
#define xx real()
#define yy imag()

#define FILE "file"

const int MAXN = 105, MAXM = 20;

const long long INF = 2e18;
long long dp[1 << MAXM];
pair<long long, pair<long long, int> > pp[MAXN];

void solve(){
    int n, i, j, k, m, a;
    long long b;
    cin >> n >> m >> b;
    for(i = 0; i < n; i++){
        cin >> pp[i].second.first >> pp[i].first >> k;
        for(j = 0; j < k; j++){
            cin >> a;
            a--;
            pp[i].second.second |= (1 << a);
        }
    }
    sort(pp, pp + n);
    for(i = 0; i < (1 << m); i++){
        dp[i] = INF;
    }
    dp[0] = 0;
    long long ans = INF;
    for(i = 0; i < n; i++){
        int mask = pp[i].second.second;
        long long add = pp[i].second.first;
        for(j = 0; j < (1 << m); j++){
            dp[j | mask] = min(dp[j | mask], dp[j] + add);
        }
        ans = min(ans, dp[(1 << m) - 1] + pp[i].first * b);
    }
    if (ans == INF){
        cout << -1;
    }
    else {
        cout << ans;
    }
    
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //assert(freopen(FILE ".in", "r", stdin));assert(freopen(FILE ".out", "w", stdout));
    int t = 1;
    while(t){
        t--;
        solve();
    }
}
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
typedef vector<int> vi;

const int MAXN = 550005, INF = 1e9;

int dp[MAXN], v[55];

void solve(){
    int n, i, j, d, ind, ind1;
    scanf("%d%d", &n, &d);
    for(i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    for(i = 0; i < MAXN; i++){
        dp[i] = dp[i] = INF;
    }
    dp[0] = 0;
    for(i = 0; i < n; i++){
        for(j = MAXN - 1; j >= 0; j--){
            if (dp[j] == INF){
                continue;
            }
            if (j + v[i] < MAXN){
                dp[j + v[i]] = 0;
            }
        }
    }
    int ans, ans_cnt, tmp;
    ind = 0;
    while(1){
        ind1 = 0;
        for(i = ind + 1; i <= min(ind + d, MAXN - 1); i++){
            if (dp[i] < INF){
                dp[i] = dp[ind] + 1;
                ind1 = i;
            }
        }
        if (ind1 == 0){
            break;
        }
        ind = ind1;
    }
    ans = ind;
    ans_cnt = dp[ind];  
    printf("%d %d", ans, ans_cnt);
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
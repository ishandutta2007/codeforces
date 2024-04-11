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

const int MAXN = 1 << 20;
const int MAXLOG = 20;

const int MOD = 1e9 + 7;

int cnt[MAXN], real_cnt[MAXN], bit_cnt[MAXN];
ll dp[MAXN][MAXLOG];
int st2[MAXN];

void solve(){
    int n, i, j, k, a;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a);
        cnt[a]++;   
    }
    st2[0] = 1;
    for(i = 1; i <= n; i++){
        st2[i] = 2 * st2[i - 1];
        if (st2[i] >= MOD){
            st2[i] -= MOD;
        }
    }
    for(i = MAXN - 1; i >= 0; i--){
        dp[i][0] = cnt[i];
        for(k = 1; k < MAXLOG; k++){
            dp[i][k] /= k;
        }
        for(j = 0; j < MAXLOG; j++){
            if (i & (1 << j)){
                for(k = 1; k < MAXLOG; k++){
                    dp[i ^ (1 << j)][k] = dp[i ^ (1 << j)][k] + dp[i][k - 1];
                }
            }
        }
    }
    for(i = 0; i < MAXN; i++){
        for(k = 0; k < MAXLOG; k++){
            real_cnt[i] = real_cnt[i] + dp[i][k];
        }
    }
    for(i = 0; i < (1 << 10); i++){
        for(j = 0; j < 10; j++){
            if (i & (1 << j)){
                bit_cnt[i]++;
            }
        }
    }
    for(i = 0; i < MAXN; i++){
        bit_cnt[i] = bit_cnt[i & 1023] + bit_cnt[i >> 10];
    }
    int ans = 0;
    for(i = 0; i < MAXN; i++){
        if (bit_cnt[i] & 1){
            ans = ans - st2[real_cnt[i]];
            if (ans < 0){
                ans += MOD;
            }
        } else {
            ans = ans + st2[real_cnt[i]];
            if (ans >= MOD){
                ans -= MOD;
            }
        }
        //printf("%d %d\n", i, real_cnt[i]);
    }
    printf("%d\n", ans);
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
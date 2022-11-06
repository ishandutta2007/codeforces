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

const long long MAXN = 2005, MOD = 1000000007;

long long c[MAXN][MAXN], st2[MAXN], f[MAXN];

int per[MAXN], used[MAXN], used_ind[MAXN];

void solve(){
    int n, i, j, a, b;
    scanf("%d", &n);
    a = 0;
    for(i = 1; i <= n; i++){
        used[i] = 1;
    }
    for(i = 1; i <= n; i++){
        scanf("%d", &per[i]);
        if (per[i] == -1){
            used_ind[i] = 1;
            a++;
        }
        else {
            used[per[i]] = 0;
        }
    }
    b = 0;
    for(i = 1; i <= n; i++){
        if (used[i] == 1 && used_ind[i] == 1){
            b++;
        }
    }
    for(i = 0; i <= b; i++){
        c[i][i] = c[i][0] = 1;
    }
    for(i = 1; i <= b; i++){
        for(j = 1; j < i; j++){
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
    st2[0] = 1;
    f[0] = 1;
    for(i = 1; i <= a; i++){
        st2[i] = (st2[i - 1] * 2) % MOD;
        f[i] = (f[i - 1] * i) % MOD;
    }
    long long ans = 0, tmp;
    for(i = 0; i <= b; i++){
        tmp = (c[b][i] * f[a - i]) % MOD;
        if (i & 1){
            
            ans = (ans - tmp + MOD) % MOD;
        }
        else {
            ans = (ans + tmp) % MOD;
        }
    }
    printf("%I64d", ans);
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
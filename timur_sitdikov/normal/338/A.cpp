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

const long long MOD = 1000000009;

long long pow_mod(long long v, long long st){
    long long ans = 1., a = v;
    for(; st; st /= 2){
        if (st & 1){
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
    }
    return ans;
}

void solve(){
    long long n, m, k, c, ans;
    cin >> n >> m >> k;
    if (m <= n - n / k){
        ans = m;
        cout << m;
        return;
    }
    c = m - (n - n / k);
    ans = pow_mod(2, c + 1);
    ans = (ans - 2 + MOD) % MOD;
    ans = (ans * k) % MOD;
    long long ost = m - c * k;
    ans = (ans + ost) % MOD;
    cout << ans;
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
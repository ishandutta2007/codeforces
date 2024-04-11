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

const ll MOD = 1e9 + 7;

ll bin_pow(ll a, ll st){
    ll ans = 1ll;
    for(; st; st /= 2){
        if (st & 1){
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
    }
    return ans;
}

ll get_inv(ll a){
    return bin_pow(a, MOD - 2);
}

ll f[100];
ll inv[100];

void solve(){
    ll s, y, sgn, _f;
    int n, i, j;
    cin >> n >> s;
    for(i = 0; i < n; i++){
        cin >> f[i];
    }
    _f = 1ll;
    for(i = 1; i < n; i++){
        inv[i] = get_inv((ll)i);
        _f = (_f * inv[i]) % MOD;
    }
    ll ans = 0, cur;
    for(i = 0; i < (1 << n); i++){
        y = s;
        sgn = 1;
        for(j = 0; j < n; j++){
            if (i & (1 << j)){
                y -= (f[j] + 1);
                sgn = -sgn;
            }
        }
        if (y < 0){
            continue;
        }
        y %= MOD;
        cur = 1ll;
        for(j = 1; j < n; j++){
            cur = (cur * (y + j)) % MOD;
            //cur = (cur * inv[j]) % MOD;
        }
        cur = (cur * _f) % MOD;
        if (sgn == -1){
            cur = (MOD - cur) % MOD;
        }
        //printf("%d %lld\n", i, cur);
        ans = (ans + cur) % MOD;
    }
    cout << ans << endl;
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
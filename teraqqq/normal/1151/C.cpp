#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

ll L, R;

int sum(ll l, ll r, int d) {
    if(l > r) return 0;
    
    //cout << "sum[" << d <<"] => " << l << ":" << r << endl;
    l %= MOD; r %= MOD;
    return ((l+r+d)%MOD)*((r-l+1)%MOD)%MOD;
}

int prefix(ll r) {
    ll da = 0, db = 0, step = 1;
    int s = 1, res = 0;
    while(da + db + step < r) {
        if(s) res = (res + sum(da, da+step-1, 1)) % MOD, da += step;
        else  res = (res + sum(db, db+step-1, 2)) % MOD, db += step;
        step *= 2, s = s ^ 1;
    }
    
    step = r - da - db;
    if(s) res = (res + sum(da, da+step-1, 1)) % MOD;
    else  res = (res + sum(db, db+step-1, 2)) % MOD;
    
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> L >> R;
    cout << ((ll)prefix(R) + 2*MOD - prefix(L-1)) % MOD << endl;
}
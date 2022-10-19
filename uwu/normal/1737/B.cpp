#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll rt(ll N){
    ll lo = 1, hi = 1e9;
    while (lo < hi){
        ll mi = (lo + hi + 1) >> 1;
        if (mi*mi <= N) lo = mi;
        else hi = mi-1;
    }
    return lo;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        ll L, R; cin >> L >> R;
        ll sl = rt(L);
        ll sr = rt(R);
        ll l = 3*(sl+1);
        ll r = 3*sr;
        if (sl * sl + 2*sl >= L) l--;
        if (sl * sl + sl >= L) l--;
        if (sl * sl >= L) l--;
        if (sr * sr + sr <= R) r++;
        if (sr * sr + 2*sr <= R) r++;
        cout << r-l+1 << '\n';
    }
}
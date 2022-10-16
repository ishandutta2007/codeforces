#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return b > a ? a = b, true : false; }

const ll MOD = 998244353;

ll rev(ll a, ll m = MOD) {
    return a < 2 ? 1 : m - (ll)m*rev(m%a, a)/a;
}

ll pow(ll a, ll n) {
    a %= MOD; if(a < 0) a += MOD;
    ll res = 1;
    for(ll j = a; n != 0; n >>= 1, j =j*j%MOD)
        if(n&1) res = res*j%MOD;
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m, l, r; cin >> n >> m >> l >> r;
    ll b0 = r/2 - (l-1)/2;
    ll b1 = (r+1)/2 - l/2;

    if(n%2==0 || m%2==0)
        cout << (pow(b0-b1, (ll)n*m) + pow(b0+b1, (ll)n*m))*rev(2)%MOD << endl;
    else cout << pow(b0+b1, (ll)n*m) << endl;
}
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt")

#include <immintrin.h>
#include <malloc.h>
#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define eb emplace_back

using namespace std;
using ll = long long;
using vi = vector<int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return b > a ? a = b, true : false; }

mt19937 rng;

const int INF = 1e9;
const int MOD = 1e9+7;

ll solve() {
    ll p, q, x = 1; cin >> p >> q;
    ll t = q;
    map<ll, int> divs;
    for(ll d = 2; d*d <= t; ++d)
        while(t % d == 0) t /= d, divs[d]++;
    if(t != 1) divs[t]++;

    vector<ll> mul;
    for(auto [m, i] : divs) {
        int j = 0;
        ll y = 1;
        while(p % m == 0) p /= m, y *= m, ++j;
        //cout << y << ' ' << j << ' ' << m << endl;
        for(int t = 0; t < min(i-1,j); ++t) x *= m, y /= m;
        //cout << "* " << y << endl;
        mul.pb(y);
    }

    x *= p;
    sort(mul.rbegin(), mul.rend());
    for(int i = 0; i < (int)mul.size()-1; ++i)
        x *= mul[i];

    return x;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    rng.seed(chrono::steady_clock::now().time_since_epoch().count());

    int t; cin >> t; while(t--) cout << solve() << '\n';
}
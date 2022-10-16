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
const int MOD = 998244353;

ll rev(ll a, ll m = MOD) {
    return a == 1 ? 1 : m - m*rev(m%a,a)/a;
}

void solve() {
    ll ans = 0;
    int n; cin >> n;
    vector<int> a(2*n); for(int& x : a) cin >> x;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; ++i) ans += a[i+n] - a[i];
    ans %= MOD;
    for(int i = n+1; i <= 2*n; ++i) ans = ans*i%MOD;
    for(int i= 1; i <= n; ++i) ans = ans*rev(i)%MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    rng.seed(chrono::steady_clock::now().time_since_epoch().count());

    solve();
    //int t; cin >> t; while(t--) cout << solve() << '\n';
}
#include <bits/stdc++.h>

#define F first
#define S second

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

const int N = 2e5+7;
const int MOD = 1e9+7;
const int M = 2*N;

int fact[M+1], rfct[M+1];

int rev(int a, int m) {
    return a == 1 ? 1 : m - (ll)m*rev(m%a,a)/a;
}

int path_cnt(int x, int y) {
    if (x < 0 || y < 0) return 0;
    return (ll)fact[x+y]*rfct[x]%MOD*rfct[y]%MOD;
}

void solve() {
    int n; cin >> n; ++n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    ll ans = 0;

    for (int i = 0; i < n; ++i) {
        ans += path_cnt(i+1, a[i]-1);
    }

    ans %= MOD;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    fact[0] = 1;
    for (int i = 1; i <= M; ++i) fact[i] = (ll)fact[i-1]*i%MOD;
    rfct[M] = rev(fact[M], MOD);
    for (int i = M; i >= 1; --i) rfct[i-1] = (ll)rfct[i]*i%MOD;

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
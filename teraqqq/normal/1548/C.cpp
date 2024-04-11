#include <bits/stdc++.h>

#define F first
#define S second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

const int MOD = 1e9+7;
const int N = 3e6+1337;

int fact[N], rfct[N], a[N], b[N];

int rev(int a, int m = MOD) {
    return a == 1 ? 1 : m - (ll)m *rev(m%a, a)/a;
}

int c(int n, int k) {
    return (ll) fact[n] * rfct[k] % MOD * rfct[n-k] % MOD;
}

void solve() {
    int n, q; cin >> n >> q;

    fact[0] = rfct[0] = 1;
    for (int i = 1; i <= 3*n+3; ++i) {
        fact[i] = (ll) i * fact[i-1] % MOD;
        rfct[i] = (ll) rev(i) * rfct[i-1] % MOD;
    }

    for (int i = 1; i <= 3*n+3; ++i) {
        a[i] = c(3*n+3,i);
    }

    for (int i = 3*n; i >= 0; i--) {
        const int t = a[i+3];
        a[i+3] = 0;
        a[i+2] = (a[i+2] + (ll) (MOD - t) * 3) % MOD;
        a[i+1] = (a[i+1] + (ll) (MOD - t) * 3) % MOD;
        b[i] = t;
    }

    while (q--) {
        int x; cin >> x;
        cout << b[x] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t; 
    while(t--) solve();
}
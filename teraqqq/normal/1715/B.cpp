#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using ll = long long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, true : false; }

template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;
template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;

void solve() {
    int n;
    ll k, b, s; cin >> n >> k >> b >> s;

    if (b*k <= s && s <= b*k + (k-1)*n) {
        vector<ll> v(n);
        s -= b * k;
        for (int i = 0; i < n; ++i) v[i] += (b + i) / n * k;

        for (int i = 0; i < n; ++i) {
            ll kek = min(s, k-1);
            s -= kek;
            v[i] += kek;
        }

        for (ll x : v) cout << x << ' ';
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}
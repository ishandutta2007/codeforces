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

vector<pair<int, ll>> wow(const vector<int>& a, int m) {
    vector<pair<int, ll>> res;

    for (int x : a) {
        ll c = 1;
        while (x % m == 0) {
            x /= m;
            c *= m;
        }

        if (res.empty() || res.back().F != x) {
            res.emplace_back(x, c);
        } else {
            res.back().S += c;
        }
    }

    return res;
}

void solve() {
    int n, m; cin >> n >> m;

    vector<int> a(n); for (int& x : a) cin >> x;
    int k; cin >> k;
    vector<int> b(k); for (int& x : b) cin >> x;

    cout << (wow(a, m) == wow(b, m) ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        solve();
    }
}
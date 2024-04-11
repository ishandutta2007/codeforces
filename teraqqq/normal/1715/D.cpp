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

const int w = 30;
const int all_bits = (1 << w) - 1;

void solve() {
    int n, q; cin >> n >> q;
    vector<vector<pi>> ref(n);

    vector<int> up(n, all_bits), res(n);

    for (int t = 0; t < q; ++t) {
        int i, j, x; cin >> i >> j >> x; --i, --j;
        if (i > j) swap(i, j);
        ref[i].emplace_back(j, x);
        up[i] &= x;
        up[j] &= x;
        if (i == j) res[i] = x;
    }

    for (int i = 0; i < n; ++i) {
        for (auto [j, x] : ref[i]) {
            res[i] |= x & (all_bits ^ up[j]);
        }

        for (auto [j, x] : ref[i]) {
            res[j] |= x & (all_bits ^ res[i]);
        }
    }

    for (int x:  res) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
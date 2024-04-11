#include <bits/stdc++.h>

using namespace std;
using ll = long  long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

void solve() {
    int n, m; cin >> n >> m;
    set<int> s;
    for (int i = 1; i <= n; ++i) s.insert(i);
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        s.erase(b);
    }

    int x = *s.begin();
    for (int i = 1; i <= n; ++i) {
        if (i != x) cout << i << " " << x << "\n";
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
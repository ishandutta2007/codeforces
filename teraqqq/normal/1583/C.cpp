#include <bits/stdc++.h>

using namespace std;
using ll = long  long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> s(n);
    for (auto& u : s) cin >> u;

    vector<int> near(m, (int)1e9);
    for (int i = m - 2; i >= 0; --i) {
        bool block = false;
        for (int j = 1; j < n; ++j) {
            if (s[j][i] == 'X' && s[j-1][i+1] == 'X') block = true;
        }

        if (block) near[i] = i;
        else near[i] = near[i+1];
    }

    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        cout << (near[l-1] >= r-1 ? "YES" : "NO") << '\n';
    }
}
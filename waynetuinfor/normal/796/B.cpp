#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5;
bool h[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int tmp; cin >> tmp;
        h[tmp] = true;
    }
    int pos = 1;
    for (int i = 0; i < k; ++i) {
        if (h[pos]) return cout << pos << '\n', 0;
        int u, v; cin >> u >> v;
        if (u == pos) {
            pos = v;
        } else if (v == pos) {
            pos = u;
        }
    }
    cout << pos << '\n';
    return 0;
}
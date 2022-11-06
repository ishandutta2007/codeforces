#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;

struct Dsu {
    int par[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i) par[i] = i;
    }
    int find(int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    }
    bool merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        par[x] = y;
        return true;;
    }
} dsu;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> del;
    dsu.init();
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        if (!dsu.merge(a, b)) del.push_back(make_pair(a, b));
    }
    cout << del.size() << endl;
    for (auto i : del) {
        for (int j = 2; j <= n; ++j) {
            if (dsu.merge(1, j)) {
                cout << i.first << ' ' << i.second << ' ' << 1 << ' ' << j << endl;
                break;
            }
        }
    }
    return 0;
}
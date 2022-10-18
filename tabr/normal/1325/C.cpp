#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> e(n - 1);
    vector<int> deg(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        e[i] = {u, v};
        deg[u]++;
        deg[v]++;
    }
    if (*max_element(deg.begin(), deg.end()) <= 2) {
        for (int i = 0; i < n - 1; i++) {
            cout << i << '\n';
        }
        return 0;
    }
    int v;
    for (int i = 0; i < n - 1; i++) {
        if (deg[i] >= 3) {
            v = i;
            break;
        }
    }
    int id = 3, cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (cnt == 3 || (e[i].first != v && e[i].second != v)) {
            cout << id << '\n';
            id++;
        } else {
            cout << cnt << '\n';
            cnt++;
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        map<int, vector<int>> c;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            c[a].emplace_back(i);
        }
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            if (!c.count(a) || !c.count(b)) {
                cout << "NO" << '\n';
                continue;
            }
            if (c[a][0] <= c[b].back()) {
                cout << "YES" << '\n';
            } else {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int main() {
    int n, m; cin >> n >> m;
    if (m < n - 1) {
        cout << "Impossible" << endl;
        return 0;
    }
    vector<pair<int, int>> ed;
    for (int i = 2; i <= n; ++i) ed.emplace_back(1, i);
    m -= n - 1;
    for (int i = 2; i <= n && m; ++i) {
        for (int j = 2; j < i && m; ++j) if (__gcd(i, j) == 1) {
            ed.emplace_back(i, j);
            --m;
        }
    } 
    if (m) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    for (int i = 0; i < ed.size(); ++i) cout << ed[i].first << ' ' << ed[i].second << endl;
}
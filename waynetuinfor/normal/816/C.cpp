#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
int g[maxn][maxn];
vector<pair<string, int>> ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> g[i][j];
    while (true) {
        int mn = 510, mi = 0, mj = 0;
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
            if (g[i][j] < mn && g[i][j] != 0) mn = g[i][j], mi = i, mj = j;
        }
        if (mn == 510) break;
        int ok = 0; bool jizz1 = true;
        for (int i = 1; i <= m; ++i) if (g[mi][i] == 0) jizz1 = false;
        if (jizz1) ++ok;
        bool jizz2 = true;
        for (int i = 1; i <= n; ++i) if (g[i][mj] == 0) jizz2 = false;
        if (jizz2) ++ok;
        if (ok == 0) return cout << "-1" << endl, 0;
        if (jizz1 && jizz2) {
            if (n < m) {
                for (int i = 1; i <= m; ++i) g[mi][i]--;
                ans.push_back(make_pair("row", mi));
            } else {
                for(int i = 1; i <= n; ++i) g[i][mj]--;
                ans.push_back(make_pair("col", mj));
            }
        } else if (!jizz2) {
            for (int i = 1; i <= m; ++i) g[mi][i]--;
            ans.push_back(make_pair("row", mi));
        } else {
            for (int i = 1; i <= n; ++i) g[i][mj]--;
            ans.push_back(make_pair("col", mj));
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto i : ans) cout << i.first << ' ' << i.second << endl;
    return 0;
}
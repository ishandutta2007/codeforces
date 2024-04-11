#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> pt[2][maxn + maxn];
int g[maxn], p[maxn], t[maxn], anid[maxn];
pair<int, int> ans[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, w, h; cin >> n >> w >> h;
    for (int i = 0; i < n; ++i) {
        cin >> g[i] >> p[i] >> t[i]; --g[i];
        pt[g[i]][t[i] - p[i] + maxn].push_back(i);
        if (g[i]) ans[i] = make_pair(w, p[i]);
        else ans[i] = make_pair(p[i], h);
    }
    for (int i = 0; i < maxn + maxn; ++i) if (pt[0][i].size() || pt[1][i].size()) {
        sort(pt[0][i].begin(), pt[0][i].end(), [&](const int &a, const int &b) { return p[a] < p[b]; });
        sort(pt[1][i].begin(), pt[1][i].end(), [&](const int &a, const int &b) { return p[a] < p[b]; });
        vector<int> aid;
        for (int j = 0; j < pt[1][i].size(); ++j) aid.push_back(pt[1][i][j]);
        for (int j = pt[0][i].size() - 1; j >= 0; --j) aid.push_back(pt[0][i][j]);
        size_t ptr = 0;
        for (int j = pt[0][i].size() - 1; j >= 0; --j) anid[pt[0][i][j]] = aid[ptr++];
        for (int j = 0; j < pt[1][i].size(); ++j) anid[pt[1][i][j]] = aid[ptr++];
    }
    for (int i = 0; i < n; ++i) cout << ans[anid[i]].first << ' ' << ans[anid[i]].second << endl;
    return 0;
}
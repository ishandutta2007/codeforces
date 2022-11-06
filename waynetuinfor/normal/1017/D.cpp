#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
short w[20];
short d[4100][4100];
int cnt[4100];
int ans[4100];
int res[maxn];
vector<pair<short, int>> tr[200];
vector<pair<short, short>> pr[1500];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, q; cin >> n >> m >> q;
    for (int i = 0; i < n; ++i) cin >> w[i];
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            for (int k = 0; k < n; ++k) if ((i >> k & 1) == (j >> k & 1)) d[i][j] += w[k];
        }
    }
    for (int i = 0; i < m; ++i) {
        string s; cin >> s;
        int x = 0;
        for (int j = 0; j < n; ++j) if (s[j] == '1') x ^= (1 << j);
        ++cnt[x];
    }
    vector<tuple<int, int, int>> qr;
    for (int i = 0; i < q; ++i) {
        string s; cin >> s;
        int x = 0;
        for (int j = 0; j < n; ++j) if (s[j] == '1') x ^= (1 << j);
        int k; cin >> k;
        tr[k].emplace_back(x, i);
    }
    for (short i = 0; i < (1 << n); ++i) for (short j = 0; j < (1 << n); ++j) {
        if (d[i][j] > 100) continue;
        pr[d[i][j]].emplace_back(i, j);
    }
    int j = 0, c = 0;
    for (int k = 0; k <= 100; ++k) for (int _ = 0; _ < tr[k].size(); ++_) {
        short x; int z; tie(x, z) = tr[k][_];
        while (j <= k) {
            while (j <= k && c >= pr[j].size()) c = 0, ++j;
            if (j > k) break;
            ans[pr[j][c].second] += cnt[pr[j][c].first];
            ++c;
        }
        res[z] = ans[x];
    }
    for (int i = 0; i < q; ++i) cout << res[i] << '\n';
    return 0;
}
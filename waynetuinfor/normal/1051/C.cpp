#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
vector<int> p[maxn];
int dp[maxn][maxn][maxn];
int ans[maxn];
pair<int, int> fr[maxn][maxn][maxn];

int main() {
    int n; scanf("%d", &n);
    vector<int> ds;
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        p[x].push_back(i);
        ds.push_back(x);
    }
    sort(ds.begin(), ds.end());
    ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
    dp[0][0][0] = 1;
    for (int i = 0; i < ds.size(); ++i) {
        for (int j = 0; j < 100; ++j) {
            for (int k = 0; k < 100; ++k) {
                if (dp[i][j][k] == 0) continue;
                int y = ds[i];
                if (p[y].size() == 1) {
                    dp[i + 1][j + 1][k] = 1;
                    fr[i + 1][j + 1][k] = make_pair(j, k);
                    dp[i + 1][j][k + 1] = 1;
                    fr[i + 1][j][k + 1] = make_pair(j, k);
                }
                if (p[y].size() == 2) {
                    dp[i + 1][j + 1][k + 1] = 1;
                    fr[i + 1][j + 1][k + 1] = make_pair(j, k);
                    dp[i + 1][j][k] = 1;
                    fr[i + 1][j][k] = make_pair(j, k);
                }
                if (p[y].size() > 2) {
                    dp[i + 1][j + 1][k] = 1;
                    fr[i + 1][j + 1][k] = make_pair(j, k);
                    dp[i + 1][j][k + 1] = 1;
                    fr[i + 1][j][k + 1] = make_pair(j, k);
                    dp[i + 1][j][k] = 1;
                    fr[i + 1][j][k] = make_pair(j, k);
                }
            }
        }
    }
    int f = -1;
    for (int i = 0; i <= 100; ++i) {
        if (dp[ds.size()][i][i] == 1) f = i;
    }
    if (f == -1) {
        puts("NO");
        return 0;
    }
    int j = f, k = f;
    for (int i = ds.size(); i > 0; --i) {
        int tj = fr[i][j][k].first, tk = fr[i][j][k].second;
        int x = ds[i - 1];
        if (p[x].size() == 1) {
            if (tj == j - 1) ans[p[x][0]] = 0;
            else ans[p[x][0]] = 1;
        }
        if (p[x].size() == 2) {
            if (tj == j - 1 && tk == k - 1) {
                ans[p[x][0]] = 0;
                ans[p[x][1]] = 1;
            } else {
                ans[p[x][0]] = 0;
                ans[p[x][1]] = 0;
            }
        }
        if (p[x].size() > 2) {
            if (tj == j - 1) {
                ans[p[x][0]] = 0;
                for (int z = 1; z < p[x].size(); ++z) ans[p[x][z]] = 1;
            } else if (tk == k - 1) {
                ans[p[x][0]] = 1;
                for (int z = 1; z < p[x].size(); ++z) ans[p[x][z]] = 0;
            } else {
                for (int z : p[x]) ans[z] = 0;
            }
        }
        j = tj, k = tk;
    }
    puts("YES");
    for (int i = 0; i < n; ++i) {
        if (ans[i]) printf("B");
        else printf("A");
    }
    puts("");
}
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n, m;

const int N = 2005;

vector<int> edge[N];

bool vis[N];
int col[N], dep[N], low[N];

vector<int> ord;
vector<vector<int> > block;

int cost[N];

void dfs(int u) {
    vis[u] = true;
    low[u] = dep[u];
    ord.push_back(u);
    for (int i = 0; i < (int)edge[u].size(); ++i) {
        int v = edge[u][i];
        if (vis[v]) {
            if (dep[v] < dep[u] - 1) {
                low[u] = min(low[u], dep[v]);
            }
        } else {
            dep[v] = dep[u] + 1;
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (low[u] == dep[u]) {
        vector<int> tmp;
        do {
            tmp.push_back(ord.back());
            ord.pop_back();
        } while (tmp.back() != u);
        block.push_back(tmp);
    }
}

vector<int> edge2[N], ch[N];

int size[N], all;

vector<int> ord2;

void dfs2(int u, int fa) {
    for (int i = 0; i < (int)edge2[u].size(); ++i) {
        int v = edge2[u][i];
        if (v == fa) {
            continue;
        }
        dfs2(v, u);
        ch[u].push_back(size[v]);
        size[u] += size[v];
        cost[u] += cost[v] + size[v] * block[u].size();
    } 
}

bool dp[2][N];

int solve(int u) {
    int ret = 0;
    block.clear();
    dfs(u);
    for (int i = 0; i < (int)block.size(); ++i) {
        for (int j = 0; j < (int)block[i].size(); ++j) {
            int u = block[i][j];
            col[u] = i;
        }
        ret += block[i].size() * block[i].size();
    }
    int m = block.size();
    if (m == 1) {
        return ret;
    }
    all = 0;
    for (int i = 0; i < m; ++i) {
        edge2[i].clear();
        for (int j = 0; j < (int)block[i].size(); ++j) {
            int u = block[i][j];
            for (int k = 0; k < (int)edge[u].size(); ++k) {
                int v = edge[u][k];
                if (col[u] != col[v]) {
                    edge2[col[u]].push_back(col[v]);
                }
            }
        }
        ch[i].clear();
        sort(edge2[i].begin(), edge2[i].end());
        edge2[i].erase(unique(edge2[i].begin(), edge2[i].end()), edge2[i].end());
        size[i] = block[i].size();
        all += size[i];
    }
    int best = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            size[j] = block[j].size();
            cost[j] = 0;
            ch[j].clear();
        }
        dfs2(i, -1);
        int tmp = 0;
        vector<int> &s = ch[i]; 
        int cur = block[i].size();
        sort(s.begin(), s.end());
        if (s.back() >= all - cur - s.back()) {
            int in = s.back(), out = all - cur - in;
            tmp = in * out;
        } else {
            memset(dp[0], 0, sizeof(bool) * (all + 1));
            int now = 0, sum = 0;
            dp[now][0] = true;
            for (int j = 0; j < (int)s.size(); ++j) {
                int delta = s[j], next = now ^ 1;
                memset(dp[next], 0, sizeof(bool) * (sum + delta + 1));
                for (int k = 0; k <= sum; ++k) {
                    if (dp[now][k]) {
                        dp[next][k + delta] = dp[next][abs(k - delta)] = true;
                    }
                }
                now = next;
                sum += delta;
            }
            for (int j = 0; j <= sum; ++j) {
                if (dp[now][j]) {
                    int in = (all - cur + j) / 2, out = (all - cur - j) / 2;
                    tmp = max(tmp, in * out);
                }
            }
        }
        best = max(best, tmp + cost[i]);
    }
    return ret + best;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            ans += solve(i);
        }
    }
    printf("%d\n", ans);
    return 0;
}
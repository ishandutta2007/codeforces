#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, m;

const int N = 100005;

vector<int> edge[N];

bool vis[N];

vector<int> stack;

int dep[N];

int ans;

void dfs(int u, int fa) {
    vis[u] = true;
    stack.push_back(u);
    for (int j = 0; j < (int)edge[u].size(); ++j) {
        int v = edge[u][j];
        if (v == fa) {
            continue;
        }
        if (!vis[v]) {
            dep[v] = dep[u] + 1;
            dfs(v, u);
        } else if (dep[v] < dep[u]) {
            int cnt = edge[u].size() > 2, p = stack.size() - 1;
            while (stack[p] != v) {
                --p;
                cnt += edge[stack[p]].size() > 2;
            }
            if (cnt < 2) {
                ++ans;
            }
        }
    }
    stack.pop_back();
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        edge[u].push_back(v), edge[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        ans += edge[i].size() % 2;
    }
    ans /= 2;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i, -1);
        }
    }
    printf("%d %d\n", ans, m);
    return 0;
}
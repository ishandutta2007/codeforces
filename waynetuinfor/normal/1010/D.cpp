#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
vector<int> g[maxn];
int op[maxn], pos[maxn], v[maxn], ans[maxn];
bool leaf[maxn], dlt[maxn];
char s[10];

int dfs(int x) {
    if (leaf[x]) return v[x];
    if (op[x] < 3) {
        int a = dfs(g[x][0]), b = dfs(g[x][1]);
        if (op[x] == 0) {
            if (a == 0) dlt[g[x][1]] = false;
            else dlt[g[x][1]] = true;
            if (b == 0) dlt[g[x][0]] = false;
            else dlt[g[x][0]] = true;
            return a && b;
        }
        if (op[x] == 1) {
            if (a == 1) dlt[g[x][1]] = false;
            else dlt[g[x][1]] = true;
            if (b == 1) dlt[g[x][0]] = false;
            else dlt[g[x][0]] = true;
            return a || b;
        } 
        dlt[g[x][0]] = dlt[g[x][1]] = true;
        return a ^ b;
    }
    dlt[g[x][0]] = true;
    return !dfs(g[x][0]);
}

void dfs2(int x) {
    if (leaf[x]) ans[x] = 1;
    for (int u : g[x]) if (dlt[u]) dfs2(u);
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        if (s[0] == 'A' || s[0] == 'O' || s[0] == 'X') {
            int u, v; scanf("%d %d", &u, &v);
            --u, --v;
            pos[u] = 0, pos[v] = 1;
            g[i].push_back(u), g[i].push_back(v);
        } else if (s[0] == 'N') {
            int u; scanf("%d", &u);
            --u;
            pos[u] = 0;
            g[i].push_back(u);
        } else {
            scanf("%d", &v[i]);
            leaf[i] = true;
        }
        if (s[0] == 'A') op[i] = 0;
        if (s[0] == 'O') op[i] = 1;
        if (s[0] == 'X') op[i] = 2;
        if (s[0] == 'N') op[i] = 3;
    }
    int x = dfs(0); dfs2(0);
    for (int i = 0; i < n; ++i) {
        if (leaf[i]) printf("%d", x ^ ans[i]);
    }
    puts("");
    return 0;
}
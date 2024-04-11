/*
Author: elfness@UESTC
*/
#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;
typedef long long LL;

const int V = 2010;
vector<int> son[V];
int n, root, x, c[V], a[V], s[V];

bool ok;

void dfs1(int u) {
    s[u] = 1;
    for (int i = 0; i < son[u].size(); ++i) {
        int v = son[u][i];
        dfs1(v);
        s[u] += s[v];
    }
}

void dfs(int u, vector<int> b) {
    //printf("%d %d %d   ", u, c[u], s[u]); for (int i = 0; i < b.size(); ++i) printf("%d ", b[i]);puts("");
    if (c[u] >= b.size()) {
        ok = false;
        return;
    }
    a[u] = b[c[u]];
    int p = 0;
    for (int i = 0; i < son[u].size(); ++i) {
        int v = son[u][i];
        vector<int> bv;
        for (int j = 0; j < s[v]; ++j) {
            if (p == c[u]) ++p;
            bv.push_back(b[p++]);
        }
        dfs(v, bv);
    }
}

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; ++i) son[i].clear();
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &x, &c[i]);
            if (x == 0) root = i;
            else son[x].push_back(i);
        }
        vector<int> all;
        for (int i = 1; i <= n; ++i) all.push_back(i);
        ok = true;
        dfs1(root);
        dfs(root, all);
        if (!ok) puts("NO");
        else {
            puts("YES");
            for (int i = 1; i <= n; ++i) printf("%d ", a[i]); puts("");
        }
    }
    return 0;
}

/*
3
2 0
0 2
2 0

5
0 1
1 3
2 1
3 0
2 0

*/
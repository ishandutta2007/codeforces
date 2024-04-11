#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> g[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    bool ans = true;
    
    for (int i = 0; i < n; ++i) {
        if ((int)g[i].size() != 1) 
            ans &= (int)g[i].size() > 2;
    }

    if (ans) puts("YES");
    else puts("NO");
}
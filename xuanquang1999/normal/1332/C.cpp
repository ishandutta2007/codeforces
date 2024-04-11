#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

int n, k;
char s[MAXN];
vector<int> graph[MAXN], vtx;
bool visited[MAXN];

void addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void dfs(int u) {
    vtx.push_back(u);
    visited[u] = true;

    for(int v: graph[u]) 
        if (!visited[v])
            dfs(v);    
}

int main() {
    int nTest;
    scanf("%d", &nTest);

    while (nTest--) {
        scanf("%d%d", &n, &k);
        scanf("%s", s);

        for(int u = 1; u <= n; ++u) {
            graph[u].clear();
            visited[u] = false;
        }

        for(int u = 1; u <= n; ++u)
            addEdge(u, n + 1 - u);
        for(int u = k+1; u <= n; ++u)
            addEdge(u - k, u);

        int ans = 0;
        for(int u = 1; u <= n; ++u) {
            if (!visited[u]) {
                vtx.clear();
                dfs(u);

                vector<int> cnt(26, 0);
                for(int v: vtx) 
                    ++cnt[s[v-1] - 'a'];
                
                int maxCnt = *max_element(cnt.begin(), cnt.end());
                ans += vtx.size() - maxCnt;
            }
        }
        
        printf("%d\n", ans);
    }

    return 0;
}
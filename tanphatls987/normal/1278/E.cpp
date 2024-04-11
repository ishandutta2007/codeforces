#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
vector<int> adj[N];
int ans[N][2];
int sub[N];
int n, n1;

int DFS(int u, int par, int L) {
    int res = 1;

    vector<int> son;
    for(auto v : adj[u]) if (v != par) 
        son.push_back(v);
    ans[u][1] = L + son.size();

    int pos = ans[u][1];
    int nL = pos + 1; 
    for(auto v : son) {
        ans[v][0] = --pos;
        int sub = DFS(v, u, nL);

        res += sub;
        nL += 2 * sub - 1;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ans[1][0] = 1;
    DFS(1, 0, 2);
    for(int i = 1; i <= n; i++) {
        cout << ans[i][0] << " " << ans[i][1] << '\n';
    }
}
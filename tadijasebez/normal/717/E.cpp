#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int n;
bool color[200005];
vector<int> g[200005];
bool visited[200005];

void dfs(int node, int par)
{
    visited[node] = true;
    cout << node << " ";
    if(node != 1){color[node] ^= 1;}

    for(auto c : g[node]){
        if(!visited[c]){
            dfs(c, node);
            cout << node << " ";
            color[node] ^= 1;
        }
    }

    if(!color[node]){
        if(node == 1){
            cout << g[1][0] << " " << node << " " << g[1][0] << " ";
        }
        else{
            cout << par << " " << node << " ";
            color[par] ^= 1; color[node] ^= 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 1; i <= n; ++i){
        int c;
        cin >> c;

        if(c == 1){color[i] = 1;}
        else{color[i] = 0;}
    }

    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;

        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(1, -1);

    return 0;
}
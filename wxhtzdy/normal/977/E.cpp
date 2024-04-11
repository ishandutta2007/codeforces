#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200005;

vector<int> g[MAXN];

bool dobro = true, was[MAXN] = {false};

void dfs(int v) {
    if(g[v].size() != 2) {
            dobro = false;
    }
    was[v] = true;
    for(int i = 0; i < g[v].size(); i++) {
        if(was[g[v][i]] == false) {
            dfs(g[v][i]);
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    while(m--) {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(was[i] == false) {
            dobro = true;
            dfs(i);
            if(dobro == true) {
                    ans++;
            }
        }
    }
    cout << ans;
}
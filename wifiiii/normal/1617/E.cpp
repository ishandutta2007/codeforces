#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5 * 30;
vector<int> g[N];
int dep[N], id[N];

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    unordered_map<int, int> mp; int tot = 0;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(!mp.count(x)) {
            mp[x] = ++tot;
            id[tot] = i + 1;
        }
        if(x == 0) id[mp[x]] = i + 1;
        while(x) {
            int p = x == 1 ? 0 : 32 - __builtin_clz(x - 1), f = 0;
            int u = mp[x], y = x;
            x = (1 << p) - x;
            if(!mp.count(x)) {
                mp[x] = ++tot;
            }
            int v = mp[x];
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }
    for(int i = 1; i <= tot; ++i) {
        sort(g[i].begin(), g[i].end());
        g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
    }
    function<void(int,int)> dfs = [&](int u, int fa) {
        for(int v : g[u]) {
            if(v == fa) continue;
            dep[v] = dep[u] + 1;
            dfs(v, u);
        }
    };
    dfs(1, -1);
    int u = max_element(dep + 1, dep + 1 + tot) - dep;
    dep[u] = 0;
    dfs(u, -1);
    int v = max_element(dep + 1, dep + 1 + tot) - dep;
    cout << id[u] << " " << id[v] << " " << dep[v] << '\n';
}
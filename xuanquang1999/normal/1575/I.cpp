// Not my solution. Testing.

#include<bits/stdc++.h>

using namespace std;

vector<int> pwr(20, 0);

void dfs(vector<vector<int>> &adj, int p, int c, vector<int> &lca, vector<int> &dpth){
    lca.push_back(c);
    for (auto u: adj[c]) if (u != p) {
        dpth[u] = dpth[c] + 1;
        dfs(adj, c, u, lca, dpth);
        lca.push_back(c);
    }
}

long long func(long long a, long long b){
    return a + b;
}

long long sum(int a, int b, int n, vector<long long> &tree){
    a += n; b += n;
    long long s = 0;
    while (a <= b){
        if (a%2 == 1) s = func(s, tree[a++]);
        if (b%2 == 0) s = func(s, tree[b--]);
        a /= 2; b /= 2;
    }
    return s;
}

void add(int k, long long x, int n, vector<long long> &tree){
    k += n;
    tree[k] += x;
    for (k /= 2; k >= 1; k /= 2){
        tree[k] = func(tree[2*k], tree[2*k+1]);
    }
}

void create_par(vector<vector<int>> &adj, int p, int c, vector<vector<int>> &par){
    for (auto ele: adj[c]){
        if (ele == p){
            continue;
        }
        par[ele][0] = c;
        for (int i = 1; i < 20; i++){
            par[ele][i] = par[par[ele][i - 1]][i - 1];
        }
        create_par(adj, c, ele, par);
    }
}

int llca(int u, int v, vector<vector<int>> &par, vector<int> &dpth){
    int j = 19;
    if (dpth[u] > dpth[v]){
        swap(u, v);
    }
    int dif = dpth[v] - dpth[u];
    for (int i = 0; i < 20; i++){
        if (pwr[i]&dif){
            v = par[v][i];
        }
    }
    while (u != v){
        if (par[u][0] == par[v][0]){
            u = v = par[u][0];
            continue;
        }
        while (par[u][j] == par[v][j]){
            j--;
        }
        u = par[u][j], v = par[v][j];
    }
    return u;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    for (int i = 0; i < 20; i++){
        pwr[i] = (1<<i);
    }
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj;
    for (int i = 0; i < n; i++){
        adj.push_back({});
    }

    vector<long long> a(n, 0);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        if (a[i] < 0){
            a[i] *= -1;
        }
    }

    for (int i = 0; i < n - 1; i++){
        int s, t;
        cin >> s >> t;
        s--;
        t--;
        adj[s].push_back(t);
        adj[t].push_back(s);
    }

    vector<int> lca;
    vector<vector<int>> par;
    vector<int> dpth(n, 0);
    for (int i = 0; i < n; i++){
        par.push_back({});
        for (int j = 0; j < 20; j++){
            par[i].push_back(0);
        }
    }
    dfs(adj, -1, 0, lca, dpth);
    create_par(adj, -1, 0, par);
    int l = (int)lca.size();
    vector<int> mnpos(n, 1e9), mxpos(n, -1);
    vector<long long> tree(2*l + 1, 0);
    for (int j = 0; j < l; j++){
        mnpos[lca[j]] = min(mnpos[lca[j]], j);
        mxpos[lca[j]] = max(mxpos[lca[j]], j);
    }
    for (int i = 0; i < n; i++){
        add(mnpos[i], a[i], l, tree);
        add(mxpos[i], -a[i], l, tree);
    }

    auto change = [&](int u, long long c)->void{
        if (c < 0){
            c *= -1;
        }
        long long prev = a[u];
        a[u] = c;
        add(mnpos[u], a[u] - prev, l, tree);
        add(mxpos[u], -a[u] + prev, l, tree);
    };

    for (int i = 0; i < q; i++){
        int t;
        cin >> t;
        if (t == 1){
            int u;
            long long c;
            cin >> u >> c;
            u--;
            change(u, c);
        }
        else{
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            if (u == v){
                cout << 0 << '\n';
            }
            else{
                int x = llca(u, v, par, dpth);
                long long ans = -2*sum(0, mnpos[x], l, tree) + sum(0, mnpos[u], l, tree) + sum(0, mnpos[v], l, tree) + a[x];
                if (mnpos[v] == mxpos[v]){
                    ans += a[v];
                }
                if (mnpos[u] == mxpos[u]){
                    ans += a[u];
                }
                ans *= 2;
                ans -= a[u];
                ans -= a[v];
                cout << ans << '\n';
            }
        }
    }
    return 0;
}
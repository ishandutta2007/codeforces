#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 4e5 + 1;

int n, m, c[N];
int st[N], en[N];
int po[N], cnt = 0;

vector <int> g[N];

void dfs(int u, int p){
    st[u] = ++cnt;
    po[cnt] = c[u];
    for (int v : g[u]){
        if (v != p){
            dfs(v, u);
        }
    }
    en[u] = cnt;
}

int it[N << 2];
int lz[N << 2];

void init(int i, int l, int r){
    if (l == r){
        it[i] = (1ll << po[l]);
        return;
    }
    int m = (l + r) / 2;
    init(i << 1, l, m);
    init(i << 1 | 1, m + 1, r);
    it[i] = it[i << 1] | it[i << 1 | 1];
}

void true_val(int i, int l, int r){
    if (!lz[i]){
        return;
    }
    it[i] = (1ll << lz[i]);
    if (l != r){
        lz[i << 1] = lz[i];
        lz[i << 1 | 1] = lz[i];
    }
    lz[i] = 0;
}

void upd(int i, int l, int r, int a,int b,int val){
    true_val(i, l, r);
    if (l > b || r < a){
        return;
    }
    if (a <= l && r <= b){
        lz[i] = val;
        true_val(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(i << 1, l, m, a, b, val);
    upd(i << 1 | 1, m + 1, r, a, b, val);
    it[i] = it[i << 1] | it[i << 1 | 1];
}

int get(int i, int l, int r, int a, int b){
    true_val(i, l, r);
    if (l > b || r < a){
        return 0;
    }
    if (a <= l && r <= b){
        return it[i];
    }
    int m = (l + r) / 2;
    return get(i << 1, l, m, a, b) | get(i << 1 | 1, m + 1, r, a, b);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> c[i];
    }
    int t, u, v, x, y;
    for (int i = 1; i < n; i++){
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 1);
    init(1, 1, n);
    while (m--){
        cin >> t >> u;
        if (t == 1){
            cin >> v;
            upd(1, 1, n, st[u], en[u], v);
        }
        else{
            cout << __builtin_popcountll(get(1, 1, n, st[u], en[u])) << "\n";
        }
    }
}
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fi first
#define se second
typedef pair<int, int> ii;

const int N = 1e5 + 5, inf = 1e18;
int n, m, q, pter[N], be[N], en[N], ver[N], cur, sz[N], hchain[N], nchain = 1, inchain[N], par[N];
vector <int> gr[N], s[N];

struct dtit{
    ii node[N << 2];
    int lz[N << 2], pl[N << 2];
    void build_tree(int nd, int left, int right){
        if (left > right){
            return;
        }
        if (left == right){
            node[nd] = ii(s[ver[left]][0], ver[left]);
            return ;
        }
        int mid = left + right >> 1;
        build_tree(nd << 1, left, mid); build_tree(nd << 1 | 1, mid + 1, right);
        node[nd] = min(node[nd << 1], node[nd << 1 | 1]);
    }
    void true_val(int nd, int left, int right){
        if (left > right || !lz[nd]){
            return;
        }
        node[nd].fi += lz[nd];
        pl[nd] += lz[nd];
        if (left != right){
            lz[nd << 1] += lz[nd];
            lz[nd << 1 | 1] += lz[nd];
        }
        lz[nd] = 0;
    }
    void update(int nd, int left, int right, int l, int r, int val, bool type){
        true_val(nd, left, right);
        if (left > right || right < l || r < left){
            return;
        }
        if (l <= left && right <= r){
            if (type){
                pter[node[nd].se] ++;
                node[nd] = ii(s[node[nd].se][pter[node[nd].se]] + pl[nd], node[nd].se);
            }
            else{
                lz[nd] = val;
                true_val(nd, left, right);
            }
            return;
        }
        int mid = left + right >> 1;
        update(nd << 1, left, mid, l, r, val, type); update(nd << 1 | 1, mid + 1, right, l, r, val, type);
        node[nd] = min(node[nd << 1], node[nd << 1 | 1]);
    }
    ii get(int nd, int left, int right, int l, int r){
        true_val(nd, left, right);
        if (left > right || right < l || r < left){
            return ii(inf, 0);
        }
        if (l <= left && right <= r){
            return node[nd];
        }
        int mid = left + right >> 1;
        return min( get(nd << 1, left, mid, l, r), get(nd << 1 | 1, mid + 1, right, l, r) );
    }
} it;

void dfs(int u, int p){
    par[u] = p;
    sz[u] = 1;
    for (int v : gr[u]){
        if (v != p){
            dfs(v, u); sz[u] += sz[v];
        }
    }
}

void hld(int u, int p){
    if (!hchain[nchain]){
        hchain[nchain] = u;
    }
    inchain[u] = nchain;
    be[u] = ++cur;
    ver[cur] = u;
    int bigChild = 0;
    for (int v : gr[u]){
        if (v != p){
            if (sz[v] > sz[bigChild]){
                bigChild = v;
            }
        }
    }
    if (bigChild){
        hld(bigChild, u);
    }
    for (int v : gr[u]){
        if (v != p && v != bigChild){
            nchain++;
            hld(v, u);
        }
    }
    en[u] = cur;
}

ii gethld(int u, int v){
    ii ret = ii(inf, 0);
    while (inchain[u] != inchain[v]){
        if (inchain[u] < inchain[v]){
            swap(u, v);
        }
        int pa = hchain[inchain[u]];
        ret = min(ret, it.get(1, 1, n, be[pa], be[u]));
        u = par[pa];
    }
    if (be[u] > be[v]){
        swap(u, v);
    }
    ret = min(ret, it.get(1, 1, n, be[u], be[v]));
    return ret;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        gr[u].pb(v); gr[v].pb(u);
    }
    for (int i = 1; i <= m; i++){
        int c;
        cin >> c;
        s[c].pb(i);
    }
    for (int i = 1; i <= n; i++){
        s[i].pb(inf);
    }
    dfs(1, 1);
    hld(1, 1);
    it.build_tree(1, 1, n);
    while (q--){
        int type, u;
        cin >> type >> u;
        if (type == 2){
            int K;
            cin >> K;
            it.update(1, 1, n, be[u], en[u], K, 0);
        }
        else{
            int v, K;
            cin >> v >> K;
            vector <int> ans;;
            while (K--){
                ii res = gethld(u, v);
                if (res.fi == inf){
                    break;
                }
                ans.pb(s[res.se][pter[res.se]]);
                it.update(1, 1, n, be[res.se], be[res.se], 0, 1);
            }
            cout << ans.size() << ' ';
            for (int i : ans){
                cout << i << ' ';
            }
            cout << '\n';
        }
    }
}
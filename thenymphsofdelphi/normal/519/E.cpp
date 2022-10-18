#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, r, l) for (int i = r; i >= l; i--)
#define Fora(i, a) for (auto i: a)
#define bend(a) a.begin(), a.end()
#define isz(a) (int)a.size()

typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef vector <vi > vvi;
typedef vector <pii > vpii;

struct binary_lifting{
    vi height;
    vvi lift;
    
    void dfs_binlift(int u, int p, vi adj[]){
        lift[u][0] = p;
        for (int j = 1; j < lift[0].size(); j++){
            lift[u][j] = lift[lift[u][j - 1]][j - 1];
        }
        Fora(v, adj[u]){
            if (v == p){
                continue;
            }
            height[v] = height[u] + 1;
            dfs_binlift(v, u, adj);
        }
    }
    
    binary_lifting(int n, vi adj[]){
        height = vi (n + 1, 0);
        lift = vvi (n + 1, vi ((int)log2(n) + 1, 0));
        dfs_binlift(1, 1, adj);
    }
    
    int lca(int u, int v){
        if (height[u] < height[v]){
            swap(u, v);
        }
        for (int j = lift[0].size() - 1; j >= 0; j--){
            if (height[u] - (1 << j) >= height[v]){
                u = lift[u][j];
            }
        }
        if (u == v){
            return u;
        }
        for (int j = lift[0].size() - 1; j >= 0; j--){
            if (lift[u][j] != lift[v][j]){
                u = lift[u][j];
                v = lift[v][j];
            }
        }
        return lift[u][0];
    }
    
    int nearlca(int u, int v){
        if (height[u] <= height[v]){
            return -1;
        }
        assert(height[u] > height[v]);
        for (int j = lift[0].size(); j >= 0; j--){
            if (height[u] - (1 << j) > height[v]){
                u = lift[u][j];
            }
        }
        if (lift[u][0] != v){
            return -1;
        }
        return u;
    }
};

const int N = 1e5 + 5;

int n;
vi adj[N];

int subtreesize[N];

void dfs(int u, int p){
    subtreesize[u] = 1;
    Fora(v, adj[u]){
        if (v == p){
            continue;
        }
        dfs(v, u);
        subtreesize[u] += subtreesize[v];
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n - 1){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    binary_lifting cac(n, adj);
    dfs(1, 1);
    int q; cin >> q; while (q--){
        int u, v; cin >> u >> v;
        if (u == v){
            cout << n << endl;
            continue;
        }
        if (cac.height[u] < cac.height[v]){
            swap(u, v);
        }
        int w = cac.lca(u, v), dist = cac.height[u] + cac.height[v] - 2 * cac.height[w];
        if (dist % 2 == 1){
            cout << 0 << endl;
            continue;
        }
        dist /= 2;
        int mid = u;
        for (int j = cac.lift[0].size() - 1; j >= 0; j--){
            if (dist & (1 << j)){
                mid = cac.lift[mid][j];
            }
        }
        int ans;
        if (mid != w){
            ans = subtreesize[mid];
            ans -= subtreesize[cac.nearlca(u, mid)];
        }
        else{
            ans = n;
            ans -= subtreesize[cac.nearlca(u, mid)];
            ans -= subtreesize[cac.nearlca(v, mid)];
        }
        cout << ans << endl;
    }
}
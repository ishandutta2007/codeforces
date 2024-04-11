//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)5e3 + 3;

int f[N];
int pr[N];
int road_id[N];
int target[N];
vector<int> path[N];
vector<pii> gr[N];
int tin[N], tout[N];
int h[N];
int gt = 0;

void dfs(int v, int p = -1, int in = -1){
    road_id[v] = in;
    tin[v] = gt++;
    pr[v] = p;
    h[v] = p == -1 ? 0 : (1 + h[p]);
    I(u, gr[v]){
        if(u.X != p)
            dfs(u.X, v, u.Y);
    }
    tout[v] = gt++;
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    F(i, 0, n - 1){
        int v, u;
        cin >> v >> u;
        --v; --u;
        gr[v].pb(mp(u, i));
        gr[u].pb(mp(v, i));
    }
    fill(f, f + n, 1);
    dfs(0);
    int m;
    cin >> m;
    F(i, 0, m){
        int v, u;
        cin >> v >> u;
        --v; --u;
        if(h[v] > h[u])swap(v, u);
        while(!(tin[v] <= tin[u] && tout[v] >= tout[u])){
            path[i].pb(v);
            v = pr[v];
        }
        path[i].pb(v);
        vector<int> rem;
        while(u != v){
            rem.pb(u);
            u = pr[u];
        }
        reverse(all(rem));
        I(x, rem)path[i].pb(x);
        int curr;
        cin >> curr;
        target[i] = curr;
        F(j, 0, (int)path[i].size() - 1){
            if(h[path[i][j + 1]] < h[path[i][j]])
                f[road_id[path[i][j]]] = max(f[road_id[path[i][j]]], curr);
            else
                f[road_id[path[i][j + 1]]] = max(f[road_id[path[i][j + 1]]], curr);
        }
    }
    F(i, 0, m){
        int val = (int)1e9 + 9;
        F(j, 0, (int)path[i].size() - 1){
            if(h[path[i][j + 1]] < h[path[i][j]])
                val = min(val, f[road_id[path[i][j]]]);
            else
                val = min(val, f[road_id[path[i][j + 1]]]);
        }
        if(val != target[i]){cout << -1; ret 0;}
    }
    F(i, 0, n - 1)cout << f[i] << ' ';
    return 0;
}
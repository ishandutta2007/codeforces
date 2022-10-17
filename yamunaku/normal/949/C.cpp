//
// Created by yamunaku on 2019/11/11.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<typename T>
using heap = priority_queue<T, vector<T>, function<bool(const T, const T)>>;

class UnionFind{
    vector<int> node;

    UnionFind(int n){
        node = vector<int>(n, -1);
    }

    int root(int x){
        if(node[x] < 0) return x;
        return node[x] = root(node[x]);
    }

    void uni(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(node[x] > node[y]) swap(x, y);
        node[x] += node[y];
        node[y] = x;
    }
};

class Scc{
public:
    int n;
    vector<vector<int>> e, re;

    Scc(int sz){
        n = sz;
        e = vector<vector<int>>(n);
        re = vector<vector<int>>(n);
    }

    void addEdge(int x, int y){
        e[x].push_back(y);
        re[y].push_back(x);
    }

    vector<int> visited;
    vector<int> id;

    void dfs1(int x, int &c){
        visited[x] = true;
        for(auto nx:e[x]){
            if(!visited[nx]) dfs1(nx, c);
        }
        id[c] = x;
        c++;
    }

    int dfs2(int x, int c, vector<int> &nv){
        visited[x] = true;
        nv[x] = c;
        for(auto nx:re[x]){
            if(!visited[nx]) dfs2(nx, c, nv);
        }
    }

    void build(vector<int> &nv, vector<vector<int>> &ne){
        visited = vi(n, false);
        id = vi(n, -1);
        int c = 0;
        rep(i, n){
            if(!visited[i]){
                dfs1(i, c);
            }
        }
        visited = vi(n, false);
        nv = vector<int>(n, -1);
        c = 0;
        per(i, n){
            if(!visited[id[i]]){
                dfs2(id[i], c, nv);
                c++;
            }
        }
        ne = vector<vector<int>>(c);
        rep(i, n){
            for(auto nx: e[i]){
                if(nv[i] != nv[nx]) ne[nv[i]].push_back(nv[nx]);
            }
        }
    }
};

int main(){
    // CFS;
    int n, m, h;
    cin >> n >> m >> h;
    vi a(n);
    rep(i, n) cin >> a[i];
    Scc scc(n);
    int u, v;
    rep(i, m){
        cin >> u >> v;
        u--, v--;
        if(a[u] == (a[v] + 1) % h){
            scc.addEdge(v, u);
        }
        if(a[v] == (a[u] + 1) % h){
            scc.addEdge(u, v);
        }
    }
    vi vc;
    mti e;
    scc.build(vc, e);
    int sz = e.size();
    vi k(sz, 0);
    rep(i,n) k[vc[i]]++;
    int ans = IINF;
    int id = -1;
    rep(i,sz){
        if(e[i].size()==0){
            if(ans>k[i]){
                ans=k[i];
                id=i;
            }
        }
    }
    cout << ans << endl;
    rep(i,n){
        if(vc[i]==id){
            cout << i+1 << " ";
        }
    }
    cout << endl;
    return 0;
}
//
// Created by yamunaku on 2019/11/07.
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

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> mti;
typedef vector<ll> vl;
typedef vector<vector<ll>> mtl;

class UnionFind{
private:
    vi node;
public:
    UnionFind(int n){
        node = vi(n, -1);
    }

    int root(int x){
        if(node[x] < 0) return x;
        return node[x] = root(node[x]);
    }

    void uni(int x, int y){
        x = root(x), y = root(y);
        if(x == y) return;
        if(node[x] > node[y]) swap(x, y);
        node[x] += node[y];
        node[y] = x;
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    int u, v;
    mti e(n);
    vi sz(n,0);
    rep(i, m){
        cin >> u >> v;
        e[u - 1].push_back(v - 1);
        e[v - 1].push_back(u - 1);
        sz[u - 1]++;
        sz[v - 1]++;
    }
    UnionFind uf(n);
    vi id(n);
    iota(all(id), 0);
    sort(all(id), [&](int &l, int &r){
        return sz[l] < sz[r];
    });
    vi f(n,false);
    for(auto nx:e[id[0]]) f[nx]=true;
    vi ng;
    rep(i, n){
        if(i==id[0]) continue;
        if(f[i]){
            ng.push_back(i);
        }else{
            uf.uni(i, id[0]);
        }
    }
    for(auto vx:ng){
        f = vi(n,false);
        for(auto nx:e[vx]) f[nx]=true;
        rep(i, n){
            if(i==vx) continue;
            if(!f[i]){
                uf.uni(i, vx);
            }
        }
    }
    set<int> st;
    rep(i,n) st.insert(uf.root(i));
    cout << st.size()-1 << endl;
    return 0;
}
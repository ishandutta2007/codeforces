//
// Created by yamunaku on 2019/10/07.
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

struct edge{
    int to;
    int w;
};

int n, k;
vector<vector<edge>> e;

pair<ll, ll> dfs(int x, int p){
    ll total = 0;
    vl v;
    for(auto &nx:e[x]){
        if(nx.to != p){
            auto pa = dfs(nx.to, x);
            ll a = max(pa.first, pa.second);
            ll b = pa.first + nx.w;
            total += a;
            v.push_back(b - a);
        }
    }
    int sz=v.size();
    sort(all(v),greater<ll>());
    rep(i,min(sz, k-1)){
        total+=max(v[i],0ll);
    }
    ll tmp=total;
    if(k<=sz) total+=max(v[k-1],0ll);
    return {tmp, total};
}


int main(){
    CFS;
    int q;
    cin >> q;
    rep(_, q){
        cin >> n >> k;
        e = vector<vector<edge>>(n);
        int u, v, w;
        rep(i, n - 1){
            cin >> u >> v >> w;
            u--, v--;
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }
        auto pa = dfs(0, -1);
        cout << max(pa.first, pa.second) << endl;
    }
    return 0;
}
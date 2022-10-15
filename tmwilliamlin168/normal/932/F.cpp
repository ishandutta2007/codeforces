#include "bits/stdc++.h"


#define ll          long long
#define pb          push_back
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define endl        '\n'
#define rep(i,a,b)    for(int i=a;i<b;i++)
using namespace std;

bool Q;
struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const {
        return Q ? p < o.p : k < o.k;
    }
};
struct LineContainer : multiset<Line> {
    const ll inf = LLONG_MAX;
    ll div(ll a, ll b){
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = inf; return false; }
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        Q = 1; auto l = *lower_bound({0,0,x}); Q = 0;
        return l.k * x + l.m;
    }
};

vector<int> x,y;
vector<vi> adj;
vector<ll> ans;
vector<int> subsize;
void dfs1(int u,int v){
    subsize[u]=1;
    for(auto i:adj[u]){
        if(i==v)continue;
        dfs1(i,u);
        subsize[u]+=subsize[i];
    }
}

void dfs2(int v, int p,LineContainer& cur){
    int mx=-1,bigChild=-1;
    bool leaf=1;
    for(auto u:adj[v]){
        if(u!=p and subsize[u]>mx){
            mx=subsize[u];
            bigChild=u;
            leaf=0;
        }
    }
    if(bigChild!=-1){
        dfs2(bigChild,v,cur);
    }
    for(auto u:adj[v]){
        if(u!=p and u!=bigChild){
            LineContainer temp;
            dfs2(u,v,temp);
            for(auto i:temp){
                cur.add(i.k,i.m);
            }
        }
    }
    if(!leaf)ans[v]=-cur.query(x[v]);
    else ans[v]=0;
    cur.add(-y[v],-ans[v]);
}
void solve(){
    int n;
    cin>>n;
    x.resize(n+1);
    y.resize(n+1);
    ans.resize(n+1);
    subsize.resize(n+1);
    adj.resize(n+1);
    rep(i,1,n+1)cin>>x[i];
    rep(i,1,n+1)cin>>y[i];
    rep(i,1,n){
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(1,0);
    LineContainer lc;
    dfs2(1,0,lc);
    rep(i,1,n+1)cout<<ans[i]<<" ";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
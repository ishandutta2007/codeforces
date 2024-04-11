//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lfs cout<<fixed<<setprecision(10)
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = (n); i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = (ll)(m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>void debug(T &v,ll h,ll w,string sv=" "){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout<<sv<<v[i][j];cout<<endl;}};
template<typename T>void debug(T &v,ll n,string sv=" "){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout<<sv<<v[i];cout<<endl;};
template<typename T>vector<vector<T>>vec(ll x, ll y, T w){vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<typename T1, typename T2>ostream &operator<<(ostream &os, const pair<T1, T2>&p){return os << p.first << " " << p.second;}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v){for(auto &z:v)os << z << " ";cout<<"|"; return os;}
template<typename T>void rearrange(vector<int>&ord, vector<T>&v){
  auto tmp = v;
  for(int i=0;i<tmp.size();i++)v[i] = tmp[ord[i]];
}
template<typename Head, typename... Tail>void rearrange(vector<ll>&ord,Head&& head, Tail&&... tail){
  rearrange(ord, head);
  rearrange(ord, tail...);
}
template<typename T> vector<int> ascend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return v[i]<v[j];});
  return ord;
}
template<typename T> vector<int> descend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return v[i]>v[j];});
  return ord;
}
ll FLOOR(ll n,ll div){return n>=0?n/div:(n-div+1)/div;}
ll CEIL(ll n,ll div){return n>=0?(n+div-1)/div:n/div;}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};

template< typename T = int >
struct edge {
  int to;
  T cost;
  int id;
  edge() = default;
  edge(int to, T cost = 1, int id = -1):to(to), cost(cost), id(id){}
  operator int() const { return to; }
};

template<typename T>
using Graph = vector<vector<edge<T>>>;
template<typename T>
Graph<T> readGraph(int n,int m,int indexed=1,bool directed=false,bool weighted=false){
  Graph<T> ret(n);
  for(int es = 0; es < m; es++){
    int u,v,w=1;
    cin>>u>>v;u-=indexed,v-=indexed;
    if(weighted)cin>>w;
    ret[u].emplace_back(v,w,es);
    if(!directed)ret[v].emplace_back(u,w,es);
  }
  return ret;
}
template<typename T>
Graph<T> readParent(int n,int indexed=1,bool directed=true){
  Graph<T>ret(n);
  for(int i=1;i<n;i++){
    int p;cin>>p;
    p-=indexed;
    ret[p].emplace_back(i);
    if(!directed)ret[i].emplace_back(p);
  }
  return ret;
}
template<typename T>
struct HLD{
  using D=long long;
  int n;
  vector<int>sz;//
  vector<D>dep;
  vector<int>par;
  vector<int>head;
  Graph<T> &g;//
  vector<edge<T>>edges;//edge
  vector<int>in,out;//[in,out)[ina,inb]a~b(a)
  vector<int>comp;//
  //inindexedge
  HLD(Graph<T> &g,int r=-1):g(g),n(g.size()){
    hld_build(r);
  }
  void hld_build(int root = -1){
    in.assign(n,-1);out.assign(n,-1);dep.assign(n,0);
    par.assign(n,-1);head.assign(n,-1);sz.assign(n,-1);comp.assign(n,-1);
    edges.assign(n,edge<T>());
    if(root == -1){//()
      for(int i=0;i<n;i++){
        if(sz[i] == -1){
          head[i] = i;
          dfs_sz(i, 0, i);
          dfs_hld(i);
        }
      }
    }
    else{
      head[root] = root;
      dfs_sz(root, 0, root);
      dfs_hld(root);
    }
  }
  void dfs_sz(int k, D d,int r){
    sz[k] = 1;
    comp[k] = r;
	dep[k] = d;
    for(auto &e: g[k]){
      if(e.to == par[k])continue;
      par[e.to] = k;
      dfs_sz(e.to, d+e.cost, r);
      sz[k] += sz[e.to];
      if(sz[e.to] > sz[g[k][0].to])swap(e, g[k][0]);
    }
  }
  int time = 0;
  void dfs_hld(int k){
    in[k] = time++;
    for(auto e:g[k]){
      if(e.to == par[k])continue;
      head[e.to] = (e.to == g[k][0].to ? head[k]: e.to);
      edges[time] = e;
      dfs_hld(e.to);
    }
    out[k] = time;
  }
  int lca(int p,int q){
    while(1){
      if(in[p] < in[q])swap(p,q);
      if(head[p] == head[q])return q;
      p = par[head[p]];
    }
  }
  vector<pair<int,int>>query_path(int p,int q,bool isEdge){
    int r=lca(p,q);
    vector<pair<int,int>>ret;
    for(int i=0;i<2;i++){
      if(i == 1)swap(p,q);
      while(1){
        if(isEdge&&p==r)break;
        if(head[p]==head[r]){
          ret.emplace_back(in[r]+(isEdge?1:i),in[p]+1);
          break;
        }
        ret.emplace_back(in[head[p]],in[p]+1);
        p = par[head[p]];
      }
    }
    return ret;
  }
  vector<vector<pair<int,int>>>query_order_path(int p,int q,bool isEdge){
	//01
    vector<vector<pair<int,int>>>ret(2);
    int r=lca(p,q);
    for(int i=0;i<2;i++){
      if(i == 1)swap(p,q);
      while(1){
        if(isEdge&&p==r)break;
        if(head[p]==head[r]){
          if(i==0) ret[i].emplace_back(n-(in[p]+1),n-(in[r]+(isEdge?1:i)));
          else ret[i].emplace_back(in[r]+(isEdge?1:i),in[p]+1);
          break;
        }
        if(i==0) ret[i].emplace_back(n-(in[p]+1),n-(in[head[p]]));
        else ret[i].emplace_back(in[head[p]],in[p]+1);
        p = par[head[p]];
      }
    }
    reverse(ret[1].begin(), ret[1].end());
    return ret;
  }
  pair<int,int>query_subtree(int p,bool isEdge){
    return make_pair(in[p]+isEdge,out[p]);
  }
  //uv (in,out)
  int child(int u,int v){
    while(1){
      if(head[u]==head[v]){
        v=g[u][0].to;
        break;
      }
      v=head[v];
      if(par[v]==u)break;
      v=par[v];
    }
    return v;
  }
  //uv
  int move(int u,int v){
    assert(u!=v);
    if(in[u]<in[v]&&in[v]<out[v])return child(u,v);
    else return par[u];
  }
  D dist(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  int n;cin>>n;
  auto g=readGraph<int>(n,n-1);
  int m;cin>>m;
  vector<int>u(m),v(m);
  rep(i,0,m){
    cin>>u[i]>>v[i];u[i]--;v[i]--;
  }
  vector<ll>szv(n);//
  vector<ll>sze(n);//
  vector<ll>szp(n);
  HLD hld(g,0);
  using pi=pair<int,int>;
  vector<map<pi,ll>>mp(n);
  rep(i,0,m){
    ll lca=hld.lca(u[i],v[i]);
    szv[u[i]]++;
    szv[v[i]]++;
    szv[lca]--;
    if(lca!=0)szv[hld.par[lca]]--;
    sze[u[i]]++;
    sze[v[i]]++;
    sze[lca]-=2;

    if(lca!=u[i]&&lca!=v[i]){
      ll d1=hld.child(lca,u[i]);
      ll d2=hld.child(lca,v[i]);
      mp[lca][minmax(d1,d2)]++;
      szp[u[i]]++;
      szp[v[i]]++;
      szp[d1]--;
      szp[d2]--; 
    }
    else if(lca!=u[i])szp[u[i]]++,szp[hld.child(lca,u[i])]--;
    else if(lca!=v[i])szp[v[i]]++,szp[hld.child(lca,v[i])]--;
  }
  {
    auto dfs=[&](auto &&f,ll k,ll par)->void{
      for(auto to:g[k]){
        if(to==par)continue;
        f(f,to,k);
        szv[k]+=szv[to];
        sze[k]+=sze[to];
        szp[k]+=szp[to];
      }
    };
    dfs(dfs,0,-1);
  }
  rep(i,0,n){
    //cout<<i spa szv[i] spa sze[i] spa szp[i] spa res<<endl;
    res+=szv[i]*(szv[i]-1)/2;
    res-=sze[i]*(sze[i]-1);
    res+=szp[i]*(szp[i]-1)/2;
    for(auto z:mp[i]){
      //cout<<z<<endl;
      res+=z.se*(z.se-1)/2;
    }
  }
  cout<<res<<endl;
  return 0;
}
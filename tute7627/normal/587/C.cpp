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
template<typename T>void debug(vector<vector<T>>&v,ll h,ll w){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>&v,ll h,ll w){for(ll i=0;i<h;i++){for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>void debug(vector<T>&v,ll n){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>vector<vector<T>>vec(ll x, ll y, T w){vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<typename T1, typename T2>ostream &operator<<(ostream &os, const pair<T1, T2>&p){return os << p.first << " " << p.second;}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v){for(auto &z:v)os << z << " ";cout<<"|"; return os;}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
struct edge{
  ll to=-1;
  edge(){};
  edge(ll t):to(t){};
};
struct HLD{
  ll n, root;
  ll cnt = 0;
  vector<ll>sz;//
  vector<ll>par,head;
  vector<vector<struct edge>>g;//
  vector<struct edge>edges;//edge
  vector<ll>in,out;//[in,out)[ina,inb]a~b(a)
  //inindexedge
  HLD(vector<vector<struct edge>>&G,ll r = -1)
      :g(G),n(G.size()),root(r){
    par.assign(n,-1),in.assign(n,-1);
    out.assign(n,-1),head.assign(n,-1),sz.assign(n,-1);
    edges.assign(n,edge());
    dfs_build();
  }
  void dfs_build(){
    if(root == -1){//()
      for(ll i=0;i<n;i++){
        if(sz[i] == -1){
          head[i] = i;
          dfs_sz(i);
          dfs_hld(i);
        }
      }
    }
    else{
      head[root] = root;
      dfs_sz(root);
      dfs_hld(root);
    }
  }
  void dfs_sz(ll k){
    sz[k] = 1;
    for(auto &e: g[k]){
      if(e.to == par[k])continue;
      par[e.to] = k;
      dfs_sz(e.to);
      sz[k] += sz[e.to];
      if(sz[e.to] > sz[g[k][0].to])swap(e, g[k][0]);
    }
  }
  void dfs_hld(ll k){
    in[k] = cnt++;
    for(auto e:g[k]){
      if(e.to == par[k])continue;
      head[e.to] = (e.to == g[k][0].to ? head[k]: e.to);
      edges[cnt] = e;
      dfs_hld(e.to);
    }
    out[k] = cnt;
  }
  ll lca(ll p,ll q){
    while(1){
      if(in[p] < in[q])swap(p,q);
      if(head[p] == head[q])return q;
      p = par[head[p]];
    }
  }
  vector<pair<ll,ll>>query_path(ll p,ll q,bool isEdge=true){
    ll r=lca(p,q);
    vector<pair<ll,ll>>ret;
    for(ll i=0;i<2;i++){
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
  vector<vector<pair<ll,ll>>>query_order_path(ll p,ll q,bool isEdge=true){
	//01
    vector<vector<pair<ll,ll>>>ret(2);
    ll r=lca(p,q);
    for(ll i=0;i<2;i++){
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
  pair<ll,ll>query_subtree(ll p,bool isEdge=true){
    return make_pair(in[p]+isEdge,out[p]);
  }
};
template<typename T, typename F>
struct DisjointSparseTable{
  int n;
  vector<vector<T>>data;
  const F func;
  DisjointSparseTable(vector<T>&v, const F &f):func(f),n(v.size()){
    int num=0;
    while((1<<num)<v.size())num++;
    data.assign(num+5,vector<T>(n+1, T()));
    if(n>=1)data[0][n-1]=v[n-1];
    for(int i=1;i<n;i++){
      int k = __builtin_ctz(i);
      data[k][i-1]=v[i-1];
      if(i!=n)data[k][i]=v[i];
      int l=i-(1<<k),r=min(n,i+(1<<k));
      for(int j=i-2;j>=l;j--)data[k][j]=func(v[j],data[k][j+1]);
      for(int j=i+1;j<r;j++)data[k][j]=func(data[k][j-1],v[j]);
    }
  }
  T query(int l,int r){//[l,r);
    r--;
    if(l==r)return data[0][l];
    ll k=31-__builtin_clz(l^r);
    return func(data[k][l],data[k][r]);
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  using V=vector<int>;
  auto f=[&](V x,V y){
    V ret;
    int l=0,r=0;
    while(l<x.size()||r<y.size()){
      if(r==y.size()||(l!=x.size()&&x[l]<y[r]))ret.PB(x[l++]);
      else ret.PB(y[r++]);
      if(ret.size()>=10)break;
    }
    return ret;
  };
  ll n,m,q;cin>>n>>m>>q;
  vector<vector<edge>>g(n);
  rep(i,0,n-1){
    ll u,v;cin>>u>>v;u--;v--;
    g[u].EB(v);
    g[v].EB(u);
  }
  HLD hld(g);
  vector<V>b(n);
  rep(i,0,m){
    ll c;cin>>c;c--;
    V p(1,i+1);
    b[hld.in[c]]=f(b[hld.in[c]],p);
  }
  //rep(i,0,n)debug(b[i],b[i].size());
  DisjointSparseTable<V,decltype(f)>dst(b,f);
  while(q--){
    ll u,v,a;cin>>u>>v>>a;u--;v--;
    V ret;
    auto p=hld.query_path(u,v,false);
    //cout<<"query"<<endl;
    for(auto z:p){
      if(z.fi==z.se)continue;
      //cout<<z.fi spa z.se spa "path"<<endl;
      auto v=dst.query(z.fi,z.se);
      //debug(v,v.size());
      //debug(ret,ret.size());
      ret=f(ret,dst.query(z.fi,z.se));
    }
    ll sz=min(a,(ll)ret.size());
    cout<<sz<<" ";
    debug(ret,sz);
  }
  return 0;
}
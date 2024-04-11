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
using ll = int;
using ld = long double;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e9;
using P = pair<ll, ll>;
template<typename T>
bool chmin(T &a,T b){if(a>b){a=b;return true;}else return false;}
template<typename T>
bool chmax(T &a,T b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>
void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>
void debug(vector<vector<T>>&v,ll h,ll w){for(ll i=0;i<h;i++)
{cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>&v,ll h,ll w){for(ll i=0;i<h;i++)
{for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>
void debug(vector<T>&v,ll n){if(n!=0)cout<<v[0];
for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>
vector<vector<T>>vec(ll x, ll y, T w){
  vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,0,-1,0,1,1,-1,-1};
vector<ll>dy={0,1,0,-1,1,-1,1,-1};
template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2>&p){
  return os << p.first << " " << p.second;
}  
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
  vector<ll>dep;//[in,out)[ina,inb]a~b(a)
  //inindexedge
  HLD(vector<vector<struct edge>>&G,ll r = -1)
      :g(G),n(G.size()),root(r){
    par.assign(n,-1);
    head.assign(n,-1),sz.assign(n,-1);
    dep.assign(n,-1);
    edges.assign(n,edge());
    dfs_build();
  }
  void dfs_build(){
      head[root] = root;
      dfs_sz(root,0);
      dfs_hld(root);
  }
  void dfs_sz(ll k,ll d){
    dep[k]=d;
    sz[k] = 1;
    for(auto &e: g[k]){
      if(e.to == par[k])continue;
      par[e.to] = k;
      dfs_sz(e.to,d+1);
      sz[k] += sz[e.to];
      if(sz[e.to] > sz[g[k][0].to])swap(e, g[k][0]);
    }
  }
  void dfs_hld(ll k){
    for(auto e:g[k]){
      if(e.to == par[k])continue;
      head[e.to] = (e.to == g[k][0].to ? head[k]: e.to);
      edges[cnt] = e;
      dfs_hld(e.to);
    }
  }
  ll lca(ll p,ll q){
    while(1){
      if(dep[head[p]] < dep[head[q]])swap(p,q);
      if(head[p] == head[q])break;
      p = par[head[p]];
    }
    if(dep[p] > dep[q])swap(p,q);
    return p;
  }
};


void dfs_tree(ll k,vector<vector<edge>>&g,ll par,vector<ll>&ret){
  ret.PB(k);
  for(auto e:g[k]){
    if(e.to!=par)dfs_tree(e.to,g,k,ret);
  }
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,k;cin>>n>>k;
  vector<vector<edge>>g(n);
  rep(i,0,n-1){
    ll a,b;cin>>a>>b;a--;b--;
    g[a].EB(b);
    g[b].EB(a);
  }
  HLD lca(g,n-1);
  vector<ll>dfst;
  dfs_tree(n-1,g,-1,dfst);
  vector<ll>idx(n);
  rep(i,0,n)idx[dfst[i]]=i;
  set<ll>st;
  st.insert(0);
  ll rem=n-1-k;
  vector<bool>t(n);
  t[n-1]=true;
  //debug(dfst,n);
  //debug(idx,n);
  rrep(i,0,n-1){
    ll pos=lca.lca(dfst[*(--st.upper_bound(idx[i]))],i);
    if(lca.dep[i]-lca.dep[pos]<=rem){
      ll now=i;
      while(!t[now]){
        st.insert(idx[now]);
        rem--;
        t[now]=true;
        now=lca.par[now];
      }
    }
    //cout<<rem spa pos spa i<<endl;
    //for(auto z:st)cout<<idx[z]<<" ";cout<<endl;
  }
  //debug(t,n);
  vector<ll>ret;
  rep(i,0,n)if(!t[i])ret.PB(i+1);
  debug(ret,k);
  return 0;
}
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
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
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
vector<ll>dx={1,-1,0,0,1,1,-1,-1};
vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>&p){
  return os << p.first << " " << p.second;
}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
struct Diameter{
  vector<ll>dep,ret;
  ll n;
  vector<vector<ll>>g;
  ll diam,root,end;
  Diameter(vector<vector<ll>>&G):g(G),n(G.size()){
    dep.assign(n,-1LL);
    dfs(0,0);
    root = max_element(ALL(dep)) - dep.begin();
    fill(ALL(dep),-1LL);
    dfs(root,0);
    end = max_element(ALL(dep)) - dep.begin();
    diam = dep[end];
  }
  void dfs(ll k, ll d){
    dep[k] = d;
    for(auto to:g[k]){
      if(dep[to]==-1)dfs(to,d+1);
    }
  }
  vector<ll>diam_path(){
    vector<ll>tmp;
    dfs2(root,-1,tmp);
    return ret;
  }
  void dfs2(ll k, ll par,vector<ll>&v){
    v.PB(k);
    if(k==end)ret=v;
    for(auto to:g[k]){
      if(par!=to)dfs2(to,k,v);
    }
    v.pop_back();
  }
};
struct LCA{
  ll datasize = 21;
  ll n,root;//rootn
  vector<ll>depth;//0
  vector<vector<ll>>G,data;
  LCA(vector<vector<ll>>g,ll r):G(g),n(g.size()),root(r){
    data.assign(n,vector<ll>(datasize,-1));
    depth.assign(n,-1LL);
    build();
  }
  void build(){
    dfs(root,0);
    for(ll i=1;i<datasize;i++){
      for(ll j=0;j<n;j++){
        if(data[j][i-1]==-1)data[j][i]=-1;
        else data[j][i]=data[data[j][i-1]][i-1];
      }
    }
  }
  void dfs(ll k,ll d){
    depth[k]=d;
    for(ll i=0;i<G[k].size();i++){
      if(depth[G[k][i]]==-1){
        data[G[k][i]][0]=k;
        dfs(G[k][i],d+1);
      }
    }
  }
  ll deep(ll x){
    return x>=0?depth[x]:-1;
  }
  ll query(ll x,ll y){
    if(depth[x]<depth[y])swap(x,y);
    ll tmp = datasize - 1;
    while(depth[x]!=depth[y]){
      while(tmp>=1&&depth[y]>=deep(data[x][tmp]))tmp--;
      x = data[x][tmp];
    }
    tmp = datasize - 1;
    while(x!=y){
      while(tmp>=1&&data[x][tmp]==data[y][tmp])tmp--;
      x = data[x][tmp];
      y = data[y][tmp];
    }
    return x;
  }
  ll path(ll x,ll y){
    return deep(x)+deep(y)-2*deep(query(x,y));
  }
  ll par(ll x){
    return data[x][0];
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<vector<ll>>g(n);
  vector<ll>d(n);
  rep(i,0,n-1){
    ll u,v;cin>>u>>v;u--;v--;
    g[u].PB(v);
    g[v].PB(u);
    d[u]++;d[v]++;
  }
  LCA lca(g,0);
  Diameter dia(g);
  queue<ll>que;
  rep(i,0,n){
    if(d[i]<=1&&i!=dia.root&&i!=dia.end)que.push(i);
  }
  vector<ll>a,b,c;
  while(!que.empty()){
    auto p=que.front();
    que.pop();
    ll x=dia.root,y=dia.end;
    if(lca.path(x,p)<lca.path(y,p))swap(x,y);
    a.PB(p+1);b.PB(x+1);res+=lca.path(x,p);c.PB(p+1);
    for(auto to:g[p]){
      d[to]--;
      if(d[to]==1)que.push(to);
    }
  }
  auto path=dia.diam_path();
  ll sz=path.size();
  rep(i,0,sz-1){
    a.PB(path[sz-1]+1);b.PB(path[i]+1);c.PB(path[i]+1);res+=sz-i-1;
  }
  cout<<res<<endl;
  rep(i,0,n-1){
    cout<<a[i] spa b[i] spa c[i]<<endl;
  }
  return 0;
}
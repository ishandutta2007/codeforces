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
#define rrep(i,n,m) for(ll i = (m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 1e18;
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
ostream &operator<<(ostream &os, pair<ll, ll>&p){
  return os << p.first << " " << p.second;
}  
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
};

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,q;cin>>n;
  vector<vector<ll>>g(n);
  rep(i,0,n-1){
    ll u,v;cin>>u>>v;u--;v--;
    g[u].PB(v);
    g[v].PB(u);
  }
  LCA lca(g,0);
  cin>>q;
  while(q--){
    ll x,y,a,b,k;cin>>x>>y>>a>>b>>k;x--;y--;a--;b--;
    vector<ll>d;
    ll dxy=lca.path(x,y);
    ll day=lca.path(a,y);
    ll dax=lca.path(a,x);
    ll dbx=lca.path(b,x);
    ll dby=lca.path(b,y);
    ll dab=lca.path(a,b);
    d.PB(dab);
    d.PB(dax+dby+1);
    d.PB(day+dbx+1);
    d.PB(dax+dxy+1+dbx);
    d.PB(dby+dxy+1+day);
    bool judge=false;
    for(auto z:d){
        //cout<<z spa k<<endl;
        if(k>=z&&k%2==z%2)judge=true;
    }
    ans2(judge);
  }
  return 0;
}
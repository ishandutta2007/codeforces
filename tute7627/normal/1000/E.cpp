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
struct Lowlink{
  vector<vector<ll>>G;
  ll size;
  vector<ll>ord,low,used;
  vector<ll>articulation;
  vector<pair<ll,ll>>bridge;
  Lowlink(vector<vector<ll>>&g):G(g){
    size = G.size();
    ord.assign(size,-1);
    low.assign(size,-1);
    used.assign(size,0);
    ll tmp=0;
    for(ll i=0;i<size;i++){
      if(!used[i]){
        dfs(i,tmp,-1);
      }
    }
  }
  void dfs(ll k,ll &num,ll par){
    ord[k] = num;
    low[k] = num;
    num++;
    used[k] = 1;
    ll cnt=0;
    bool is_articulation=false;
    for(ll i=0;i<G[k].size();i++){
      if(par==G[k][i])continue;
      if(used[G[k][i]]){
        chmin(low[k],ord[G[k][i]]);
      }
      else{
        cnt++;
        dfs(G[k][i],num,k);
        chmin(low[k],low[G[k][i]]);
        if(ord[k]<low[G[k][i]])bridge.emplace_back(k,G[k][i]);
        if(ord[k]<=low[G[k][i]]&&par!=-1)is_articulation=true;
      }
    }
    if(par==-1&&cnt>=2)is_articulation=true;
    if(is_articulation)articulation.push_back(k);
    return; 
  }
  vector<ll>index;//
  vector<vector<ll>>edges;
  void TECC(){
    index.assign(G.size(),-1);
    ll cnt=0;
    for(ll i=0;i<size;i++){
      if(index[i]==-1)dfs_tecc(i,-1,cnt);
    }
    edges.assign(cnt+1,vector<ll>());
    for(ll i=0;i<bridge.size();i++){
      ll u=index[bridge[i].fi],v=index[bridge[i].se];
      edges[u].push_back(v);
      edges[v].push_back(u);
    }
  }
  void dfs_tecc(ll k,ll par,ll &group){
    if(par==-1||ord[par]<low[k]){
      index[k] = group++;
    }
    else index[k] = index[par];
    for(ll i=0;i<G[k].size();i++){
      if(index[G[k][i]]==-1)dfs_tecc(G[k][i],k,group);
    }
  }
};
struct Diameter{
  vector<ll>dep;
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
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  vector<vector<ll>>g(n);
  rep(i,0,m){
    ll x,y;cin>>x>>y;x--;y--;
    g[x].PB(y);
    g[y].PB(x);
  }
  Lowlink low(g);
  low.TECC();
  Diameter dm(low.edges);
  cout<<dm.diam<<endl;
  return 0;
}
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
template<typename T>void rearrange(vector<ll>&ord, vector<T>&v){
  auto tmp = v;
  for(int i=0;i<tmp.size();i++)v[i] = tmp[ord[i]];
}
template<typename Head, typename... Tail>void rearrange(vector<ll>&ord,Head&& head, Tail&&... tail){
  rearrange(ord, head);
  rearrange(ord, tail...);
}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};

template< typename T = int >
struct edge {
  int to;
  T cost;
  edge() = default;
  edge(int to, T cost = 1):to(to), cost(cost){}
  operator int() const { return to; }
};
template<typename T>
using Graph = vector<vector<edge<T>>>;
template<typename T>
Graph<T> readGraph(int n,int m,int indexed=1,bool directed=false,bool weighted=false){
  Graph<T> ret(n);
  while(m--){
    int u,v,w=1;
    cin>>u>>v;u-=indexed,v-=indexed;
    if(weighted)cin>>w;
    ret[u].emplace_back(v,w);
    if(!directed)ret[v].emplace_back(u,w);
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
struct RangeGraph{
  Graph<T> g;
  int n,sz;
  int cnt;
  RangeGraph(int n,int m):n(n){
    sz=1;cnt=0;
    while(sz<n)sz <<= 1;
    g.assign(3*sz+m,vector<edge<T>>());
    for(int i=1;i<sz;i++){
      g[i].emplace_back(2*i,0);
      g[i].emplace_back(2*i+1,0);
      if(2*i<sz){
        g[2*i+2*sz].emplace_back(i+2*sz,0);
        g[2*i+1+2*sz].emplace_back(i+2*sz,0);
      }
      else{
        g[2*i].emplace_back(i+2*sz,0);
        g[2*i+1].emplace_back(i+2*sz,0);
      }
    }
  }
  void add_edge(int l1,int r1,int l2,int r2,int w){//[l1,r1)->[l2,r2)
    if(l1>=r1||l2>=r2)return;
    if(l1+1==r1&&l2+1==r2){
      g[l1+sz].emplace_back(l2+sz,w);
    }
    else if(l1+1==r1){
      auto v=range(l2,r2);
      v=range(l2,r2);
      for(auto z:v)g[l1+sz].emplace_back(z,w);
    }
    else if(l2+1==r2){
      auto v=range(l1,r1);
      for(auto z:v){
        if(z<sz)g[z+2*sz].EB(l2+sz,w);
        else g[z].EB(l2+sz,w);
      }
    }
    else{
      auto v=range(l1,r1);
      ll via=3*sz+cnt;
      for(auto z:v){
        if(z<sz)g[z+2*sz].EB(via,w);
        else g[z].EB(via,w);
      }
      v=range(l2,r2);
      for(auto z:v)g[via].EB(z,0);
      cnt++;
    }
  }
  vector<int>range(int l,int r){
    vector<int>ret;
    l+=sz,r+=sz;
    while(l!=r){
      if(l&1)ret.PB(l++);
      if(r&1)ret.PB(--r);
      l>>=1,r>>=1;
    }
    return ret;
  };
  int add(){
    return sz;
  }
};
template<typename T>
vector<ll> dijkstra(Graph<T>&g,ll s = 0) {
  using PT=pair<ll,int>;
  priority_queue<PT, vector<PT>, greater<PT> > que;
  vector<ll>dist(g.size(),INF);
  dist[s] = 0;
  que.emplace(0, s);
  while (!que.empty()) {
    PT p = que.top();
    que.pop();
    int v = p.second;
    if (dist[v] < p.first) continue;
    for(auto e:g[v]) {
      if (dist[e.to] > dist[v] + e.cost) {
          dist[e.to] = dist[v] + e.cost;
          que.emplace(dist[e.to], e.to);
      }
    }
  }
  return dist;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,q,s;cin>>n>>q>>s;s--;
  RangeGraph<ll> gr(n,0);
  ll add=gr.add();
  while(q--){
    ll t;cin>>t;
    if(t==1){
      ll v,u,w;cin>>v>>u>>w;v--;u--;
      gr.add_edge(v,v+1,u,u+1,w);
    }
    else{
      ll v,l,r,w;cin>>v>>l>>r>>w;l--;v--;
      if(t==2)gr.add_edge(v,v+1,l,r,w);
      else gr.add_edge(l,r,v,v+1,w);
    }
  }
  //rep(i,0,4*len)for(auto e:g[i])cout<<i spa e.to spa e.cost<<endl; 
  auto dist=dijkstra(gr.g,s+add);
  rep(i,0,n){
    if(i!=0)cout<<" ";
    cout<<(dist[i+add]==INF?-1:dist[i+add]);
  }
  cout<<endl;
  return 0;
}
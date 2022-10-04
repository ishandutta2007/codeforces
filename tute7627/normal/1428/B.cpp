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
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
struct SCC{
  int n;
  const vector<vector<int>>&G;
  vector<int>index;//
  vector<int>start,visited,low,ord;
  int now_ord,group_num;
  SCC(const vector<vector<int>>&g):G(g),n(g.size()){
    index.assign(n,-1LL);
    build();
  }
  void build(){
    low.assign(n,0);ord.assign(n,-1);index.assign(n,0);
    visited.reserve(n);
    now_ord=0,group_num=0;
    for(int i=0;i<n;i++){
      if(ord[i]==-1)dfs(i);
    }
    for(auto& x:index)x=group_num-1-x;
  }
  void dfs(int v){
    low[v]=ord[v]=now_ord++;
    visited.push_back(v);
    for(auto to:G[v]){
      if(ord[to]==-1){
        dfs(to);
        low[v]=min(low[v],low[to]);
      }
      else{
        low[v]=min(low[v],ord[to]);
      }
    }
    if(low[v]==ord[v]){
      while(1){
        int u=visited.back();
        visited.pop_back();
        ord[u]=n;
        index[u]=group_num;
        if(u==v)break;
      }
      group_num++;
    }

  }
  vector<vector<int>>edges;
  void build_edges(){
    edges.assign(*max_element(ALL(index))+1,vector<int>());
    for(ll i=0;i<n;i++){
      for(ll j=0;j<G[i].size();j++){
        if(index[i]!=index[G[i][j]]){
          edges[index[i]].push_back(index[G[i][j]]);
        }
      }
    }
  }
  vector<int>output(){return index;};
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll t;cin>>t;
  while(t--){
    ll n;cin>>n;
    string s;cin>>s;
    vector<vector<int>>g(n);
    rep(i,0,n){
      ll u=i,v=(i+1)%n;
      if(s[i]!='<')g[u].PB(v);
      if(s[i]!='>')g[v].PB(u);
    }
    SCC scc(g);
    vector<ll>sz(n);
    rep(i,0,n)sz[scc.index[i]]++;
    ll ret=0;
    rep(i,0,n)if(sz[scc.index[i]]>=2)ret++;
    cout<<ret<<endl;
  }
  return 0;
}
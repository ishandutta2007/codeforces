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
struct edge {
  ll to,cost;
  edge(ll x,ll y):to(x),cost(y){};
};
vector<vector<ll>> WarshallFloyd(vector<vector<edge>>&g){
  ll n=g.size();
  vector<vector<ll>>ret(n,vector<ll>(n,INF));
  for(ll i=0;i<n;i++){
    ret[i][i]=0;
    for(ll j=0;j<g[i].size();j++){
      chmin(ret[i][g[i][j].to],g[i][j].cost);
    }
  }
  for(ll j=0;j<n;j++){
    for(ll i=0;i<n;i++){
      for(ll o=0;o<n;o++){
        if(ret[i][j]!=INF&&ret[j][o]!=INF){
          chmin(ret[i][o],ret[i][j]+ret[j][o]);
        }
      }
    }
  }
  return ret;
} 
vector<ll>nibu_graph(vector<vector<ll>>&g){
  ll n=g.size();
  vector<ll>t(n,-1);
  queue<P>que;
  for(ll i=0;i<n;i++){
    if(t[i]!=-1)continue;
    que.emplace(i,0);
    t[i]=0;
    while(!que.empty()){
      auto p=que.front();que.pop();
      for(auto to:g[p.fi]){
        if(t[to]==-1){
          que.emplace(to,p.se^1);
          t[to]=p.se^1;
        }
        else if(p.se==t[to])return vector<ll>();
      }
    }
  }
  return t;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  vector<vector<edge>>g(n);
  vector<vector<ll>>gt(n);
  rep(i,0,m){
    ll u,v,b;cin>>u>>v>>b;u--;v--;
    if(b==0){
      g[u].EB(v,1);
      g[v].EB(u,1);
    }
    else{
      g[u].EB(v,1);
      g[v].EB(u,-1);
    }
    gt[u].PB(v);
    gt[v].PB(u);
  }
  if(nibu_graph(gt).empty())judge=false;
  auto mat=WarshallFloyd(g);
  rep(i,0,n)if(mat[i][i]<0)judge=false;
  ans2(judge);
  if(!judge)return 0;
  vector<ll>ret(n);
  ll mx=-INF,pre=-1;
  rep(i,0,n)rep(j,0,n){
    if(chmax(mx,mat[i][j]))pre=i;
  }
  rep(i,0,n)ret[i]=mat[pre][i];
  cout<<mx<<endl;
  debug(ret,n);
  return 0;
}
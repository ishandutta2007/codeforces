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
map<ll,ll> factoring(ll n){ 
  ll buf=n;
  map<ll,ll>ret;
  ll i,j;
  for(i=2;buf!=1&&i*i<=n;i++){
    for(j=0;buf%i==0;j++){
      buf/=i;
    }
    if(j>0)ret.emplace(i,j);
  }
  if(buf!=1)ret.emplace(buf,1);
  return ret;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  ll sz=5001;
  //ll sz=10;cout<<"naosu"<<endl;
  auto f=vec(sz,sz,0LL);
  vector<ll>d(sz);
  rep(i,1,sz){
    auto mp=factoring(i+1);
    f[i]=f[i-1];
    d[i]=d[i-1];
    for(auto z:mp){
      f[i][z.fi]+=z.se;
      d[i]+=z.se;
    }
  }
  auto lca=[&](ll x,ll y){
    ll dep=0;
    rrep(i,0,sz){
      dep+=min(f[x][i],f[y][i]);
      if(f[x][i]!=f[y][i])break;
    }
    return dep;
  };
  struct edge{
    ll to,cost;
  };
  vector<vector<edge>>g(sz);
  stack<ll>st;
  st.push(0);
  rep(i,1,sz){
    ll dep=lca(i-1,i);
    //debug(f[i],sz);
    //debug(f[i-1],sz);
    //cout<<i spa dep spa d[i] spa st.size()<<endl;
    ll local=-1;
    while(d[st.top()]>dep){
      ll now=st.top();
      st.pop();
      if(d[st.top()]>dep)g[st.top()].push_back({now,d[now]-d[st.top()]});
      else local=now;
    }
    if(d[st.top()]!=dep){
      g.push_back(vector<edge>());
      st.push(d.size());
      d.push_back(dep);
    }
    if(local!=-1)g[st.top()].push_back({local,d[local]-d[st.top()]});
    st.push(i);
  }
  //cout<<st.size() spa st.top()<<endl;
  while(st.size()>=2){
    ll now=st.top();
    st.pop();
    //cout<<now spa st.top() spa d[now] spa d[st.top()]<<endl;
    g[st.top()].push_back({now,d[now]-d[st.top()]});
  }
  vector<ll>a(d.size());
  rep(i,0,n){
    ll k;cin>>k;k=max(k-1,0LL);
    a[k]++;
  }
  //debug(a,10);
  auto dfs=[&](auto &&f,ll pos)->void{
    for(auto e:g[pos]){
      f(f,e.to);
      res+=e.cost*min(a[e.to],n-a[e.to]);
      //if(a[e.to]>0)cout<<pos spa e.to spa a[e.to] spa e.cost<<endl;
      //if(pos<10)cout<<pos spa a[pos] spa e.to spa e.cost<<endl;
      a[pos]+=a[e.to];
    }
  };
  //debug(a,10);
  dfs(dfs,0);
  cout<<res<<endl;
  return 0;
}
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
vector<pair<bool,vector<vector<ll>>>>nibu_graph_con(vector<vector<ll>>&g){
  ll n=g.size();
  vector<pair<bool,vector<vector<ll>>>>v;
  vector<ll>t(n,-1);
  queue<P>que;
  for(ll i=0;i<n;i++){
    if(t[i]!=-1)continue;
    que.emplace(i,0);
    v.emplace_back(true,vector<vector<ll>>(2));
    t[i]=0;
    while(!que.empty()){
      auto p=que.front();que.pop();
      v.back().second[p.se].push_back(p.fi);
      for(auto to:g[p.fi]){
        if(t[to]==-1){
          que.emplace(to,p.se^1);
          t[to]=p.se^1;
        }
        else if(p.se==t[to])v.back().first=false;
      }
    }
  }
  return v;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  vector<vector<ll>>g(n);
  rep(i,0,m){
    ll u,v;cin>>u>>v;u--;v--;
    g[u].PB(v);
    g[v].PB(u);
  }
  auto t=nibu_graph_con(g);
  vector<vector<ll>>a(2);
  for(auto &z:t){
    if(!z.fi)judge=false;
    else{
      rep(i,0,2){
        for(auto zz:z.se[i])a[i].PB(zz+1);
      }
    }
  }
  if(!judge)cout<<-1<<endl;
  else{
    rep(i,0,2){
      cout<<a[i].size()<<endl;
      debug(a[i],a[i].size());
    }
  }
  return 0;
}
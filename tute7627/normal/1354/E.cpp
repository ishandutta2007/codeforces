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
vector<ll>dx={1,0,-1,0,1,1,-1,-1};
vector<ll>dy={0,1,0,-1,1,-1,1,-1};
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
vector<ll>a(5005,-1);
bool nibu=true;
void dfs(ll k,vector<vector<ll>>&g,ll now,vector<vector<ll>>&cnt){
  a[k]=now;
  cnt[now].PB(k);
  for(auto to:g[k]){
    if(a[to]!=-1&&a[to]!=(now^1))nibu=false;
    if(a[to]!=-1)continue;
    dfs(to,g,now^1,cnt);
  }
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  ll n1,n2,n3;cin>>n1>>n2>>n3;
  vector<vector<ll>>g(n);
  rep(i,0,m){
    ll u,v;cin>>u>>v;u--;v--;
    g[u].PB(v);
    g[v].PB(u);
  }
  vector<vector<vector<ll>>>v;
  vector<vector<bool>>from(1,vector<bool>(n+1,false));
  vector<vector<bool>>dp(1,vector<bool>(n+1,false));
  dp[0][0]=true;
  ll t=0;
  rep(i,0,n){
    if(a[i]!=-1)continue;
    v.PB(vector<vector<ll>>(2,vector<ll>()));
    dfs(i,g,0,v.back());
    ll sz0=v[t][0].size();
    ll sz1=v[t][1].size();
    dp.emplace_back(n+1,false);
    from.emplace_back(n+1,false);
    rep(j,0,n+1){
      if(!dp[t][j])continue;
      if(j+sz0<=n){
        dp[t+1][j+sz0]=true;
        from[t+1][j+sz0]=false;
      }
      if(j+sz1<=n){
        dp[t+1][j+sz1]=true;
        from[t+1][j+sz1]=true;
      }
    }
    t++;
  }
  if(!nibu||!dp[t][n2]){
    cout<<"NO"<<endl;
    return 0;
  }
  cout<<"YES"<<endl;
  ll now=n2;
  string ret(n,'1');
  rrep(i,0,t){
    if(from[i+1][now])swap(v[i][0],v[i][1]);
    ll sz2=v[i][0].size(),sz3=v[i][1].size();
    if(n3>=sz3){
      for(auto z:v[i][1])ret[z]='3';
      n3-=sz3;
    }
    else if(n3){
      rep(j,0,n3)ret[v[i][1][j]]='3';
      n3=0;
    }
    for(auto z:v[i][0])ret[z]='2';
    now-=sz2;
  }
  cout<<ret<<endl;
  return 0;
}
//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

//#define int long long
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

signed main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<string>s(n);
  rep(i,0,n)cin>>s[i];
  ll m=s[0].size();
  vector<ll>a(1<<m);
  if(n==1){
    cout<<0<<endl;
    return 0;
  }
  vector<vector<ll>>dif(m,vector<ll>(n,0LL));
  rep(i,0,m){
    rep(j,0,n)rep(o,0,n){
      if(s[j][i]!=s[o][i])dif[i][j]^=1LL<<o;
    }
  }
  {
    ll mask=(1LL<<n)-1;
    auto dfs=[&](auto &&f,vector<ll>v,int d,int bit)->void{
      if(d==s[0].size()){
        for(auto z:v)if(z==mask)a[bit]++;
        return;
      }
      f(f,v,d+1,bit);
      vector<ll>nxt=v;
      rep(i,0,n)nxt[i]|=dif[d][i];
      f(f,nxt,d+1,bit|1LL<<d);
    };
    vector<ll>emp(n);
    rep(i,0,n)emp[i]=1LL<<i;
    dfs(dfs,emp,0,0);
  }
  vector<ld>dp(1LL<<m);
  dp[0]=1;
  ld ret=0;
  rep(i,0,1<<m){
    ret+=dp[i];
    if(a[i]==n)continue;
    if(popcount(i)==m)continue;
    ll cnt=m-popcount(i);
    rep(j,0,m){
      if(i&1LL<<j)continue;
      ll to=n-a[i|1LL<<j];
      ll from=n-a[i];
      //ret+=dp[i]*(from-to)/from*coef*popcount(i+1);
      dp[i|1LL<<j]+=dp[i]*to/from/cnt;
    }
  }
  //debug(a,a.size());
  //debug(dp,dp.size());
  lfs<<ret<<endl;
  return 0;
}
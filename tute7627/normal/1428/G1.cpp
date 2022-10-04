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
template<typename T> 
struct SWAG{
  stack<pair<T,T>>st_front,st_back;
  T func(T x, T y){return max(x,y);}
  void push(T x){
    if(st_back.empty())st_back.emplace(x,x);
    else st_back.emplace(x,func(st_back.top().second,x));
  }
  void pop(){
    if(st_front.empty()){
      while(!st_back.empty()){
       if(st_front.empty())st_front.emplace(st_back.top().first,st_back.top().first);
       else st_front.emplace(st_back.top().first,func(st_back.top().first, st_front.top().second));
       st_back.pop();
      }
    }
    st_front.pop();
  }
  T query(){
    if(st_front.empty())return st_back.top().second;
    else if(st_back.empty())return st_front.top().second;
    else return func(st_front.top().second, st_back.top().second);
  }
  bool empty(){
    return st_front.empty() && st_back.empty();
  }
  int size(){
    return st_front.size() + st_back.size();
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll k;cin>>k;
  vector<ll>f(6);
  rep(i,0,6)cin>>f[i];
  ll q,n;cin>>q>>n;
  ll sz=n+1;
  auto dp=vec(7,sz,-INF);
  dp[0][0]=0;
  vector<ll>p(6,3);
  rep(i,0,5)p[i+1]=p[i]*10;
  //debug(p,6);
  rep(i,0,6){
    ll lim=(k-1)*3;
    rep(j,0,p[i]){
      ll cnt=0;
      SWAG<ll>swag;
      for(ll o=j;o<sz;o+=p[i]){
        if(swag.size()>lim)swag.pop();
        swag.push(dp[i][o]-cnt*f[i]);
        dp[i+1][o]=swag.query()+cnt*f[i];
        cnt++;
      }
    }
  }
  //debug(dp,7,sz);
  rep(i,0,n+1){
    ll rem=n-i;
    ll add=0;
    rep(j,0,6){
      ll tmp=rem%10;
      if(tmp%3==0)add+=f[j]*tmp/3;
      rem/=10;
    }
    //cout<<i spa n-i spa add spa dp[6][i]<<endl;
    chmax(res,add+dp[6][i]);
  }
  cout<<res<<endl;
  return 0;
}
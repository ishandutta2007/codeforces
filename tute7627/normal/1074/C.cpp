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

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>x(n),y(n);
  rep(i,0,n)cin>>x[i]>>y[i];
  P xl(INF,-1),xr(-INF,-1),yl(INF,-1),yr(-INF,-1);
  rep(i,0,n){
    chmin(xl,MP(x[i],i));
    chmax(xr,MP(x[i],i));
    chmin(yl,MP(y[i],i));
    chmax(yr,MP(y[i],i));
  }
  vector<ll>v;
  for(auto p:{xl,yr,xr,yl}){
    if(p.se!=-1)v.PB(p.se);
  }
  //assert(v.size()>=3);
  //debug(v,v.size());
  vector<ll>mx(5,-INF);
  ll m=v.size();
  auto dist=[&](ll i,ll j){
    return abs(x[i]-x[j])+abs(y[i]-y[j]);
  };
  rep(i,0,1<<m){
    ll sum=0;
    vector<ll>tmp;
    rep(j,0,m)if(i&1<<j)tmp.PB(j);
    ll sz=tmp.size();
    rep(j,0,sz)sum+=dist(v[tmp[j]],v[tmp[(j+1)%sz]]);
    //cout<<popcount(i) spa sum<<endl;
    chmax(mx[max(3,popcount(i))],sum);
  }
  rep(i,0,m){
    ll dif=dist(v[i],v[(i+1)%m]);
    rep(j,0,n)chmax(mx[3],dif+dist(v[i],j)+dist(v[(i+1)%m],j));
  }
  rep(i,3,n+1){
    if(i==3)cout<<mx[i];
    else cout<<" "<<max(mx[3],mx[4]);
  }
  cout<<endl;
  return 0;
}
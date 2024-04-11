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
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>&p){
  return os << p.first << " " << p.second;
}  
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>x(n);
  vector<char>c(n);
  rep(i,0,n)cin>>x[i]>>c[i];
  /*ll mxr=-1,mxb=-1,mir=INF,mib=INF;
  rep(i,0,n){
    if(c[i]=='R')chmax(mxr,i),chmin(mir,i);
    if(c[i]=='B')chmax(mxb,i),chmin(mib,i);
  }*/
  vector<ll>r,b;
  ll prep=-INF;
  rep(i,0,n){
    if(c[i]=='R')r.PB(x[i]);
    else if(c[i]=='B')b.PB(x[i]);
    else{
      if(prep==-INF){
        if(!r.empty())res+=x[i]-r[0];
        if(!b.empty())res+=x[i]-b[0];
      }
      else{
        ll dr=x[i]-r.back(),db=x[i]-b.back();
        rep(i,0,ll(r.size())-1)chmax(dr,r[i+1]-r[i]);
        rep(i,0,ll(b.size())-1)chmax(db,b[i+1]-b[i]);
        ll d=x[i]-prep;
        res+=min(2*d,d+2*(x[i]-prep)-(db+dr));
      }
      prep=x[i];
      r.clear();
      b.clear();
      r.PB(prep);
      b.PB(prep);
    }
    //cout<<i spa res spa prep<<endl;
  }
  if(!r.empty())res+=r.back()-r[0];
  if(!b.empty())res+=b.back()-b[0];
  cout<<res<<endl;
  return 0;
}
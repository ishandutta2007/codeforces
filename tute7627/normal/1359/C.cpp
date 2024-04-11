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
struct RationalNumber{
  long long a, b;
  RationalNumber(){
    a = 0,b = 1;
  }
  RationalNumber(long long p, long long q):a(p), b(q){// a / b
    reduction();
  };
  void reduction(){
    long long g = __gcd(a, b);
    a /= g, b /= g;
  }
  RationalNumber &operator+=(const RationalNumber &x){
    long long q = b / __gcd(b, x.b) * x.b;
    a = a * (q / b) + x.a * (q / x.b);
    b = q;
    reduction();
    return *this;
  }
  RationalNumber &operator-=(const RationalNumber &x){
    long long q = b / __gcd(b, x.b) * x.b;
    a = a * (q / b) - x.a * (q / x.b);
    b = q;
    reduction();
    return *this;
  }
  RationalNumber &operator*=(const RationalNumber &x){
    long long q1 = __gcd(a, x.b), q2 = __gcd(b, x.a); 
    a = (a / q1) * (x.a / q2), b = (b / q2) * (x.b / q1); 
    return *this;
  }
  RationalNumber &operator/=(const RationalNumber &x){
    long long q1 = __gcd(a, x.a), q2 = __gcd(b, x.b); 
    a = (a / q1) * (x.b / q2), b = (b / q2) * (x.a / q1); 
    return *this;
  }
  RationalNumber operator+(const RationalNumber &x)const{
    return RationalNumber(*this) += x;
  }
  RationalNumber operator-(const RationalNumber &x)const{
    return RationalNumber(*this) -= x;
  }
  RationalNumber operator*(const RationalNumber &x)const{
    return RationalNumber(*this) *= x;
  }
  RationalNumber operator/(const RationalNumber &x)const{
    return RationalNumber(*this) /= x;
  }
  RationalNumber operator-()const{
    return RationalNumber(-a, b);
  }
  bool operator==(const RationalNumber &x)const{
    return a * x.b == b * x.a;
  };
  bool operator!=(const RationalNumber &x)const{
    return !(*this == x);
  };
  bool operator<(const RationalNumber &x)const{
    return a * x.b < b * x.a;
  }
  bool operator>(const RationalNumber &x)const{
    return a * x.b > b * x.a;
  }
  bool operator<=(const RationalNumber &x)const{
    return *this < x || *this == x;
  }
  bool operator>=(const RationalNumber &x)const{
    return *this > x || *this == x;
  }
  friend ostream &operator<<(ostream &os, RationalNumber x){
    return os << x.a << "/" << x.b;
  }
};
using rat=RationalNumber;
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll t;cin>>t;
  while(t--){
    ll h,c,x;cin>>h>>c>>x;
    h-=x;c-=x;
    ll s=h+c;
    using PR=pair<rat,ll>;
    pair<rat,ll>p;
    p.fi=rat((ll)1e6,1);
    p.se=INF;
    chmin(p,MP(rat(abs(s),2),2LL));
    ll now=0;
    if(s!=0)now=max(0LL,h/abs(s)-1);
    //cout<<h spa s spa now<<endl;
    rep(i,now,now+5){
      //cout<<p<<endl;
      //cout<<i spa rat(abs(h+s*i),2*i+1)<<endl;
      chmin(p,MP(rat(abs(h+s*i),2*i+1),2*i+1));
    }
    cout<<p.se<<endl;
  }
  return 0;
}
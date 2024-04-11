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
#define rrep(i,n,m) for(ll i = (m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
//const ll MOD = 1e9+7;
const ll MOD = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T>
void chmin(T &a,T b){if(a>b)a=b;}
template<typename T>
void chmax(T &a,T b){if(a<b)a=b;}
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
ostream &operator<<(ostream &os, pair<ll, ll>&p){
  return os << p.first << " " << p.second;
}  
template< int mod >
struct ModInt {
  ll x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};
using modint = ModInt< MOD >;
modint pow2(int64_t n, int64_t x){
    return modint(n).pow(x);
}
vector<ll>z_algorithm(string s){
  ll n = s.size();
  vector<ll>ret(n,0);
  ret[0] = n;
  ll p = 1,len = 0;
  while(p < n){
    while(p+len < n && s[len] == s[p+len])len++;
    ret[p] = len;
    if(len == 0){p++; continue;}
    ll k = 1;
    while(p+k < n && k+ret[k] < len)ret[p+k] = ret[k], k++;
    p += k, len -= k;
  }
  return ret;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  string a,l,r;cin>>a>>l>>r;
  ll n=a.size(),nl=l.size(),nr=r.size();
  auto vl=z_algorithm(l+a);
  auto vr=z_algorithm(r+a);
  vector<modint>cum(n+2);
  vector<modint>b(n+1);
  cum[0]=0;cum[1]=1;
  rep(i,0,n){
    modint now=0;
    ll idxl=max(0LL,i-nl+1),idxr=max(0LL,i-nr+2);
    //cout<<idxl spa idxr<<endl;
    if(i>=nl-1&&(vl[i+1]>=nl||a[i-nl+1+vl[i+1]]>=l[vl[i+1]]))idxl++;
    if(i>=nr-1&&(vr[i+1]>=nr||a[i-nr+1+vr[i+1]]<=r[vr[i+1]]))idxr--;
    //cout<<idxl spa idxr<<endl;
    //cout<<a[i+vr[i+1]] spa r[vr[i+1]] spa vr[i+1]<<endl;
    if(idxr<idxl)now=cum[idxl]-cum[idxr];
    if(l=="0")now+=b[i];
    if(i==n-1||a[i+1]!='0'){
      cum[i+2]=cum[i+1]+now;
    }
    else{
      b[i+1]=now;
      cum[i+2]=cum[i+1];
    }
  }
  //debug(cum,n+2);
  //debug(b,n);
  //debug(vl,vl.size());
  //debug(vr,vr.size());
  cout<<cum[n+1]-cum[n]<<endl;
  return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define test cout<<"test"<<endl;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = (n); i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = (m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T>
void chmin(T &a,T b){if(a>b)a=b;}
template<typename T>
void chmax(T &a,T b){if(a<b)a=b;}
void pmod(ll &a,ll b){a=(a+b)%MOD;}
void pmod(ll &a,ll b,ll c){a=(b+c)%MOD;}
void qmod(ll &a,ll b){a=(a*b)%MOD;}
void qmod(ll &a,ll b,ll c){a=(b*c)%MOD;}
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

ll mod;
struct ModInt {
  int x;

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
    a = ModInt(t);
    return (is);
  }

  static int get_mod() { return mod; }
};
using modint = ModInt;
modint pow2(int64_t n, int64_t x){
    return modint(n).pow(x);
}
template<typename T>
struct Polynomial{
  ll size;
  vector<T>data;
  Polynomial(ll d):size(d){
    data.assign(size,T(0));
  }
  Polynomial(vector<T>&a){
    data = a;
    size = (ll)a.size();
  }
  T &operator[](ll idx){
    return data.at(idx); 
  }
  T operator[](ll idx)const{
    return data.at(idx); 
  }
  Polynomial operator+(const Polynomial &p)const{
    Polynomial<T> ret(max(this->size,p.size));
    for(ll i=0;i<ret.size;i++){
      if(i < this->size)ret[i] += data[i];
      if(i < p.size)ret[i] += p.data[i];
    }
    return ret;
  }
  Polynomial operator-(const Polynomial &p)const{
    Polynomial<T> ret(max(this->size,p.size));
    for(ll i=0;i<ret.size;i++){
      if(i < this->size)ret[i] += data[i];
      if(i < p.size)ret[i] -= p.data[i];
    }
    return ret;
  }
  Polynomial operator*(const Polynomial &p)const{
    Polynomial<T> ret(this->size + p.size - 1);
    for(ll i=0;i<size;i++){
      for(ll j=0;j<p.size;j++){
        ret[i+j] += data[i] * p.data[j];
      }
    }
    return ret;
  }
  Polynomial operator*(const T x)const{
    Polynomial<T> ret = *this;
    for(ll i=0;i<ret.size;i++)ret[i]*=x;
    return ret;
  }
  Polynomial operator/(const Polynomial &p)const{
    Polynomial<T> ret(max(0LL,this->size - p.size) + 1);
    Polynomial<T> remain = *this;
    for(ll i=this->size;i>=p.size;i--){
      ret[i-p.size]=remain[i-1]/p[p.size-1];
      for(ll j=0;j<p.size;j++){
        remain[i-p.size+j]-=p[j]*ret[i-p.size];
      }
    }
    return ret;
  }
  T func(ll x){
    T ret=0,tmp=1;
    for(ll i=0;i<size;i++){
      ret+=data[i]*tmp;
      tmp*=x;
    }
    return ret;
  }
};
template<typename T>
Polynomial<T> lagrange_polynomial(const vector<T>&y){
  ll n=y.size();
  Polynomial<T>ret(n);
  Polynomial<T>tmp(1);tmp[0]=1;  
  vector<T>v(2);v[1]=1;
  for(ll i=0;i<n;i++){
    tmp = tmp * Polynomial<T>(v);
    v[0] -= 1;
  }
  v=vector<T>(2);v[1]=1;
  for(ll i=0;i<n;i++){
    auto p = tmp / Polynomial<T>(v);
    ret = ret + p * (y[i] / p.func(i));
    v[0] -= 1;
  }
  return ret;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  //cout<<fixed<<setprecision(10);
  ll res=0,buf=0;
  bool judge = true;
  mod=1000003;
  vector<modint>a(11);
  rep(i,0,11){
    cout<<"?" spa i<<endl;
    cin>>a[i];
  }
  auto p=lagrange_polynomial(a);
  ll x=-1;
  rep(i,0,mod){
    if(p.func(i)==0)x=i;
  }
  cout<<"!" spa x<<endl;
  return 0;
}
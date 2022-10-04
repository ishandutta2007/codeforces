//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

//#define endl '\n'
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
namespace FastPrimeFactorization {

  template< typename word, typename dword, typename sword >
  struct UnsafeMod {
    UnsafeMod() : x(0) {}

    UnsafeMod(word _x) : x(init(_x)) {}

    bool operator==(const UnsafeMod &rhs) const {
      return x == rhs.x;
    }

    bool operator!=(const UnsafeMod &rhs) const {
      return x != rhs.x;
    }

    UnsafeMod &operator+=(const UnsafeMod &rhs) {
      if((x += rhs.x) >= mod) x -= mod;
      return *this;
    }

    UnsafeMod &operator-=(const UnsafeMod &rhs) {
      if(sword(x -= rhs.x) < 0) x += mod;
      return *this;
    }

    UnsafeMod &operator*=(const UnsafeMod &rhs) {
      x = reduce(dword(x) * rhs.x);
      return *this;
    }

    UnsafeMod operator+(const UnsafeMod &rhs) const {
      return UnsafeMod(*this) += rhs;
    }

    UnsafeMod operator-(const UnsafeMod &rhs) const {
      return UnsafeMod(*this) -= rhs;
    }

    UnsafeMod operator*(const UnsafeMod &rhs) const {
      return UnsafeMod(*this) *= rhs;
    }

    UnsafeMod pow(uint64_t e) const {
      UnsafeMod ret(1);
      for(UnsafeMod base = *this; e; e >>= 1, base *= base) {
        if(e & 1) ret *= base;
      }
      return ret;
    }

    word get() const {
      return reduce(x);
    }

    static constexpr int word_bits = sizeof(word) * 8;

    static word modulus() {
      return mod;
    }

    static word init(word w) {
      return reduce(dword(w) * r2);
    }

    static void set_mod(word m) {
      mod = m;
      inv = mul_inv(mod);
      r2 = -dword(mod) % mod;
    }

    static word reduce(dword x) {
      word y = word(x >> word_bits) - word((dword(word(x) * inv) * mod) >> word_bits);
      return sword(y) < 0 ? y + mod : y;
    }

    static word mul_inv(word n, int e = 6, word x = 1) {
      return !e ? x : mul_inv(n, e - 1, x * (2 - x * n));
    }

    static word mod, inv, r2;

    word x;
  };

  using uint128_t = __uint128_t;

  using Mod64 = UnsafeMod< uint64_t, uint128_t, int64_t >;
  template<> uint64_t Mod64::mod = 0;
  template<> uint64_t Mod64::inv = 0;
  template<> uint64_t Mod64::r2 = 0;

  using Mod32 = UnsafeMod< uint32_t, uint64_t, int32_t >;
  template<> uint32_t Mod32::mod = 0;
  template<> uint32_t Mod32::inv = 0;
  template<> uint32_t Mod32::r2 = 0;

  bool miller_rabin_primality_test_uint64(uint64_t n) {
    Mod64::set_mod(n);
    uint64_t d = n - 1;
    while(d % 2 == 0) d /= 2;
    Mod64 e{1}, rev{n - 1};
    // http://miller-rabin.appspot.com/  < 2^64
    for(uint64_t a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
      if(n <= a) break;
      uint64_t t = d;
      Mod64 y = Mod64(a).pow(t);
      while(t != n - 1 && y != e && y != rev) {
        y *= y;
        t *= 2;
      }
      if(y != rev && t % 2 == 0) return false;
    }
    return true;
  }

  bool miller_rabin_primality_test_uint32(uint32_t n) {
    Mod32::set_mod(n);
    uint32_t d = n - 1;
    while(d % 2 == 0) d /= 2;
    Mod32 e{1}, rev{n - 1};
    for(uint32_t a : {2, 7, 61}) {
      if(n <= a) break;
      uint32_t t = d;
      Mod32 y = Mod32(a).pow(t);
      while(t != n - 1 && y != e && y != rev) {
        y *= y;
        t *= 2;
      }
      if(y != rev && t % 2 == 0) return false;
    }
    return true;
  }

  bool is_prime(uint64_t n) {
    if(n == 2) return true;
    if(n == 1 || n % 2 == 0) return false;
    if(n < uint64_t(1) << 31) return miller_rabin_primality_test_uint32(n);
    return miller_rabin_primality_test_uint64(n);
  }

  uint64_t pollard_rho(uint64_t n) {
    if(is_prime(n)) return n;
    if(n % 2 == 0) return 2;
    Mod64::set_mod(n);
    uint64_t d;
    Mod64 one{1};
    for(Mod64 c{one};; c += one) {
      Mod64 x{2}, y{2};
      do {
        x = x * x + c;
        y = y * y + c;
        y = y * y + c;
        d = __gcd((x - y).get(), n);
      } while(d == 1);
      if(d < n) return d;
    }
    assert(0);
  }

  vector< uint64_t > prime_factor(uint64_t n) {
    if(n <= 1) return {};
    uint64_t p = pollard_rho(n);
    if(p == n) return {p};
    auto l = prime_factor(p);
    auto r = prime_factor(n / p);
    copy(begin(r), end(r), back_inserter(l));
    return l;
  }
};
template< int mod >
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

  friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) += rhs;
  }
  friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) -= rhs;
  }
  friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) *= rhs;
  }
  friend ModInt operator/(const ModInt& lhs, const ModInt& rhs) {
        return ModInt(lhs) /= rhs;
  }

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
using modint = ModInt< MOD9 >;modint pow(ll n, ll x){return modint(n).pow(x);}modint pow(modint n, ll x){return n.pow(x);}
//using modint=ld;
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>a(n);
  vector<ll>c(n);
  vector<ll>b(n);
  map<ll,ll>mp;
  vector<ll>v3,v4;
  for(ll i=0;i*i*i<=2*INF+5;i++){
    v3.PB(i*i*i);
  }
  for(ll i=0;i*i*i*i<=2*INF+5;i++){
    v4.PB(i*i*i*i);
  }
  auto ch=[&](ll i,ll d){
    if(d<=1)return;
    while(c[i]%d==0){
      b[i]++;
      c[i]/=d;
      mp[d]++;
    }
  };
  rep(i,0,n){
    cin>>a[i];
    c[i]=a[i];
    ll t=lower_bound(ALL(v4),a[i])-v4.begin();
    ch(i,t);
    ll ok=2e9,ng=1;
    while(ok-ng>=2){
      ll mid=(ok+ng)/2;
      if(mid*mid>=a[i])ok=mid;
      else ng=mid;
    }
    ch(i,ok);
    t=lower_bound(ALL(v3),a[i])-v3.begin();
    ch(i,t);
  }
  //debug(c,n);
  rep(i,0,n)rep(j,i+1,n){
    if(a[i]==a[j])continue;
    ll g=gcd(a[i],a[j]);
    ch(i,g);
    ch(j,g);
  }
  map<ll,ll>cnt;
  modint ret=1;
  rep(i,0,n){
    if(b[i]==0){
      cnt[a[i]]++;
      ll k=cnt[a[i]];
      ret=ret*(k+1)*(k+1)/k/k;
    }
    else if(c[i]!=1)mp[c[i]]++;
  }
  //debug(c,n);
  for(auto z:mp)ret*=z.se+1;
  cout<<ret<<endl;
  return 0;
}
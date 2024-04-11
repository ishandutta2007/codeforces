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
constexpr ll MOD1 = 1e9+7;
constexpr ll MOD9 = 998244353;
constexpr ll INF = 1e18;
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
void debug(vector<T>v,ll n){if(n!=0)cout<<v[0];
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
//0-indexed
template<typename T>
map<T,ll> compress(vector<T> &t){
  sort(ALL(t));
  t.erase(unique(ALL(t)),t.end());
  map<T, ll> ret;
  for(ll i=0;i<(ll)t.size();i++)
    ret[t[i]]=i;
  return ret;
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
using modint = ModInt< MOD1 >;
//using modint = ld;
modint pow2(int64_t n, int64_t x){
    return modint(n).pow(x);
}
vector<modint>twoinv(300005);
template<typename T>
struct SegmentTree{
  using F = function<T(T,T)>;
  vector<T> data;//,,>><<
  ll n,lastlen = 1;
  T func(T a, T b){
    return {
      a[0]+b[0]+a[3]*b[2]*twoinv[2],
      a[1]+b[1],
      b[2]*twoinv[a[1].x]+a[2],
      b[3]+a[3]*twoinv[b[1].x]
    };
  };
  bool check (T a, T b){return 1;};
  T iden = {0,0,0,0}; //
  SegmentTree(vector<T> &v){
    build(v);
  }
  SegmentTree(ll size){
    build(vector<T>(size, iden));
  }
  void build(vector<T> v){
    n = (ll)v.size();
    while(lastlen < n)lastlen *= 2;
    data.assign(lastlen*2-1,iden);
    for(ll i=0;i<n;i++)data[i+lastlen-1] = v[i];
    for(ll i=lastlen-2;i>=0;i--){
      data[i] = func(data[2*i+1], data[2*i+2]);
    }
  }
  
  void update(ll point, T x){
    point+=lastlen-1;
    data[point] = x;
    while(point!=0){
      point=(point-1)/2;
      data[point]=func(data[2*point+1],data[2*point+2]);
    }
  }
  T query(ll l,ll r){
    T left = iden, right = iden;
    l+=lastlen-1, r+=lastlen-1;
    while(l != r){
      if(~l&1)left = func(left, data[l++]);
      if(~r&1)right = func(data[--r], right);
      l >>= 1,r >>= 1;
    }
    return func(left, right);
  }
  T operator[](ll x){
    return data[lastlen-1+x];
  }
  void print(){
    for(ll i=0;i<n;i++){
      if(i!=0)cout<<" ";
      cout<<data[lastlen-1+i];
    }
    cout<<endl;
  }
  T lower_bound(ll p,T x){
    ll sumbuf=iden, l=p,r=p+1;
    p = p + lastlen - 1;
    while(1){
      if(!check(func(sumbuf,data[p]), x)){
        if(p%2==1){
          p = (p-1)/2;
          r = l + (r-l)*2;
        }
        else if(r>=n){
          return n;
        }
        else{
          func(sumbuf,data[p]);
          p >>= 1;
          ll x = r + (r-l)*2; 
          l = r; r = x;
        }
      }
      else if(p >= lastlen - 1)return r - 1;
      else if(!check(func(sumbuf,data[2*p+1]),x)){
        sumbuf = func(sumbuf, data[2*p+1]);
        p = 2*p+2; l = (r+l)/2;
      }
      else{
        p = 2*p+1; r = (r+l)/2;
      }
    }  
  }
};

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  using MMP=array<modint,4>;
  vector<ll>val;
  vector<ll>p(n);
  rep(i,0,n){
    cin>>p[i];
    val.PB(p[i]);
  }
  ll q;cin>>q;
  vector<ll>pos(q),x(q);
  rep(i,0,q){
    cin>>pos[i]>>x[i];pos[i]--;
    val.PB(x[i]);
  }
  auto mp=compress(val);
  ll sz=mp.size();
  //debug(val,sz);
  vector<ll>cnt(sz);
  vector<MMP>tmp(sz);
  rep(i,0,n){
    cnt[mp[p[i]]]++;
  }
  vector<modint>two(n+2);
  modint tmp2=1;
  rep(i,0,n+1){
    two[i+1]=two[i]+tmp2;
    tmp2/=2;
  }
  twoinv[0]=1;
  rep(i,0,n+2)twoinv[i+1]=twoinv[i]/2;
  vector<modint>trans(n+2);
  rep(i,2,n+2){
    trans[i]=trans[i-1]+two[i-1]*twoinv[2];
  }
  //debug(trans,n+2);
  rep(i,0,sz){
    tmp[i]={
      trans[cnt[i]]*val[i]*val[i],
      cnt[i],
      two[cnt[i]]*val[i],
      two[cnt[i]]*val[i]
    };
    //debug(tmp[i],4);
  }
  SegmentTree<MMP>seg(tmp);
  //for(auto z:seg.data)debug(z,4);
  //auto v=seg.query(0,sz);debug(v,4);
  cout<<seg.query(0,sz)[0]<<endl;
  rep(i,0,q){
    ll l=mp[p[pos[i]]];
    ll r=mp[x[i]];
    cnt[l]--;cnt[r]++;p[pos[i]]=x[i];
    seg.update(l,{
      trans[cnt[l]]*val[l]*val[l],
      cnt[l],
      two[cnt[l]]*val[l],
      two[cnt[l]]*val[l]
    });
    swap(l,r);
    seg.update(l,{
      trans[cnt[l]]*val[l]*val[l],
      cnt[l],
      two[cnt[l]]*val[l],
      two[cnt[l]]*val[l]
    });
    cout<<seg.query(0,sz)[0]<<endl;
    //debug(p,n);
  }
  return 0;
}
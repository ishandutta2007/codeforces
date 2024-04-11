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
template<typename T>void rearrange(vector<ll>&ord, vector<T>&v){
  auto tmp = v;
  for(int i=0;i<tmp.size();i++)v[i] = tmp[ord[i]];
}
template<typename Head, typename... Tail>void rearrange(vector<ll>&ord,Head&& head, Tail&&... tail){
  rearrange(ord, head);
  rearrange(ord, tail...);
}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
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
template<typename T>
struct UnionFind {
  vector<ll> data;
  vector<T>v;
  ll num;
  void merge(ll x, ll y){
    v[x] = MP(min(v[x].fi,v[y].fi),max(v[x].se,v[y].se));
  }
  void set(ll i,T x){
    v[i] = x;
  }
  UnionFind(ll size) : data(size, -1) ,num(size),v(size){ }
  bool unite(ll x, ll y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
      merge(x, y);
	    num--;
    }
    return x != y;
  }
  bool find(ll x, ll y) {
    return root(x) == root(y);
  }
  ll root(ll x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  ll size(ll x) {
    return -data[root(x)];
  }
  T& val(ll x){
    return v[root(x)];
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  vector<ll>c(m);
  rep(i,0,m)cin>>c[i],c[i]--;
  UnionFind<P> uf(m);
  rep(i,0,m)uf.set(i,MP(i,i+1));
  vector<vector<modint>>dp(m);
  vector<vector<ll>>idx(n);
  rep(i,0,m)idx[c[i]].PB(i);
  rrep(i,0,n){
    for(auto z:idx[i]){
      dp[z].assign(2,0);
      dp[z][1]=1;
    }
    auto merge=[&](ll x,ll y){
      //cout<<x spa y<<endl;
      //x<-y
      vector<modint>ndp(dp[x].size()+dp[y].size()-1);
      vector<modint>cum=dp[y];
      rrep(i,1,dp[y].size())cum[i-1]+=cum[i];
      rep(i,0,dp[x].size())rep(j,0,cum.size()){
        ndp[i+j]+=dp[x][i]*cum[j];
      }
      return ndp;
    };
    auto allmerge=[&](ll x,ll y){
      //cout<<x spa y<<endl;
      vector<modint>ndp(dp[x].size());
      //debug(dp[x],dp[x].size());
      //debug(dp[y],dp[y].size());
      rep(i,0,dp[x].size())rep(j,0,dp[y].size()){
        ndp[i]+=dp[x][i]*dp[y][j];
      }
      //debug(ndp,dp[x].size());
      return ndp;
    };
    //cout<<idx[i][0] spa idx[i].back() spa uf.find(idx[i][0],idx[i].back())<<endl;
    while(!uf.find(idx[i][0],idx[i].back())){
      ll nxt=uf.val(idx[i][0]).se;
      if(c[nxt]<i){
        cout<<0<<endl;
        return 0;
      }
      ll rx=uf.root(idx[i][0]);
      ll ry=uf.root(nxt);
      uf.unite(rx,ry);
      dp[uf.root(rx)]=allmerge(rx,ry);
    }
    for(auto j:{idx[i][0]-1,idx[i].back()+1}){
      //cout<<i spa j<<endl;
      if(j<0||j>=m||c[j]<i)continue;
      ll rx=uf.root(idx[i][0]);
      ll ry=uf.root(j);
      uf.unite(rx,ry);
      //cout<<i spa j spa dp[rx].size() spa dp[ry].size()<<endl;
      //cout<<i spa idx[i][0] spa j<<endl;
      dp[uf.root(rx)]=merge(rx,ry);
    }
  }
  modint ret=0;
  ll r=uf.root(0);
  rep(i,0,dp[r].size())ret+=dp[r][i];
  cout<<ret<<endl;
  return 0;
}
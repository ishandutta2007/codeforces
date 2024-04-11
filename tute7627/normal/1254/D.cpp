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
struct BIT{
  ll n;
  ll k=1;
  vector<T>data;
  BIT() = default;
  BIT(ll size):n(size){
    n++;
    data.assign(n,0);
    while(k*2<=n)k*=2;
  }
  void add(ll a,T w){
    for(ll i=a+1;i<=n;i+=i&-i)data[i-1]+=w;
  }
  void add(ll l,ll r,T w){
    add(l,w);add(r+1,-w);
  }
  T sum(ll a){
	  if(a<0)return 0;
    T ret = 0;
    for(ll i=a+1;i>0;i-=i&-i)ret+=data[i-1];
    return ret;
  }
  T sum(ll a,ll b){return a>b?0:sum(b)-sum(a-1);}
  T operator[](ll pos){
    return sum(pos,pos);
  }
  ll lower_bound(ll x){
    ll ret=0;    
    for(ll i=k;i>0;i/=2){
      if(ret+i<=n&&data[ret+i-1]<x){
        x-=data[ret+i-1];
        ret+=i;
      }
    }
    return ret;
  }
  void print(){
    for(ll i=0;i<n;i++){
      if(i!=0)cout<<" ";
      cout<<sum(i);
    }
    cout<<endl;
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
  ll n,q;cin>>n>>q;
  const ll sq=900;
  //const ll sq=3;cout<<"naosu"<<endl;
  vector<vector<ll>>g(n);
  vector<ll>multi;//sq
  vector<ll>num(n);//d
  rep(i,0,n-1){
    ll u,v;cin>>u>>v;u--;v--;
    g[u].PB(v);
    g[v].PB(u);
  }
  rep(i,0,n){
    if(g[i].size()>=sq)multi.PB(i);
  }
  vector<ll>sz(n,1),in(n),out(n);
  {
    ll time=0;
    auto dfs=[&](auto &&f,ll k,ll par)->void{
      in[k]=time++;
      for(auto to:g[k]){
        if(to==par)continue;
        f(f,to,k);
        sz[k]+=sz[to];
      }
      out[k]=time;
    };
    dfs(dfs,0,-1);
  }
  vector<vector<int>>szz(n);
  {
    for(auto z:multi){
      szz[z].assign(n,1);
      auto dfs1=[&](auto &&f,ll k,ll par)->void{
        for(auto to:g[k]){
          if(to==par)continue;
          f(f,to,k);
          szz[z][k]+=szz[z][to];
        }
      };
      auto dfs2=[&](auto &&f,ll k,ll par)->void{
        for(auto to:g[k]){
          if(to==par)continue;
          chmax(szz[z][to],szz[z][k]);
          f(f,to,k);
        }
      };
      dfs1(dfs1,z,-1);
      szz[z][z]=0;
      dfs2(dfs2,z,-1);
    }
  }
  //vr
  auto subsz=[&](ll v,ll r){
    //cout<<v spa r spa szz[v][r]<<endl;;
    //assert(szz[v].size()>r);
    return szz[v][r];
  };
  BIT<modint>bit(n);
  vector<modint>inv(n+1,1);
  rep(i,1,n+1)inv[i]/=i;
  ll add=0;
  while(q--){
    ll type;cin>>type;
    if(type==1){
      ll v,d;cin>>v>>d;v--;
      add+=d;
      if(g[v].size()>=sq){
        num[v]+=d;
        continue;
      }
      for(auto to:g[v]){
        modint sub=inv[n];
        if(in[to]<=in[v]&&in[v]<out[to]){
          sub*=n-sz[v];
          bit.add(0,n-1,d*sub);
          bit.add(in[v],out[v]-1,-d*sub);
        }
        else{
          sub*=sz[to];
          bit.add(in[to],out[to]-1,d*sub);
        }
      }
    }
    else{
      ll v;cin>>v;v--;
      modint ret=add;
      ret-=bit.sum(0,in[v]);
      for(auto z:multi){
        //cout<<z spa v<<endl;
        //cout<<"sub "<<subsz(z,v)<<endl;
        modint sub=subsz(z,v)*inv[n];
        ret-=num[z]*sub;
      }
      cout<<ret<<endl;
    }
    //bit.print();
  }
  return 0;
}
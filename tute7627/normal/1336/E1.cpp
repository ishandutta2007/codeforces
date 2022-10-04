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
const ll MAX_W=40;
struct BitMatrix {
  ll h,w;
  vector<bitset<MAX_W>>A;
  BitMatrix() {};
  BitMatrix(ll n, ll m) :h(n),w(m){
    A.assign(h,bitset<MAX_W>(0));
  };
  BitMatrix(vector<vector<ll>>v):h(v.size()),w(v[0].size()){
    A.assign(h,bitset<MAX_W>(0));
    for(ll i=0;i<h;i++)for(ll j=0;j<w;j++)A[i][j]=(v[i][j]&1);  
  }
  ll height() {
    return h;
  }

  ll width() {
    return w;
  }

  inline bitset<MAX_W> &operator[](ll k) {
    return A[k];
  }
  friend ostream &operator<<(ostream &os, BitMatrix &p) {
    ll n = p.height(), m = p.width();
    for(ll i = 0; i < n; i++) {
      os << "[";
      for(ll j = 0; j < m; j++) {
        os << p[i][j] << (j + 1 == m ? "]\n" : ",");
      }
    }
    return (os);
  }
};

ll sweep(BitMatrix &a, bool is_extended){
  ll h = a.height(), w = a.width();
  ll rank = 0;
  ll limit = w - is_extended;
  for(ll col=limit-1;col>=0;col--){
    ll pivot = -1;
    for(ll row=rank;row<h;row++){
      if(a[row][col]){
        pivot=row;
        break;
      }
    }
    if(pivot==-1)continue;
    auto tmp=a[pivot][col];
    swap(a[pivot],a[rank]);
    for(ll row=0;row<h;row++){
      if(row!=rank&&a[row][col]!=0){
        a[row]^=a[rank];
      }  
    }
    rank++;
  }
  return rank;
}
vector<bool>linear_equation(BitMatrix a){
  ll h=a.height(),w=a.width();
  ll rank = sweep(a,true);
  vector<bool>ret;
  for(ll row=rank;row<h;row++)if(a[row][w-1])return ret;
  ret.assign(w-1,0);
  for(ll i=0;i<rank;i++)ret[i]=a[i][w-1];
}

vector<vector<bool>>kernel(BitMatrix a){
  ll h=a.height(),w=a.width();
  ll rank = sweep(a,true);
  vector<ll>cols(w-1,0),piv;
  for(ll i=0;i<h;i++)for(ll j=0;j<w-1;j++){
    if(a[i][j]==1){
      cols[j]=1;
      piv.push_back(j);
      break;
    }
  }
  vector<vector<bool>>ret;
  for(ll i=0;i<w-1;i++){
    if(cols[i])continue;
    vector<bool>v(w-1);
    v[i]=true;
    for(ll j=0;j<piv.size();j++)v[piv[j]]=a[j][i];
    ret.push_back(v);
  }
  return ret;
}  
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
using modint = ModInt< MOD9 >;modint pow(ll n, ll x){return modint(n).pow(x);}modint pow(modint n, ll x){return n.pow(x);}
//using modint=ld;
template <typename T>
void fwt(vector<T>& f) {
    int n = f.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                T x = f[j], y = f[j | i];
                f[j] = x + y, f[j | i] = x - y;
            }
        }
    }
}
template <typename T>
void ifwt(vector<T>& f) {
    int n = f.size();
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                T x = f[j], y = f[j | i];
                f[j] = (x + y) / 2, f[j | i] = (x - y) / 2;
            }
        }
    }
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m;cin>>n>>m;
  BitMatrix mat(n,MAX_W);
  vector<ll>a(n);
  rep(i,0,n){
    cin>>a[i];
    mat[i]=a[i];
  }
  ll rank=sweep(mat,false);
  ll mid=min(rank,20LL);
  ll b=17;
  auto cnt1=vec(20,1<<b,modint(0));
  vector<modint>cnt2(1<<b,0);
  rep(i,0,1LL<<mid){
    ll tmp=0;
    rep(j,0,mid)if(i&1LL<<j){
      tmp^=mat[j].to_ullong();
    }
    ll num=0,bitnum=0;
    rep(j,0,m){
      if(j<b)num^=(tmp&1LL<<j);
      else if(tmp&1LL<<j)bitnum++;
    }
    //cout<<mid spa bitnum spa num<<endl;
    cnt1[bitnum][num]+=1;
  }
  ll dif=rank-mid;
  //cout<<mat<<endl;
  //rep(i,0,rank)cout<<mat[i].to_ullong()<<endl;
  rep(i,0,1LL<<dif){
    ll k=0;
    rep(j,0,dif){
      if(i&1<<j)k^=mat[mid+j].to_ullong();
    }
    cnt2[k]+=1;
  }
  modint p2=pow(2LL,n-rank);
  rep(i,0,1<<b)cnt2[i]*=p2;
   //debug(cnt2,1<<m);
  fwt(cnt2);
  vector<modint>ret(m+1);
  rep(i,0,20){
    //debug(cnt1[i],1<<m);
    fwt(cnt1[i]);
    rep(j,0,1<<b)cnt1[i][j]*=cnt2[j];
    ifwt(cnt1[i]);
    //debug(cnt1[i],1<<m);
    rep(j,0,1<<b){
      ll k=__builtin_popcountll(j)+i;
      if(k>m)continue;
      ret[k]+=cnt1[i][j];
    }
  }
  debug(ret,m+1);
  return 0;
}
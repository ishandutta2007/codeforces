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
const ll MAX_W=500;
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
  static BitMatrix I(size_t n) {
    BitMatrix mat(n,n);
    for(int i = 0; i < n; i++) mat[i][i] = 1;
    return (mat);
  }
  inline bitset<MAX_W> &operator[](ll k) {
    return A[k];
  }
  inline bitset<MAX_W> operator[](ll k) const{
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
  BitMatrix &operator*=(const BitMatrix &B){
    BitMatrix C(h,B.w);
    for(int i = 0; i < h; i++){
      for(int j = 0; j < w; j++){
        if(this->A[i][j])C[i] |= B[j];
      }
    }
    A.swap(C.A);
    return (*this);
  }
  BitMatrix operator*(BitMatrix &B) const {
    return (BitMatrix(*this) *= B);
  }
  BitMatrix &operator^=(long long k) {
    BitMatrix B = BitMatrix::I(height());
    while(k > 0) {
      if(k & 1) B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return (*this);
  }
  BitMatrix operator^(const long long k) const {
    return (BitMatrix(*this) ^= k);
  }

};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  ll m;cin>>m;
  ll sz=61;
  auto mat=vec(sz,2,BitMatrix(n,n));
  rep(i,0,m){
    ll u,v,t;cin>>u>>v>>t;u--;v--;
    mat[0][t][u][v]=1;
  } 
  rep(i,0,sz-1){
    rep(j,0,2){
      mat[i+1][j]=mat[i][j]*mat[i][j^1];
    }
  }
  BitMatrix now=BitMatrix::I(n);
  rep(i,0,n)now[i][i]=1;
  ll cnt=0;
  ll bit=0;
  rrep(i,0,sz){
    auto tmp=now*mat[i][bit];
    if(tmp[0]!=0){
      now=tmp;
      cnt+=1LL<<i;
      bit^=1;
    }
  }
  ans(cnt>INF,-1,cnt);
  return 0;
}
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
template<long long iden, long long size>
struct Trie{
  struct Node{
    vector<ll>next,idx;
    ll num, failure, len;
    Node(ll l):num(0), failure(-1), len(l){
       next.assign(size,-1);
    }
  };
  vector<Node>data;
  Trie(){
    data.emplace_back(0);
  }
  void add(const string &s, ll id){
    ll pos=0;
    for(ll i=0;i<s.size();i++){
      ll c = s[i] - iden;
      if(data[pos].next[c]==-1){
        data[pos].next[c]=data.size();
        data.emplace_back(i+1);
      }
      data[pos].num++;
      pos = data[pos].next[c];
    }
    data[pos].num++;
    data[pos].idx.push_back(id);
  }
  void search(const string &s){
    ll pos=0;
    for(ll i=0;i<s.size();i++){
      ll c = s[i] - iden;
      if(data[pos].next[c]==-1)break;
      pos = data[pos].next[c];
    }
  }
  vector<ll>v;
  void dfs(ll pos, ll d){
    for(ll i=0;i<size;i++){
      if(data[pos].next[i]!=-1){
        dfs(data[pos].next[i], d+1);
      }
    }
  }
  void build_Ahocorasick(){
    queue<ll>que;
    que.push(0);
    data[0].failure = -1;
    while(!que.empty()){
      ll pos = que.front();
      for(ll i=0;i<size;i++){
        if(data[pos].next[i]==-1)continue;
        ll now = data[pos].failure;
        while(now!=-1&&data[now].next[i]==-1)now = data[now].failure;
        if(now==-1)data[data[pos].next[i]].failure = 0;
        else data[data[pos].next[i]].failure = data[now].next[i];
        que.push(data[pos].next[i]);
      }
      que.pop();
    }
  }
  vector<ll> aho_search(const string &s){
    ll now=0;
    vector<ll>cnt(data.size());
    for(ll i=0;i<s.size();i++){
      ll c = s[i] - iden;
      while(now!=-1&&data[now].next[c]==-1)now=data[now].failure;
      if(now==-1)now=0;
      else{
        now=data[now].next[c];
        ll pos=now;
        while(pos!=-1){
          cnt[pos]++;
          pos=data[pos].failure;
        }
      }
    }
    return cnt;
  }
};
using trie = Trie<'a',26>;
template< class T , int maxsize>
struct SquareMatrix {
  using arr = array <T, maxsize>;
  using sqmat = array <arr, maxsize>;
  sqmat A;
  ll n;
  static const T iden = 0;
  static const T zero = -INF;
  const T add(T x, T y){
    return max(x,y);
  }
  const T mul(T x, T y){
    return x+y;
  }
  sqmat zeros(){
    sqmat mat;
    for(ll i=0;i<maxsize;i++)for(ll j=0;j<maxsize;j++)mat[i][j]=zero;
    return mat;
  }
  SquareMatrix() {
    n = maxsize;
    A = zeros();
  }
  SquareMatrix(size_t N) : n(N){
    A = zeros();
  };
  SquareMatrix(vector<vector<T>>v):n(v.size()){
    for(ll i=0;i<n;i++)for(ll j=0;j<n;j++)A[i][j]=v[i][j];
  };
  inline const arr &operator[](int k) const {
    return (A[k]);
  }

  inline arr &operator[](int k) {
    return (A[k]);
  }
  static SquareMatrix I(size_t N){
    SquareMatrix mat(N);
    for(int i = 0; i < N; i++) mat[i][i] = mat.iden;
    return (mat);
  }
  SquareMatrix &operator+=(const SquareMatrix &B) {
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        (*this)[i][j] = add((*this)[i][j], B[i][j]);
    return (*this);
  }

  SquareMatrix &operator*=(const SquareMatrix &B) {
    sqmat C = zeros();
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        for(int k = 0; k < n; k++)
          C[i][j] = add(C[i][j],mul((*this)[i][k] , B[k][j]));
    A.swap(C);
    return (*this);
  }
  SquareMatrix &operator^=(long long k) {
    SquareMatrix B = SquareMatrix::I(n);
    while(k > 0) {
      if(k & 1) B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return (*this);
  }

  SquareMatrix operator+(const SquareMatrix &B) const {
    return (SquareMatrix(*this) += B);
  }

  SquareMatrix operator*(const SquareMatrix &B) const {
    return (SquareMatrix(*this) *= B);
  }

  SquareMatrix operator^(const long long k) const {
    return (SquareMatrix(*this) ^= k);
  }

  friend ostream &operator<<(ostream &os, SquareMatrix p) {
    for(int i = 0; i < p.n; i++) {
      os << "[";
      for(int j = 0; j < p.n; j++) {
        os << p[i][j] << (j + 1 == p.n ? "]\n" : ",");
      }
    }
    return (os);
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll sz=202;
  using SQ=SquareMatrix<ll,203>;
  trie tri;
  ll n,l;cin>>n>>l;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  vector<string>s(n);
  rep(i,0,n){
    cin>>s[i];
    tri.add(s[i],0);
  }
  tri.build_Ahocorasick();
  vector<ll>b(sz);
  {
    string t;
    auto &tr=tri.data;
    auto dfs=[&](auto &&f,ll pos)->void{
      rep(i,0,n){
        if(t.size()>=s[i].size()&&t.substr((ll)t.size()-(ll)s[i].size())==s[i])b[pos]+=a[i];
      }
      //cout<<t spa b[pos]<<endl;
      rep(i,0,26){
        if(tr[pos].next[i]==-1)continue;
        t+=i+'a';
        f(f,tr[pos].next[i]);
        t.pop_back();
      }
    };
    //cout<<tr.size()<<endl;
    dfs(dfs,0);
  }
  SQ mat=SQ::I(sz);
  {
    auto &tr=tri.data;
    auto dfs=[&](auto &&f,ll pos)->void{
      ll now=pos;
      while(1){
        rep(i,0,26){
          if(tr[now].next[i]==-1)continue;
          mat[pos][tr[now].next[i]]=b[tr[now].next[i]];
        }
        if(now==0)break;
        now=tr[now].failure;
      }
      rep(i,0,26){
        if(tr[pos].next[i]==-1)continue;
        f(f,tr[pos].next[i]);
      }
    };
    dfs(dfs,0);
  }
  //debug(b,sz);
  //cout<<mat<<endl;
  mat^=l;
  //cout<<mat<<endl;
  rep(i,0,sz)chmax(res,mat[0][i]);
  cout<<res<<endl;
  return 0;
}
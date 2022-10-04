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
template<typename T> using PQ = priority_queue<T>;
template<typename T> using QP = priority_queue<T,vector<T>,greater<T>>;
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>void debug(const T &v,ll h,ll w,string sv=" "){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout<<sv<<v[i][j];cout<<endl;}};
template<typename T>void debug(const T &v,ll n,string sv=" "){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout<<sv<<v[i];cout<<endl;};
template<typename T>vector<vector<T>>vec(ll x, ll y, T w){vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<typename T1, typename T2>ostream &operator<<(ostream &os, const pair<T1, T2>&p){return os << p.first << " " << p.second;}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v){for(auto &z:v)os << z << " ";cout<<"|"; return os;}
template<typename T>void rearrange(vector<int>&ord, vector<T>&v){
  auto tmp = v;
  for(int i=0;i<tmp.size();i++)v[i] = tmp[ord[i]];
}
template<typename Head, typename... Tail>void rearrange(vector<int>&ord,Head&& head, Tail&&... tail){
  rearrange(ord, head);
  rearrange(ord, tail...);
}
template<typename T> vector<int> ascend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return v[i]<v[j];});
  return ord;
}
template<typename T> vector<int> descend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return v[i]>v[j];});
  return ord;
}
ll FLOOR(ll n,ll div){return n>=0?n/div:(n-div+1)/div;}
ll CEIL(ll n,ll div){return n>=0?(n+div-1)/div:n/div;}
template<typename T>T min(const vector<T>&v){return *min_element(v.begin(),v.end());}
template<typename T>T max(const vector<T>&v){return *max_element(v.begin(),v.end());}
template<typename T>T reverse(const T &v){return T(v.rbegin(),v.rend());};
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
template<typename T>T poll(queue<T> &q){auto ret=q.front();q.pop();return ret;};
template<typename T>T poll(priority_queue<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(QP<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(stack<T> &s){auto ret=s.top();s.pop();return ret;};
template< typename T = int >
struct edge {
  int to;
  T cost;
  int id;
  edge() = default;
  edge(int to, T cost = 1, int id = -1):to(to), cost(cost), id(id){}
  operator int() const { return to; }
};

template<typename T>
using Graph = vector<vector<edge<T>>>;
template<typename T>
Graph<T> readGraph(int n,int m,int indexed=1,bool directed=false,bool weighted=false){
  Graph<T> ret(n);
  for(int es = 0; es < m; es++){
    int u,v,w=1;
    cin>>u>>v;u-=indexed,v-=indexed;
    if(weighted)cin>>w;
    ret[u].emplace_back(v,w,es);
    if(!directed)ret[v].emplace_back(u,w,es);
  }
  return ret;
}
template<typename T>
Graph<T> readParent(int n,int indexed=1,bool directed=true){
  Graph<T>ret(n);
  for(int i=1;i<n;i++){
    int p;cin>>p;
    p-=indexed;
    ret[p].emplace_back(i);
    if(!directed)ret[i].emplace_back(p);
  }
  return ret;
}
struct SuccinctIndexableDictionary {
  size_t length;
  size_t blocks;
  vector< unsigned > bit, sum;

  SuccinctIndexableDictionary() {
  }

  SuccinctIndexableDictionary(size_t _length) {
    length = _length;
    blocks = (length + 31) >> 5;
    bit.assign(blocks, 0U);
    sum.assign(blocks, 0U);
  }

  void set(int k) {
    bit[k >> 5] |= 1U << (k & 31);
  }

  void build() {
    sum[0] = 0U;
    for(int i = 1; i < blocks; i++) {
      sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);
    }
  }

  bool operator[](int k) const {
    return (bool((bit[k >> 5] >> (k & 31)) & 1));
  }

  int rank(int k) {
    return (sum[k >> 5] + __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));
  }

  int rank(bool val, int k) {
    return (val ? rank(k) : k - rank(k));
  }

  int select(bool val, int k) {
    if(k < 0 || rank(val, length) <= k) return (-1);
    int low = 0, high = length;
    while(high - low > 1) {
      int mid = (low + high) >> 1;
      if(rank(val, mid) >= k + 1) high = mid;
      else low = mid;
    }
    return (high - 1);
  }

  int select(bool val, int i, int l) {
    return select(val, i + rank(val, l));
  }
};

template< class T, int MAXLOG >
struct WaveletMatrix {
  size_t length;
  SuccinctIndexableDictionary matrix[MAXLOG];
  int zs[MAXLOG];
  int buff1[MAXLOG], buff2[MAXLOG];

  int freq_dfs(int d, int l, int r, T val, T a, T b) {
    if(l == r) return 0;
    if(d == MAXLOG) return (a <= val && val < b) ? r - l : 0;
    T nv = 1ULL << (MAXLOG - d - 1) | val, nnv = ((1ULL << (MAXLOG - d - 1)) - 1) | nv;
    if(nnv < a || b <= val) return 0;
    if(a <= val && nnv < b) return r - l;
    int lc = matrix[d].rank(1, l), rc = matrix[d].rank(1, r);
    return freq_dfs(d + 1, l - lc, r - rc, val, a, b) +
           freq_dfs(d + 1, lc + zs[d], rc + zs[d], nv, a, b);
  }

  WaveletMatrix(vector< T > data) {
    length = data.size();
    vector< T > l(length), r(length);
    for(int depth = 0; depth < MAXLOG; depth++) {
      matrix[depth] = SuccinctIndexableDictionary(length + 1);
      int left = 0, right = 0;
      for(int i = 0; i < length; i++) {
        bool k = (data[i] >> (MAXLOG - depth - 1)) & 1;
        if(k) r[right++] = data[i], matrix[depth].set(i);
        else l[left++] = data[i];
      }
      zs[depth] = left;
      matrix[depth].build();
      swap(l, data);
      for(int i = 0; i < right; i++) data[left + i] = r[i];
    }
  }

  T access(int k) {
    int ret = 0;
    bool bit;
    for(int depth = 0; depth < MAXLOG; depth++) {
      bit = matrix[depth][k];
      ret = (ret << 1) | bit;
      k = matrix[depth].rank(bit, k) + zs[depth] * bit;
    }
    return (ret);
  }

  int rank(T val, int k) {
    int l = 0, r = k;
    for(int depth = 0; depth < MAXLOG; depth++) {
      buff1[depth] = l, buff2[depth] = r;
      bool bit = (val >> (MAXLOG - depth - 1)) & 1;
      l = matrix[depth].rank(bit, l) + zs[depth] * bit;
      r = matrix[depth].rank(bit, r) + zs[depth] * bit;
    }
    return (r - l);
  }

  int select(T val, int kth) {
    rank(val, length);
    for(int depth = MAXLOG - 1; depth >= 0; depth--) {
      bool bit = (val >> (MAXLOG - depth - 1)) & 1;
      kth = matrix[depth].select(bit, kth, buff1[depth]);
      if(kth >= buff2[depth] || kth < 0) return (-1);
      kth -= buff1[depth];
    }
    return (kth);
  }

  int select(T val, int k, int l) {
    return select(val, k + rank(val, l));
  }

  int quantile(int left, int right, int kth) {
    if(right - left <= kth || kth < 0) return (-1);
    T ret = 0;
    for(int depth = 0; depth < MAXLOG; depth++) {
      int l = matrix[depth].rank(1, left);
      int r = matrix[depth].rank(1, right);
      if(r - l > kth) {
        left = l + zs[depth];
        right = r + zs[depth];
        ret |= 1ULL << (MAXLOG - depth - 1);
      } else {
        kth -= r - l;
        left -= l;
        right -= r;
      }
    }
    return ret;
  }
  
  int rangefreq(int left, int right, T lower, T upper) {
    return freq_dfs(0, left, right, 0, lower, upper);
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,k;cin>>n>>k;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  vector<vector<ll>>id(100005);
  rep(i,0,n){
    id[a[i]].PB(i);
  }
  vector<ll>v(n,n);
  for(auto &z:id){
    rep(i,0,z.size()){
      if(i+k<z.size())v[z[i]]=z[i+k];
    }
  }
  WaveletMatrix<ll,20> wm(v);
  ll q;cin>>q;
  ll last=0;
  while(q--){
    ll x,y;cin>>x>>y;
    ll l=(x+last)%n,r=(y+last)%n;
    if(l>r)swap(l,r);
    r++;
    last=wm.rangefreq(l,r,r,n+1);
    cout<<last<<endl;
  }
  return 0;
}
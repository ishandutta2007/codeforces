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
struct SuffixArray{
  ll size;
  string str;
  vector<ll>data, rank;
  SuffixArray(string S):size(S.size()),str(S){
    str += '$';//-1,str[i]+input,,kind
    vector<ll>input(str.size());
    for(ll i=0;i<str.size();i++)input[i] = str[i];
    data = induced_sort(input, 200);
    data.erase(data.begin()); data.push_back(size);
    str.pop_back();
    rank.assign(size,0);
    for(ll i=0;i<size;i++){
      rank[data[i]] = i;
    }
  }
  vector<ll> induced_sort(vector<ll>t, ll kind){
    ll sz = t.size();
    vector<bool>ls(sz);//trueL,falseS
    for(ll i = sz-1;i>=0;i--){
      if(i==sz-1)ls[i] = false;
      else{
        if(t[i]!=t[i+1])ls[i] = (t[i] > t[i+1]);
        else ls[i] = ls[i+1];
      }
    }
    vector<ll>cnt(kind);
    for(ll i=0;i<sz;i++)cnt[t[i]]++;
    vector<P>lr(kind,MP(-1,-1));
    for(ll i=1;i<kind;i++){
      if(cnt[i]==0)lr[i] = lr[i-1];
      else lr[i] = make_pair(lr[i-1].se + 1, lr[i-1].se + cnt[i]);
    }
    vector<ll>lmsidx,ret(sz,-1);
    for(ll i=0;i<sz-1;i++){
      if(ls[i]&&!ls[i+1]){
        ret[lr[t[i+1]].fi+cnt[t[i+1]]-1]=i+1;
        cnt[t[i+1]]--;
        lmsidx.push_back(i+1);
      }
    }
    fill(ALL(cnt),0);
    for(ll i=0;i<sz;i++){
      if(ret[i]>=1&&ls[ret[i]-1]){
        ret[lr[t[ret[i]-1]].fi+cnt[t[ret[i]-1]]]=ret[i]-1;
        cnt[t[ret[i]-1]]++;
        if(i!=0&&!ls[ret[i]])ret[i]=-1;
      }
    }
    fill(ALL(cnt),0);
    for(ll i=sz-1;i>=1;i--){
      if(ret[i]>=1&&!ls[ret[i]-1]){
        ret[lr[t[ret[i]-1]].se-cnt[t[ret[i]-1]]]=ret[i]-1;
        cnt[t[ret[i]-1]]++;
      }
    }
    vector<ll>rev_lmsidx(sz,-1),lmsinput(lmsidx.size(),-1);
    for(ll i=0;i<lmsidx.size();i++)rev_lmsidx[lmsidx[i]] = i;
    ll kindnum=1; 
    lmsinput[rev_lmsidx[ret[0]]] = 1;
    vector<ll>comp(t.begin()+ret[0],t.end());
    for(ll i=1;i<sz;i++){
      if(ret[i]>=1&&ls[ret[i]-1]&&!ls[ret[i]]){
        vector<ll>tmp(t.begin()+ret[i],t.begin()+lmsidx[rev_lmsidx[ret[i]]+1]+1); 
        if(comp != tmp){
          kindnum++;
          comp = tmp;
        }
        lmsinput[rev_lmsidx[ret[i]]] = kindnum;
      }
    }
    vector<ll>output;
    if(kindnum==lmsidx.size()){
      output.assign(kindnum,-1);
      for(ll i=0;i<lmsinput.size();i++)output[lmsinput[i]-1]=i;
    }
    else output = induced_sort(lmsinput,kindnum+1);
    
    fill(ALL(cnt),0), fill(ALL(ret),-1);
    for(ll i=output.size()-1;i>=0;i--){
      ll tmp=lmsidx[output[i]];
      ret[lr[t[tmp]].se - cnt[t[tmp]]]=tmp;
      cnt[t[tmp]]++;
    }
    fill(ALL(cnt),0);
    for(ll i=0;i<sz;i++){
      if(ret[i]>=1&&ls[ret[i]-1]){
        ret[lr[t[ret[i]-1]].fi+cnt[t[ret[i]-1]]]=ret[i]-1;
        cnt[t[ret[i]-1]]++;
        if(i!=0&&!ls[ret[i]])ret[i]=-1;
      }
    }
    fill(ALL(cnt),0);
    for(ll i=sz-1;i>=1;i--){
      if(ret[i]>=1&&!ls[ret[i]-1]){
        ret[lr[t[ret[i]-1]].se-cnt[t[ret[i]-1]]]=ret[i]-1;
        cnt[t[ret[i]-1]]++;
      }
    }
    return ret;
  }
  ll operator[](ll x) const {
    return data[x];
  }
  ll lower_bound(string x){
    ll le=-1,ri=str.size();
    while(ri-le>=2){
      ll mid=(le+ri)/2;
      ll cnt=0;
      while(cnt<x.size()&&data[mid]+cnt<str.size()
        &&x[cnt]==str[data[mid]+cnt])cnt++;
      if(cnt==x.size())ri=mid;
      else if(data[mid]+cnt==str.size())le=mid;
      else if(x[cnt]<=str[data[mid]+cnt])ri=mid;
      else le=mid;
    }
    return ri;
  }
  ll upper_bound(string x){
    x.back()++;
    return lower_bound(x);
  }
  vector<ll> lcp(){
    vector<ll>ret(size);
    for(ll i=0,h=0;i<size;i++){
      if(rank[i]==0)continue;
      for(ll j=data[rank[i]-1];max(i,j)+h<size&&str[i+h]==str[j+h];h++);
      ret[rank[i]-1] = h;
      if(h>0) h--;
    }
    return ret;
  }
};
template< typename Monoid ,typename F>
struct SegmentTree {
  int sz, n;
  vector< Monoid > seg;
  const F f;
  const Monoid M1;

  SegmentTree(int n, const F f, const Monoid &M1) : f(f), M1(M1), n(n){
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz, M1);
  }

  void set(int k, const Monoid &x) {
    seg[k + sz] = x;
  }

  void build() {
    for(int k = sz - 1; k > 0; k--) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  void update(int k, const Monoid &x) {
    k += sz;
    seg[k] = x;
    while(k >>= 1) {
      seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }
  }

  Monoid query(int a, int b) {
	  if(a>=b)return M1;
    Monoid L = M1, R = M1;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) L = f(L, seg[a++]);
      if(b & 1) R = f(seg[--b], R);
    }
    return f(L, R);
  }

  Monoid operator[](const int &k) const {
    return seg[k + sz];
  }

  template< typename C >
  int find_subtree(int a, const C &check, Monoid &M, bool type) {
    while(a < sz) {
      Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
      if(check(nxt)) a = 2 * a + type;
      else M = nxt, a = 2 * a + 1 - type;
    }
    return a - sz;
  }
  //[a,x]x,-1
  template< typename C >
  int find_first(int a, const C &check) {
    Monoid L = M1;
    if(a <= 0) {
      if(check(f(L, seg[1]))) return find_subtree(1, check, L, false);
      return -1;
    }
    int b = sz;
    for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
      if(a & 1) {
        Monoid nxt = f(L, seg[a]);
        if(check(nxt)) return find_subtree(a, check, L, false);
        L = nxt;
        ++a;
      }
    }
    return -1;
  }

  template< typename C >
  int find_last(int b, const C &check) {
    Monoid R = M1;
    if(b >= sz) {
      if(check(f(seg[1], R))) return find_subtree(1, check, R, true);
      return -1;
    }
    int a = sz;
    for(b += sz; a < b; a >>= 1, b >>= 1) {
      if(b & 1) {
        Monoid nxt = f(seg[--b], R);
        if(check(nxt)) return find_subtree(b, check, R, true);
        R = nxt;
      }
    }
    return -1;
  }
  void print(){
    for(ll i=0;i<n;i++)if((*this)[i]==M1)cout<<"x ";else cout<<(*this)[i]<<" ";
    cout<<endl;
  }
};
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
  ll n,q;cin>>n>>q;
  string s;
  vector<ll>idx(n),sz(n),group;
  rep(i,0,n){
    string t;cin>>t;
    sz[i]=t.size();
    idx[i]=s.size();
    s+=t+'{';
    rep(_,0,sz[i])group.PB(i);
    group.PB(n+10);
  }
  SuffixArray sa(s);
  auto lcp=sa.lcp();
  ll m=s.size();
  vector<ll>dat(m);
  rep(i,0,m){
    dat[i]=group[sa[i]];
  }
  auto ff=[&](ll x,ll y){return min(x,y);};
  SegmentTree<ll,decltype(ff)>seg(m,ff,LLONG_MAX);
  rep(i,0,m)seg.set(i,lcp[i]);
  seg.build();
  WaveletMatrix<ll,19> mat(dat);
  //debug(dat,m);
  //debug(lcp,m);
  while(q--){
    ll l,r,k;cin>>l>>r>>k;k--;
    auto ch=[&](ll t){return t<sz[k];};
    ll pp=sa.rank[idx[k]];
    ll sl=-1;
    sl=seg.find_last(pp,ch);
    ll sr=seg.find_first(pp,ch);
    sl++;
    if(sr==-1)sr=m;
    //cout<<sl spa sr spa sa.rank[idx[k]] spa k spa sz[k] spa l spa r<<endl;
    ll pre=0;
    if(sl<=sr)pre=mat.rangefreq(sl,sr+1,l-1,r);
    cout<<pre<<endl;
  }
  return 0;
}
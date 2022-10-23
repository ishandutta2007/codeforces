//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lfs cout<<fixed<<setprecision(10)
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define UNIQUE(a) (a).erase(unique((a).begin(),(a).end()),(a).end())
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
template<typename T1,typename T2,typename T3>void anss(T1 x,T2 y,T3 z){ans(x!=y,x,z);};  
template<typename T>void debug(const T &v,ll h,ll w,string sv=" "){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout<<sv<<v[i][j];cout<<endl;}};
template<typename T>void debug(const T &v,ll n,string sv=" "){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout<<sv<<v[i];cout<<endl;};
template<typename T>void debug(const vector<T>&v){debug(v,v.size());}
template<typename T>void debug(const vector<vector<T>>&v){for(auto &vv:v)debug(vv,vv.size());}
template<typename T>void debug(stack<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(queue<T> st){while(!st.empty()){cout<<st.front()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(deque<T> st){while(!st.empty()){cout<<st.front()<<" ";st.pop_front();}cout<<endl;}
template<typename T>void debug(PQ<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(QP<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(const set<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T>void debug(const multiset<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T,size_t size>void debug(const array<T, size> &a){for(auto z:a)cout<<z<<" ";cout<<endl;}
template<typename T,typename V>void debug(const map<T,V>&v){for(auto z:v)cout<<"["<<z.first<<"]="<<z.second<<",";cout<<endl;}
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
  sort(ord.begin(),ord.end(),[&](int i,int j){return make_pair(v[i],i)<make_pair(v[j],j);});
  return ord;
}
template<typename T> vector<int> descend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return make_pair(v[i],-i)>make_pair(v[j],-j);});
  return ord;
}
template<typename T> vector<T> inv_perm(const vector<T>&ord){
  vector<T>inv(ord.size());
  for(int i=0;i<ord.size();i++)inv[ord[i]] = i;
  return inv;
}
ll FLOOR(ll n,ll div){assert(div>0);return n>=0?n/div:(n-div+1)/div;}
ll CEIL(ll n,ll div){assert(div>0);return n>=0?(n+div-1)/div:n/div;}
ll digitsum(ll n){ll ret=0;while(n){ret+=n%10;n/=10;}return ret;}
ll modulo(ll n,ll d){return (n%d+d)%d;};
template<typename T>T min(const vector<T>&v){return *min_element(v.begin(),v.end());}
template<typename T>T max(const vector<T>&v){return *max_element(v.begin(),v.end());}
template<typename T>T acc(const vector<T>&v){return accumulate(v.begin(),v.end(),T(0));};
template<typename T>T reverse(const T &v){return T(v.rbegin(),v.rend());};
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
template<typename T>T poll(queue<T> &q){auto ret=q.front();q.pop();return ret;};
template<typename T>T poll(priority_queue<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(QP<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(stack<T> &s){auto ret=s.top();s.pop();return ret;};
ll MULT(ll x,ll y){if(LLONG_MAX/x<=y)return LLONG_MAX;return x*y;}
ll POW2(ll x, ll k){ll ret=1,mul=x;while(k){if(mul==LLONG_MAX)return LLONG_MAX;if(k&1)ret=MULT(ret,mul);mul=MULT(mul,mul);k>>=1;}return ret;}
ll POW(ll x, ll k){ll ret=1;for(int i=0;i<k;i++){if(LLONG_MAX/x<=ret)return LLONG_MAX;ret*=x;}return ret;}
template< typename T = int >
struct edge {
  int to;
  T cost;
  int id;
  edge():id(-1){};
  edge(int to, T cost = 1, int id = -1):to(to), cost(cost), id(id){}
  operator int() const { return to; }
};

template<typename T>
using Graph = vector<vector<edge<T>>>;
template<typename T>
Graph<T>revgraph(const Graph<T> &g){
  Graph<T>ret(g.size());
  for(int i=0;i<g.size();i++){
    for(auto e:g[i]){
      int to = e.to;
      e.to = i;
      ret[to].push_back(e);
    }
  }
  return ret;
}
template<typename T>
Graph<T> readGraph(int n,int m,int indexed=1,bool directed=false,bool weighted=false){
  Graph<T> ret(n);
  for(int es = 0; es < m; es++){
    int u,v;
    T w=1;
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
vector<ll>divisor_enum(ll n){
  vector<ll>ret;
  for(ll i=1;i*i<=n;i++){
    if(n%i==0){
      if(i*i==n)ret.PB(i);
      else{
        ret.PB(i);
        ret.PB(n/i);
      }
    }
  }
  return ret;
}
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
  //[x,b)x,-1
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
vector<int>divisor_num(int sz){
  vector<int>ret(sz+1);
  for(int i=1;i<=sz;i++){
    for(int j=i;j<=sz;j+=i){
      ret[j]++;
    }
  }
  return ret;
}

//10^61s
vector<vector<int>>divisor_table(int sz){
  vector<vector<int>>ret(sz+1);
  auto dn=divisor_num(sz);
  for(int i=1;i<=sz;i++){
    ret[i].reserve(dn[i]);
  }
  vector<int>idx(sz);
  for(int i=1;i<=sz;i++){
    for(int j=i;j<=sz;j+=i){
      ret[j].push_back(i);
    }
  }
  return ret;
}
namespace range_min{
  using M=ll;
  auto f=[](M x,M y){
    return min(x,y);
  };
  SegmentTree<M,decltype(f)>make(int n){
    return {n,f,INF};
  }
}
//https://noimi.hatenablog.com/entry/2021/05/02/195143
// S :  T : 
template <class S, class T = int> struct IntervalManager {
    struct node {
        T l, r;
        S x;
        node(const T &l, const T &r, const S &x) : l(l), r(r), x(x) {}
        constexpr bool operator<(const node &rhs) const {
            if(l != rhs.l) return l < rhs.l;
            return r < rhs.r;
        }
    };
    const S unit;
    set<node> s;
    IntervalManager(const S &u = S()) : unit(u) {}
    IntervalManager(const vector<T> &a): unit(S()){
        vector<node> setter;
        for(int l = 0; l < a.size(); l++) {
            int r = l;
            for(; r < a.size() and a[l] == a[r]; r++) {}
            setter.emplace_back(l, r, a[l]);
            l = r - 1;
        }
        s = set<node>(setter.begin(),setter.end());
    }
    template<typename ADD>
    void init(const ADD &add){
      for(auto e:s){
        add(e.l, e.r, e.x);
      }
    }
    // x 
    typename set<node>::iterator getIt(const T &x) {
        auto it = s.upper_bound(node(x, numeric_limits<T>::max(), 0));
        if(it == begin(s)) return end(s);
        it = prev(it);
        if(it->l <= x and x < it->r) return it;
        return end(s);
    }

    // x 
    node getSeg(const T &x) {
        auto it = getIt(x);
        if(it != end(s)) return *it;
        return node(x, x + 1, unit);
    }

    // x  iterator 
    typename set<node>::iterator nextIt(const T &x) {
        auto it = s.upper_bound(node(x, numeric_limits<T>::max(), 0));
        if(it == begin(s)) return it;
        return prev(it);
    }

    // x 
    S get(const T &x) {
        auto it = getIt(x);
        if(it != end(s)) return it->x;
        return unit;
    }

    S operator[](T k) const { return get(k); }

    // [l, r) := x  set 
    // ,  [L, r) := x 
    template <typename ADD, typename DEL> void update(T l, T r, const S &x, const ADD &add, const DEL &del) {
        auto it = s.lower_bound(node{l, 0, x});
        while(it != end(s) and it->l <= r) {
            if(it->l == r) {
                if(it->x == x) {

                    del(r, it->r, x);
                    r = it->r, it = s.erase(it);
                }
                break;
            }
            if(it->r <= r) {
                del(it->l, it->r, it->x);
                it = s.erase(it);
            } else {
                if(it->x == x) {
                    r = it->r;
                    del(it->l, it->r, it->x);
                    it = s.erase(it);
                } else {
                    del(it->l, it->r, it->x);
                    node n = *it;
                    it = s.erase(it);
                    add(r, n.r, n.x);
                    it = s.emplace_hint(it, r, n.r, n.x);
                }
            }
        }

        if(it != begin(s)) {
            it = prev(it);
            if(it->r == l) {
                if(it->x == x) {
                    del(it->l, it->r, it->x);
                    l = it->l;
                    it = s.erase(it);
                }
            } else if(l < it->r) {
                if(it->x == x) {
                    del(it->l, it->r, it->x);
                    l = min(l, it->l);
                    r = max(r, it->r);
                    it = s.erase(it);
                } else {
                    if(r < it->r) {
                        add(r, it->r, it->x);
                        it = s.emplace_hint(next(it), r, it->r, it->x);
                        it = prev(it);
                    }
                    del(it->l, it->r,it->x);
                    node n = *it;
                    it = s.erase(it);
                    add(n.l, l, n.x);
                    it = s.emplace_hint(it, n.l, l, n.x);
                }
            }
        }
        if(it != end(s)) it = next(it);
        add(l, r, x);
        s.emplace_hint(it, l, r, x);
    }

    void update(T l, T r, const S &x) {
        update(
            l, r, x, [](T, T, S) {}, [](T, T, S) {});
    }

    void show() {
        for(auto e : s) {
            cerr << "("
                 << "[" << e.l << ", " << e.r << "): " << e.x << ") ";
        }
        cerr << endl;
    }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  int n,q;cin>>n>>q;
  vector<int>a(n),b(n);
  rep(i,0,n){
    cin>>a[i];
  }
  int sz=50005;
  auto dt=divisor_table(sz);
  vector<vector<int>>idx(sz);
  rep(i,0,n){
    cin>>b[i];
    for(auto z:dt[b[i]]){
      //cout<<i spa b[i] spa z<<endl;
      idx[z].push_back(i);
    }
  }
  auto fmin=[&](int x,int y){
    return min(x,y);
  };
  vector<SegmentTree<int,decltype(fmin)>>seg;
  rep(i,0,sz){
    seg.emplace_back(idx[i].size()+1,fmin,INT_MAX);
    rep(j,0,idx[i].size()){
      seg.back().set(j,b[idx[i][j]]);
    }
    seg.back().build();
  }
  //seg[4].print();
  auto get=[&](int av,int l,int r){
    ll ret=INF;
    for(auto z:dt[av]){
      int cl=lower_bound(ALL(idx[z]),l)-idx[z].begin();
      int cr=lower_bound(ALL(idx[z]),r)-idx[z].begin();
      if(cl<cr)chmin(ret,(ll)seg[z].query(cl,cr)*av/((ll)(z)*z));
      //if(av==30&&l==1&&r==9)cout<<ret spa cl spa cr spa idx[z] spa z spa seg[z].query(l,r)<<endl;
    }
    //cout<<av spa l spa r spa ret<<endl;
    return ret;
  };
  auto segim=range_min::make(n);
  IntervalManager<int> im(a);
  for(auto e:im.s){
    segim.set(e.l,get(e.x,e.l,e.r));
  }
  segim.build();
  //segim.print();
  while(q--){
    int type,l,r;cin>>type>>l>>r;l--;
    if(type==1){
      int x;cin>>x;
      auto add=[&](int l,int r,int x){
        segim.update(l,get(x,l,r));
      };
      auto del=[&](int l,int r,int x){
        segim.update(l,segim.M1);
      };
      im.update(l,r,x,add,del);
    }
    else{
      //segim.print();
      auto sl=im.getSeg(l);
      auto sr=im.getSeg(r-1);
      ll ret=INF;
      //im.show();
      //cout<<l spa sl.r spa sr.l spa r<<endl;
      chmin(ret,segim.query(sl.r,sr.l));
      chmin(ret,get(sl.x,l,min(r,sl.r)));
      chmin(ret,get(sr.x,max(l,sr.l),r));
      cout<<ret<<endl;
    }
  }
  return 0;
}
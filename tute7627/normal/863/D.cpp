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
template<typename T>void debug(T &v,ll h,ll w,string sv=" "){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout<<sv<<v[i][j];cout<<endl;}};
template<typename T>void debug(T &v,ll n,string sv=" "){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout<<sv<<v[i];cout<<endl;};
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
template<typename Head, typename... Tail>void rearrange(vector<ll>&ord,Head&& head, Tail&&... tail){
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
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};

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

template<typename Monoid, typename OM>
struct LazyReversibleTreap{
  mt19937 mt;
  struct Node{
    Node* ch[2];
    int pri, sz = 1;
    Monoid val, sum;
    OM lazy;
    bool rev;
    Node(){}
    Node(Monoid val,OM lazy,int pri):val(val),lazy(lazy),sum(val),pri(pri),ch{nullptr, nullptr}{};
  };
  int nxt = 0;
  Monoid M1 = (int)1e9;
  OM OM0 = 0;
  Monoid f(Monoid x, Monoid y){
    return min(x,y);
  }
  Monoid g(Monoid x, OM y){
    return x + y;
  }
  OM h(OM x, OM y){
    return x + y;
  }
  Monoid flip(Monoid x){
    return x;
  }
  LazyReversibleTreap():mt(chrono::steady_clock::now().time_since_epoch().count()){
  }
  LazyReversibleTreap(int x):mt(x){
    cout<<"debug"<<endl;
  }
  int gen(){
    return uniform_int_distribution<int>(0,1<<30)(mt);
  }
  int count(Node *t){return !t ? 0 : t->sz;};
  Monoid sum(Node *t){return !t ? M1 : t->sum;};
  Node* update(Node* t){
    if(!t)return t;
    for(int i=0;i<2;i++)if(t->ch[i])push(t->ch[i]);
    t->sz = count(t->ch[0]) + count(t->ch[1]) + 1;
    t->sum = f(t->val, f(sum(t->ch[0]), sum(t->ch[1])));
    return t;
  }
  void push(Node* t){
    if(t && t->lazy != OM0){
      t->val = g(t->val, t->lazy);
      t->sum = g(t->sum, t->lazy);
      for(int i = 0; i < 2; i++){
        if(t->ch[i])t->ch[i]->lazy = h(t->ch[i]->lazy, t->lazy);
      }
      t->lazy = OM0;
    }
    if(t && t->rev){
      t->rev = false;
      swap(t->ch[0], t->ch[1]);
      t->sum = flip(t->sum);
      if(t->ch[0])t->ch[0]->rev ^= true;
      if(t->ch[1])t->ch[1]->rev ^= true;
    }
  }
  template<typename ... Args>
  Node* merge(Node *l, Args... rest){
    Node *r=merge(rest...);
    push(l);
    push(r);
    if(!l || !r)return !l ? r : l;
    if(l->pri > r->pri){
      l->ch[1] = merge(l->ch[1], r);
      return update(l);
    }
    else{
      r->ch[0] = merge(l, r->ch[0]);
      return update(r);
    }
  }
  Node *merge(Node *l){
    return l;
  }
  using PN = pair<Node*, Node*>;
  PN split(Node* t, int k){ //[0,k),[k,n)
    if(!t) return make_pair(nullptr, nullptr);
    push(t);
    if(k <= count(t->ch[0])){
      PN s = split(t->ch[0], k);
      t->ch[0] = s.second;
      return make_pair(s.first, update(t));
    }
    else{
      PN s = split(t->ch[1], k - count(t->ch[0]) - 1);
      t->ch[1] = s.first;
      return make_pair(update(t), s.second);
    }
  }
  tuple<Node*,Node*,Node*> split3(Node *&t, int l, int r){//[0,l),[l,r),[r,n)
    PN sp = split(t,r);
    PN sp2 = split(sp.first,l);
    return make_tuple(sp2.first, sp2.second, sp.second);
  }
  //k
  void insert(Node *&t, int k, Monoid val){
    PN sp = split(t,k);
    sp.first = merge(sp.first, new Node(val, OM0, gen()));
    t = merge(sp.first, sp.second);
  }
  //k
  void erase(Node *&t, int k){
    PN sp = split(t,k+1);
    PN sp2 = split(sp.first,k);
    t = merge(sp2.first,sp.second); 
  }
  int size(Node *t){
    return count(t);
  }
  Node* make_root(){
    return nullptr;
  }
  void set_propagate(Node *t,OM x){
    if(!t)return;
    t->lazy = h(t->lazy, x);
    push(t);
  }
  void set_propagate(Node *&t,int l,int r,OM x){
    PN sp = split(t,r);
    PN sp2 = split(sp.first,l);
    set_propagate(sp2.second, x);
    t = merge(sp2.first,sp2.second);
    t = merge(t, sp.second);
  }
  void reverse(Node *t){
    if(!t)return;
    t->rev ^= true;
    push(t);
  }
  Monoid query(Node *&t){
    if(!t)return M1;
    push(t);
    update(t);
    return t->sum;
  }
  vector<Node*>enumerate(Node *t){
    vector<Node*>ret;
    vector<Monoid>db;
    auto dfs=[&](auto &&f, Node *nt)->void{
      if(!nt)return;
      push(nt);
      for(int i=0;i<2;i++){
        if(i==1){
          db.push_back(nt->val);
          ret.push_back(nt);
        }
        if(nt->ch[i])f(f, nt->ch[i]);
      }
      update(nt);
    };
    dfs(dfs, t);
    debug(db,db.size());
    return ret;
  }
};


int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  LazyReversibleTreap<int,int>seg;
  ll n,q,m;cin>>n>>q>>m;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  auto root=seg.make_root();
  rep(i,0,n)seg.insert(root,i,a[i]);
  while(q--){
    ll t,l,r;cin>>t>>l>>r;l--;
    if(t==1){
      auto [nl,nm,nr]=seg.split3(root,l,r);
      auto [ml,mr]=seg.split(nm,r-l-1);
      root=seg.merge(nl,mr,ml,nr);
    }
    else{
      auto [nl,nm,nr]=seg.split3(root,l,r);
      seg.reverse(nm);
      root=seg.merge(nl,nm,nr);
    }
    //if(n!=root->sz&&q%100==0)cout<<root->sz<<endl;
  }
  vector<ll>ret(m);
  vector<ll>b(m);
  //if(n!=root->sz)cout<<root->sz<<endl;
  rep(i,0,m){
    cin>>b[i],b[i]--;
    auto [nl,nm,nr]=seg.split3(root,b[i],b[i]+1);
    ret[i]=nm->sum;
    root=seg.merge(nl,nm,nr);
  }
  debug(ret,m);
  return 0;
}
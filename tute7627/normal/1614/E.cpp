//#define _GLIBCXX_DEBUG
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
  sort(ord.begin(),ord.end(),[&](int i,int j){return v[i]<v[j];});
  return ord;
}
template<typename T> vector<int> descend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return v[i]>v[j];});
  return ord;
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
template<typename T, typename V>
struct Treap{
  mt19937 mt;
  struct Node{
    T key;
    Node* ch[2];
    int pri, sz = 1;
    V val, sum;
    Node(T key, V val, int pri):key(key),val(val),sum(val),pri(pri),ch{nullptr, nullptr}{};
    void print(){
      cout<<"["<<key<<"]"<<"="<<val<<","<<sum<<" "<<pri<<" "<<sz<<endl;  
    }
  };
  Node* root = nullptr;
  T iden = 0;
  V func(V x, V y){
    return x+y;
  }
  Treap():mt(chrono::steady_clock::now().time_since_epoch().count()){
  }
  int gen(){
    return uniform_int_distribution<int>(0,1<<30)(mt);
  }
  int count(Node *t){return !t ? 0 : t->sz;};
  int sum(Node *t){return !t ? iden : t->sum;};
  Node* update(Node* t){
    t->sz = count(t->ch[0]) + count(t->ch[1]) + 1;
    t->sum = func(t->val, func(sum(t->ch[0]), sum(t->ch[1])));
    return t;
  }
  Node* merge(Node *l, Node *r){
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
  using PN = pair<Node*, Node*>;
  PN split(Node* t, int k){ //[0,k),[k,n)
    if(!t) return make_pair(nullptr, nullptr);
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
  int count_lower(Node* t, T key){
    int ret = 0;
    while(t){
      if(t->key >= key)t = t->ch[0];
      else{
        ret += count(t->ch[0]) + 1;
        t = t->ch[1];
      }
    }
    return ret;
  }

  void insert_pos(int k, V val){
    PN sp = split(root,k);
    sp.first = merge(sp.first, new Node(k, val, gen()));
    root = merge(sp.first, sp.second);
  }
  void insert_key(T key, V val){
    int k = count_lower(root, key);
    PN sp = split(root,k);
    sp.first = merge(sp.first, new Node(key, val, gen()));
    root = merge(sp.first, sp.second);
  }
  void erase_pos(int k){
    PN sp = split(root,k+1);
    PN sp2 = split(sp.first,k);
    root = merge(sp2.first,sp.second); 
  }
  void erase_key(T key){
    int k = count_lower(root, key);
    erase_pos(k);
  }
  Node* find(T key){
    Node *t = root;
    while(t){
      if(t->key == key)return t;
      if(t->key > key)t = t->ch[0];
      else t = t->ch[1];
    }
    return nullptr;
  }
  void update(T key, V val, Node* t){
    if(t->key == key){
      t->val = val;
      update(t);
    }
    else if(t->key > key){
      update(key, val, t->ch[0]);
      update(t);
    }
    else{
      update(key, val, t->ch[1]);
      update(t);
    }
  }
  void update(T key, V val){
    update(key, val, root);
  }
  Node* kth_element(int k){
    PN sp = split(root,k+1);
    PN sp2 = split(sp.first,k);
    Node* ret = sp2.second;
    root = merge(sp2.first,sp2.second); 
    root = merge(root, sp.second);
    return ret;
  }
  int size(){
    return count(root);
  }
  V query(int l,int r){
    PN sp=split(root,r);
    PN sp2=split(sp.first,l);
    V ret=sum(sp2.second);
    root = merge(sp2.first,sp2.second);
    root = merge(root, sp.second);
    return ret;
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  using namespace __gnu_pbds;
  tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> tr;
  ll inf=1e10;
  ll lastans=0;
  rep(i,0,n){
    ll t;cin>>t;
    auto get=[&](ll v){
      return i+v-tr.order_of_key(v+1);
    };
    ll k;cin>>k;
    rep(_,0,k){
      ll _x;cin>>_x;
      ll x=(_x+lastans)%((ll)1e9+1);
      ll pre=get(x);
      if(pre<t)pre++;
      else if(pre>t)pre--;
      cout<<pre<<endl;
      lastans=pre;
    }
    auto search=[&](ll v){
      ll ok=inf,ng=-inf;
      while(ok-ng>=2){
        ll mid=(ok+ng)/2;
        if(get(mid)>=v)ok=mid;
        else ng=mid;
      }
      return ok;
    };
    ll nl=search(t);
    ll nr=search(t+1);
    //cout<<nl spa nr<<endl;
    tr.insert(nl);
    tr.insert(nr);
  }
  return 0;
}
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
template<typename Key, typename Monoid, typename OM>
struct LazyTreap{
  mt19937 mt;
  struct Node{
    Key key;
    Node* ch[2];
    int pri, sz = 1;
    Monoid val, sum;
    OM lazy;
    Node(){}
    Node(Key key,Monoid val,OM lazy,int pri):key(key),val(val),lazy(lazy),sum(val),pri(pri),ch{nullptr, nullptr}{};
    void print(){
      cout<<"["<<key<<"]"<<"="<<val<<","<<sum<<" "<<pri<<" "<<sz<<endl;  
    }
  };
  int nxt = 0;
  Monoid M1 = INF;
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
  LazyTreap():mt(chrono::steady_clock::now().time_since_epoch().count()){
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
  }
  Node* merge(Node *l, Node *r){
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
  int count_lower(Node* t, Key key){
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
  //k
  void insert(Node *&t, int k, Key key, Monoid val){
    PN sp = split(t,k);
    sp.first = merge(sp.first, new Node(key, val, OM0, gen()));
    t = merge(sp.first, sp.second);
  }
  void insert_key(Node *&t, Key key, Monoid val){
    int k = count_lower(t, key);
    PN sp = split(t,k);
    sp.first = merge(sp.first, new Node(key, val, OM0, gen()));
    t = merge(sp.first, sp.second);
  }
  //k
  void erase(Node *&t, int k){
    PN sp = split(t,k+1);
    PN sp2 = split(sp.first,k);
    t = merge(sp2.first,sp.second); 
  }
  void erase_key(Node *&t, Monoid key){
    int k = count_lower(t, key);
    erase(t, k);
  }
  Node* find(Node* t, Key key){
    while(t){
      push(t);
      update(t);
      if(t->key == key)return t;
      if(t->key > key)t = t->ch[0];
      else t = t->ch[1];
    }
    return nullptr;
  }

  void update(Node* t, Key key, Monoid val){
    if(!t)return;
    push(t);
    if(t->key == key){
      t->val = val;
      update(t);
    }
    else if(t->key > key){
      update(t->ch[0],key, val);
      update(t);
    }
    else{
      update(t->ch[1],key, val);
      update(t);
    }
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
  Monoid query(Node *&t, int l, int r){
    PN sp = split(t,r);
    PN sp2 = split(sp.first,l);
    Monoid ret = sum(sp2.second);
    t = merge(sp2.first,sp2.second);
    t = merge(t, sp.second);
    return ret;
  }
  Monoid query(Node *&t){
    if(!t)return M1;
    push(t);
    update(t);
    return t->sum;
  }
  vector<Node*>enumerate(Node *t){
    vector<Node*>ret;
    auto dfs=[&](auto &&f, Node *nt)->void{
      if(!nt)return;
      push(nt);
      for(int i=0;i<2;i++){
        if(nt->ch[i])f(f, nt->ch[i]);
      }
      update(nt);
      ret.push_back(nt);
    };
    dfs(dfs, t);
    return ret;
  }
};
LazyTreap<int,ll,ll>lt;
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,s;cin>>n>>s;
  using LN=LazyTreap<int,ll,ll>::Node;
  vector<LN*>st;
  st.push_back(nullptr);
  lt.insert(st[0],0,0,0);
  ll idx=0;
  rep(i,0,n){
    string cmd;cin>>cmd;
    if(cmd=="set"){
      ll y,v;cin>>y>>v;
      if(y!=s){
        ll mi=lt.query(st[idx]);
        lt.set_propagate(st[idx],v);
        auto to=lt.find(st[idx],y);
        if(to==nullptr){
          lt.insert_key(st[idx],y,mi);
        }
        else lt.update(st[idx],y,mi);
      }
      else{
        lt.set_propagate(st[idx],v);
      }
    }
    else if(cmd=="if"){
      ll y;cin>>y;
      st.push_back(nullptr);
      auto tmp=lt.find(st[idx],y);
      if(tmp){
        lt.insert(st[idx+1],0,tmp->key,tmp->val);
        lt.erase_key(st[idx],tmp->key);
      }
      idx++;
    }
    else{
      idx--;
      if(lt.size(st[idx])<lt.size(st[idx+1]))swap(st[idx],st[idx+1]);
      auto vn=lt.enumerate(st[idx+1]);
      for(auto z:vn){
        auto to=lt.find(st[idx],z->key);
        if(to==nullptr){
          lt.insert_key(st[idx],z->key,z->val);
        }
        else if(to->val>z->val){
          lt.update(st[idx],z->key,z->val);
        }
      }
      st.pop_back();
    }
    //auto vv=lt.enumerate(st[idx]);
    //for(auto z:vv)z->print();
    //cout<<endl;
  }
  cout<<lt.query(st[idx])<<endl;
  return 0;
}
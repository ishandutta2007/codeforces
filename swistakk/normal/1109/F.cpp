#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define int long long
#define st first
#define nd second
#define rd third
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define __builtin_ctz __builtin_ctzll
#define __builtin_clz __builtin_clzll
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',') { cerr<<*sdbg++; } cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define cerr if(0)cout
#endif
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class A, class B, class C> struct Triple { A first; B second; C third;
  bool operator<(const Triple& t) const { if (st != t.st) return st < t.st; if (nd != t.nd) return nd < t.nd; return rd < t.rd; } };
template<class T> void ResizeVec(T&, vector<int>) {}
template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
  for (T& v : vec) { ResizeVec(v, sz); }
}
typedef Triple<int, int, int> TIII;
template<class A, class B, class C>
ostream& operator<< (ostream &out, Triple<A, B, C> t) { return out << "(" << t.st << ", " << t.nd << ", " << t.rd << ")"; }
template<class T> ostream& operator<<(ostream& out, vector<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }
template<class L, class R> ostream& operator<<(ostream& out, map<L, R> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }


struct node{
  node *l, *r, *p;
  int size,val,sum;
  bool flip;
  node(int _val): l(0), r(0), p(0), val(_val), size(1), sum(_val), flip(0){}
  virtual void update(){
    size = 1;              // Wszystkie funckje nalezy wykonywac na korzeniu/korzeniach
    sum = val;             // drzewa Splay. Zwracaja one nowy korzen/korzenie.
    if(l){                 // Jesli skadinad mamy wskaznik do wierzcholka, nalezy
      size += l->size;     // wykonac na nim splay(). Remove() nie zwalnia pamieci.
      sum += l->sum;       // Usuwany wierzcholek staje sie korzeniem
    }                      // jednoelementowego drzewa.
    if(r){
      size += r->size;
      sum += r->sum;
    }
  }
  void touch(){
    if(flip){
      swap(l, r);
      if(l) l->flip ^= 1;
      if(r) r->flip ^= 1;
      flip = 0;
    }
  }
  void touch_path(){
    if(p) p->touch_path();
    touch();
  }
  node*& get_child(bool right){
    return right ? r : l;
  }
  static void add_child(node* x, node* q, bool right){
    if(x) x->get_child(right) = q;
    if(q) q->p = x;
  }
  inline bool is_right(){
    return p && p->r == this;
  }
  void rotate(){
    if(!p) return;
    node *oldp = p;
    bool right = is_right();
    add_child(p->p, this, p->is_right());
    add_child(oldp, get_child(!right), right);
    add_child(this, oldp, !right);
    oldp->update();
    update();
  }
  void splay_(){
    while(p){
      if(is_right() ^ p->is_right())
        rotate();
      else
        p->rotate();
      rotate();
    }
  }
  void splay(){ //dla nieodwracalych splay'ow zastapic przez splay_
    touch_path();
    splay_();
  }
  void set_val(int nval){
    val = nval;
    update();
  }
  void reverse(){
    flip = !flip;
  }
  node* get_first(){
    node* res = this;
    while(1){
      res->touch();
      if(!res->l) break;
      res = res->l;
    }
    res->splay_();
    return res;
  }
  node* remove() {
    if(l) l->p = nullptr;
    if(r) r->p = nullptr;
    node* root = join(l, r);
    l = r = nullptr;
    return root;
  }
  static node* join(node* a, node* b){
    if(!a) return b;
    while(1){
      a->touch();
      if(!a->r) break;
      a = a->r;
    }
    a->splay_();
    add_child(a, b, true);
    a->update();
    return a;
  }
  node* get_kth(int k){
    assert(size > k);
    node* res = this;
    while(1){
      res->touch();
      if(res->l){
        if(res->l->size > k){
          res = res->l;
          continue;
        }else
          k -= res->l->size;
      }
      if(k == 0){
        res->splay_();
        return res;
      }
      k--;
      res = res->r;
    }
  }
  pair<node*, node*> split(int k){
    if(k == 0) return {nullptr, this};
    if(k >= size) return {this, nullptr};
    node* x = get_kth(k);
    node* res = x->l;
    x->l->p = nullptr;
    x->l = nullptr;
    x->update();
    return {res, x};
  }
  ~node(){ delete l; delete r; }
};

struct LCnode : node {
  
  int st_size;
  int base_size;
  
  LCnode(int val,bool ver):node(val), st_size(ver), base_size(ver){};
  
  virtual void update(){
    node::update();
    st_size = base_size;
    if(l) st_size += ((LCnode*) l)->st_size;
    if(r) st_size += ((LCnode*) r)->st_size;
  }
  
  void LCsplay(){
    node* ak = this;
    node* par = ak->p;
    while(par && (par->l == ak || par->r == ak)){
      ak = par;
      par = ak->p;
    }
    ak->p = nullptr;
    splay();
    p = par;
  }
  
  void access(){
    node* right = nullptr;
    LCnode* cur = this;
    while(cur){
      cur->LCsplay();
      
      //--- zapytania o poddrzewo
      if(cur->r) cur->base_size += ((LCnode*) cur->r)->st_size;
      if(right) cur->base_size -= ((LCnode*) right)->st_size;
      //---
      
      cur->r = right;
      cur->update();
      right = cur;
      cur = (LCnode*)cur->p;
    }
    splay();
  }
  
  void to_root(){
    access();
    reverse();
    touch();
  }
  
  void link(LCnode* par){
    to_root();
    p = par;
    
    //--- zapytania o poddrzewo
    par->to_root();
    par->base_size += st_size;
    par->update();
    //---
  }
  
  void get_path(LCnode* v){
    v->to_root();
    access();
  }
  
  void cut(LCnode* v){
    get_path(v);
    v->p = nullptr;
    l = nullptr;
    update();
  }
  
  bool connected(LCnode* v){
    get_path(v);
    return get_first() == v;
  }
  
  ~LCnode(){
    l = r = nullptr;
  };
};

map<int, LCnode*> mapping;

LCnode* GetNode(int v) {
  if (mapping.count(v)) { return mapping[v]; }
  LCnode* hehs = new LCnode(0, 1);
  return mapping[v] = hehs;
}

void AddEdge(int a, int b) {
  debug(a, b);
  LCnode* v1 = GetNode(a);
  LCnode* v2 = GetNode(b);
  v1->link(v2);
}

void RemoveEdge(int a, int b) {
  LCnode* v1 = GetNode(a);
  LCnode* v2 = GetNode(b);
  v1->cut(v2);
}

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};
const int N = 1013;
PII wh[N * N];
int board[N][N];
int n, m;
VI GetNeis(int a) {
  int i = wh[a].st;
  int j = wh[a].nd;
  VI neis;
  REP (dir, 4) {
    int ni = i + di[dir];
    int nj = j + dj[dir];
    if (ni >= 1 && ni <= n && nj >= 1 && nj <= m) {
      neis.PB(board[ni][nj]);
    }
  }
  return neis;
}

pair<bool, int> TryAdding(int guy, int fir) {
  VI neis = GetNeis(guy);
  VI added;
  int fail = 0;
  for (auto nei : neis) {
    if (nei < fir || nei > guy) { continue; }
    LCnode* nodzik = GetNode(guy);
    debug("?", guy, nei);
    if (nodzik->connected(GetNode(nei))) {
      debug("CYC");
      fail = 1;
      break;
    } else {
      AddEdge(guy, nei);
      added.PB(nei);
    }
  }
  if (fail) {
    for (auto nei : added) {
      RemoveEdge(guy, nei);
    }
  }
  return {!fail, SZ(added)};
}

const int M = 1 << 18;
struct Node {
  int mi, mult, sum;
};
Node drz[2 * M + 5];
Node Merge(Node L, Node R) {
  R.mi += L.sum;
  L.sum += R.sum;
  R.sum = L.sum;
  if (L.mi == R.mi) {
    return {L.mi, L.mult + R.mult, L.sum};
  }
  if (L.mi < R.mi) { return L; }
  return R;
}
void Set(int x, int bl, int br, int node, int val) {
  if (bl == br && bl == x) {
    drz[node].mi = val;
    drz[node].mult = 1;
    drz[node].sum = val;
    return;
  }
  if (bl > x || br < x) { return; }
  int m = (bl + br) / 2;
  Set(x, bl, m, 2 * node, val);
  Set(x, m + 1, br, 2 * node + 1, val);
  drz[node] = Merge(drz[2 * node], drz[2 * node + 1]);
}

Node Ones(int l, int r, int bl, int br, int node) {
  if (l <= bl && br <= r) {
    return drz[node];
  }
  if (r < bl || l > br) {
    return {10 * M, 1};
  }
  int m = (bl + br) / 2;
  Node L = Ones(l, r, bl, m, 2 * node);
  Node R = Ones(l, r, m + 1, br, 2 * node + 1);
  return Merge(L, R);
}
  
int cur[M];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  cin>>n>>m;
  RE (i, n) {
    RE (j, m) {
      cin>>board[i][j];
      wh[board[i][j]] = {i, j};
    }
  }
  int res = 0;
  int last = 1;
  Set(1, 1, M, 1, 1);
  RE (fir, n * m) {
    while (last + 1 <= n * m) {
      auto parka = TryAdding(last + 1, fir);
      if (parka.st) {
        last = last + 1;
        int added = parka.nd;
        debug(last, 1 - added);
        Set(last, 1, M, 1, 1 - added);
        cur[last] = 1 - added;
      } else {
        break;
      }
    }
    debug(fir, last);
    Node hehs = Ones(fir, last, 1, M, 1);
    debug(hehs.mi, hehs.mult);
    if (hehs.mi == 1) {
      res += hehs.mult;
    }
    //res += last - fir + 1;
    VI neis = GetNeis(fir);
    for (auto nei : neis) {
      if (nei >= fir && nei <= last) {
        cur[nei]++;
        Set(nei, 1, M, 1, cur[nei]);
        RemoveEdge(fir, nei);
      }
    }
  }
  cout<<res<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
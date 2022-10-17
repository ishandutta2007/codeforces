#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

const int LEV = 22;
const int M1 = (1<<LEV)-1;

int BIT(int x, int bit) { return (1<<bit) & x; }

struct node;
using pn = node*;
pn merge(pn a, pn b);

struct node {
  pn l = nullptr, r = nullptr;
  int cnt_ = 0, here = 0;
  int level = -1;
  int lazy_xor = 0;
  int has_on = 0, has_off = 0;

  friend int cnt(pn x) { return x ? x->cnt_ : 0; }
  friend int ON(pn x) { return x ? x->has_on : 0; }
  friend int OFF(pn x) { return x ? x->has_off : 0; }
  friend pn create(pn l, pn r, int lev) {
    pn t = new node();
    t->level = lev;
    t->l = l;
    t->r = r;
    t->pull();
    return t;
  }

  void pull() {
    cnt_ = here + cnt(l) + cnt(r);
    has_on = ON(l) | ON(r);
    has_off = OFF(l) | OFF(r);
    if(r) has_on ^= (1<<level);
    if(l) has_off ^= (1<<level);
  }
  void apply_xor(int x) {
    rep(bit,0,LEV) if(x>>bit&1){
      lazy_xor ^= (1<<bit);
      if((has_on>>bit&1) != (has_off>>bit&1)){
        has_on ^= (1<<bit);
        has_off ^= (1<<bit);
      }
    }
  }
  void push() {
    if(level == -1) return;
    if(lazy_xor>>level&1) swap(l,r);
    for(auto c : {l,r}) if(c) c->apply_xor(lazy_xor);
    lazy_xor = 0;
    pull();
  }
};

pn merge(pn a, pn b) {
  if(!a) return b;
  if(!b) return a;
  a->push();
  b->push();
  pn t = create(merge(a->l, b->l), merge(a->r, b->r), a->level);
  t->here = (a->here || b->here);
  t->pull();
  delete a;
  delete b;
  return t;
}

pair<pn,pn> split(pn t, int x, int level = LEV) {
  if(!t) return {t,t};
  assert(level == t->level);
  t->push();
  if(level == -1) return {nullptr, t}; // x on RHS
  if(x>>level&1) {
    auto [a,b] = split(t->r,x,level-1);
    auto p = make_pair(create(t->l,a,level), create(nullptr,b,level));
    delete t;
    return p;
  }
  else {
    auto [a,b] = split(t->l,x,level-1);
    auto p = make_pair(create(a,nullptr,level), create(b,t->r,level));
    delete t;
    return p;
  }
}

void insert(pn& t, int x, int level = LEV) {
  if(!t) t = create(t, t, level);
  assert(level == t->level);
  t->push();
  if(level == -1) {
    t->here = 1;
    t->pull();
    return;
  }
  if(x>>level&1) insert(t->r, x, level-1);
  else insert(t->l, x, level-1);
  t->pull();
}

tuple<pn,pn,pn> split3(pn t, int l, int r) {
  auto [L,T] = split(t,l);
  auto [M,R] = split(T,r+1);
  return {L,M,R};
}

void XOR(pn& t, int x) {
  if(!t) return;
  t->apply_xor(x);
  t->push();
}
void OR(pn& t, int x) {
  if(!x) return;
  if(!t) return;
  t->push();
  if(t->level == -1) return;
  if(x>>t->level&1) {
    t->r = merge(t->l,t->r);
    t->l = nullptr;
    t->pull();
  }
  rep(bit,0,t->level) if(x>>bit&1) {
    if((t->has_off>>bit&1) == 0) x ^= (1<<bit);
    else if((t->has_on>>bit&1) == 0) { x ^= (1<<bit); XOR(t, 1<<bit); }
  }
  OR(t->l, x);
  OR(t->r, x);
  t->pull();
}
void AND(pn& t, int x) { XOR(t, M1); OR(t, x^M1); XOR(t, M1); }

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  int n, q;
  cin>>n>>q;

  pn root = nullptr;
  rep(i,0,n) {
    int a;
    cin>>a;
    insert(root, a);
  }


  rep(i,0,q) {
    int typ,l,r,x;
    cin>>typ>>l>>r;
    if(typ <= 3) cin>>x;
    auto [a,b,c] = split3(root,l,r);

    if(typ == 1) AND(b,x);
    if(typ == 2) OR(b,x);
    if(typ == 3) XOR(b,x);
    if(typ == 4) cout << cnt(b) << "\n";
    root = merge(a,merge(b,c));
  }

  cout << flush;
  _Exit(0);
}
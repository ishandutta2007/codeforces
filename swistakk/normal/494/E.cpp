#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define st first
#define nd second
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#ifdef LOCAL
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debug2(x, y) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
using std::cerr;
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::set;
using std::map;
using std::pair;
using std::max;
using std::min;
using std::ostream;
using std::fixed;
using std::ios_base;
using std::setprecision;
using std::make_pair;
using std::string;
using std::multiset;
using std::next_permutation;
using std::prev_permutation;
using std::random_shuffle;
using std::greater;
using std::lower_bound;
using std::upper_bound;
using std::reverse;
using std::swap;
using std::complex;
using std::sort;
using std::bitset;
using std::abs;
using std::__gcd;
using std::unordered_set;
using std::unordered_map;
using std::sqrt;
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}

const int N = 5e4 + 5;
const int M = 1ll << 30;
//int nimb[N][N];

struct Rect {
  int x1, y1, x2, y2;
};
Rect rect[N];
struct Node {
  Node() {
    sum = 0;
    cov = 0;
    sons[0] = sons[1] = nullptr;
  }
  Node* sons[2];
  int sum, cov;
  void Check(int ind) {
    if (sons[ind] != nullptr) { return; }
    sons[ind] = new Node();
  }
  void AddRec(int l, int r, int b_l, int b_r, int val) {
    if (r < b_l || l > b_r) { return; }
    int wid = b_r - b_l + 1;
    if (wid > 1) {
      REP (tr, 2) {
        Check(tr);
      }
    }
    int m;
    if (r >= b_r && l <= b_l) {
      sum += val;
      if (wid == 1) {
        cov = wid * !!sum;
      } else {
        goto B;
      }
      return;
    }    
    m = (b_l + b_r) / 2;
    sons[0]->AddRec(l, r, b_l, m, val);
    sons[1]->AddRec(l, r, m + 1, b_r, val);
    B: ;
    if (sum) {
      cov = wid;
    } else {
      cov = sons[0]->cov + sons[1]->cov;
    }
  }
  void Free() {
    REP (tr, 2) {
      if (sons[tr] != nullptr) {
        sons[tr]->Free();
        delete sons[tr];
      }
    }
  }
};

struct DynamicTree {
  Node* root;
  DynamicTree() {
    root = new Node();
  }
  ~DynamicTree() {
    root->Free();
    delete root;
  }
  void Add(int l, int r, int val) { root->AddRec(l, r, 1, M, val); }
  int ReadCov() { return root->cov; }
};

struct Ev {
  int x, y1, y2, val;
  bool operator<(const Ev& e) const {
    if (x != e.x) { return x < e.x; }
    return val < e.val;
  }
};

int main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make3(int, _, m, k);
  RE (i, m) {
    make4(int, x1, y1, x2, y2);
    rect[i] = Rect{x1, y1, x2, y2};
  }
  //sort(rect + 1, rect + 1 + m);
  int pot = 1;
  while (pot <= k) {
    DynamicTree tree;
    vector<Ev> evs;
    RE (i, m) {
      Rect r = rect[i];
      r.x1--;
      r.y1--;
      r.x1 = r.x1 / pot + 1;
      r.y1 = r.y1 / pot + 1;
      r.x2 = r.x2 / pot;
      r.y2 = r.y2 / pot;
      evs.PB(Ev{r.x1 - 1, r.y1, r.y2, 1});
      evs.PB(Ev{r.x2, r.y1, r.y2, -1});
    }
    sort(ALL(evs));
    int last = 0;
    ll res = 0;
    for (auto e : evs) {
      res = (res + (e.x - last) % 2 * tree.ReadCov()) % 2;
      debug3(e.x, last, tree.ReadCov());
      tree.Add(e.y1, e.y2, e.val);
      last = e.x;
    }
    debug(res);
    if (res) {
      cout<<"Hamed\n";
      goto A;
    }
    pot *= 2;
  }
  cout<<"Malek\n";
  A: ;
  
  
  
  
  return 0;
}
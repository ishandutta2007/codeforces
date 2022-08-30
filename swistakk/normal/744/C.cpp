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
using namespace std;
template<typename TH> void _dbg(const char* sdbg, TH h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH h, TA... t) {
  while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
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

struct Info {
  int turns, red, blue;
  bool operator<(const Info& oth) const {
    if (turns != oth.turns) return turns < oth.turns;
    if (red != oth.red) return red < oth.red;
    return blue < oth.blue;
  }
  friend ostream& operator<<(ostream& out, Info i) {
    return out<<"("<<i.turns<<", "<<i.red<<", "<<i.blue<<")";
  }
};
bool IsDominated(Info i1, Info i2) {
  i1.red += i2.turns - i1.turns;
  i1.blue += i2.turns - i1.turns;
  return i1.red <= i2.red && i1.blue <= i2.blue;
}
const int N = 16;
vector<Info> res[1 << N];
int has_red[1 << N];
int has_blue[1 << N];
int is_red[N];
int r[N], b[N];
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  REP (i, n) {
    char c;
    cin>>c;
    if (c == 'R') {
      is_red[i] = 1;
    }
    cin>>r[i]>>b[i];
  }
  res[0].PB({0, 0, 0});
  REP (mask, 1 << n) {
    if (mask == 0) { continue; }
    REP (last, n) {
      if (!(mask & (1 << last))) { continue; }
      int prv_mask = mask - (1 << last);
      has_red[mask] = has_red[prv_mask] + (is_red[last]);
      has_blue[mask] = __builtin_popcount(mask) - has_red[mask];
      for (auto& prv_res : res[prv_mask]) {
        int cost_r = max(0ll, r[last] - has_red[prv_mask]);
        int cost_b = max(0ll, b[last] - has_blue[prv_mask]);
        int need_turns = max(max(0ll, cost_r - prv_res.red), cost_b - prv_res.blue);
        auto new_res = prv_res;
        new_res.turns += need_turns;
        new_res.red += need_turns;
        new_res.blue += need_turns;
        new_res.red -= cost_r;
        new_res.blue -= cost_b;
        debug(mask, last, new_res, need_turns);
        assert(new_res.red == 0 || new_res.blue == 0);
        bool fail = false;
        for (auto& R : res[mask]) {
          if (IsDominated(new_res, R)) {
            fail = true;
            break;
          }
        }
        if (!fail) {
          vector<Info> new_heh;
          for (auto& R : res[mask]) {
            if (!IsDominated(R, new_res)) {
              new_heh.PB(R);
            }
          }
          new_heh.PB(new_res);
          res[mask] = new_heh;
        }
      }
    }
    debug(mask, res[mask]);
  }
  int best = 1e9;
  for (auto& H : res[(1 << n) - 1]) {
    mini(best, H.turns);
  }
  cout<<best+n<<endl;

  
  return 0;
}
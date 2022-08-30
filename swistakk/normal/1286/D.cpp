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

const int P = 998244353;
int spow(int a, int b) {
  int r = 1;
  while (b) {
    if (b % 2) {
      r = r * a % P;
    }
    a = a * a % P;
    b /= 2;
  }
  return r;
}
int Inv(int a) { return spow(a, P - 2); }
const int N = 1e5 + 5;
int p[N], q[N];
struct Node {
  int prodp, prodq, all;
};
Node Merge(Node A, Node B) {
  Node n;
  n.prodp = A.prodp * B.prodp % P;
  n.prodq = A.prodq * B.prodq % P;
  n.all = A.all * B.prodp + A.prodq * B.all - A.prodq * B.prodp;
  n.all = ((n.all % P) + P) % P;
  return n;
}
const int M = 1 << 17;
Node drz[2 * M + 5];
Node Read(int a, int b) {
  a += M - 1;
  b += M - 1;
  Node L = drz[a];
  if (a == b) { return L; }
  Node R = drz[b];
  while (a / 2 != b / 2) {
    if (a % 2 == 0) {
      L = Merge(L, drz[a + 1]);
    }
    if (b % 2 == 1) {
      R = Merge(drz[b - 1], R);
    }
    a /= 2;
    b /= 2;
  }
  return Merge(L, R);
}
struct Ev {
  int t_num, t_den;
  int pos, typ; // 0-do siebie, 1 - na lewo, 2 - na prawo
  bool operator<(const Ev& oth) const {
    return t_num * oth.t_den < oth.t_num * t_den;
  }
};
int x[N], v[N];
struct Seg {
  int L, R, fir_right, last_left, p;
};
Seg segs[N];
int GetP(Seg seg) {
  if (seg.fir_right <= seg.last_left) { return 0; }
  debug(seg.L, seg.R, seg.fir_right, seg.last_left);
  int prod_left = 1;
  if (seg.last_left != 0) {
    prod_left = Read(seg.L, seg.last_left).prodq;
  }
  int prod_right = 1;
  if (seg.fir_right != N) {
    prod_right = Read(seg.fir_right, seg.R).prodp;
  }
  if (seg.last_left + 1 == seg.fir_right) { return prod_left * prod_right % P; }
  return prod_left * prod_right % P * Read(max(seg.L, seg.last_left + 1), min(seg.R, seg.fir_right - 1)).all % P;
}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  int i100 = Inv(100);
  RE (i, n) {
    int pp;
    cin>>x[i]>>v[i]>>pp;
    p[i] = pp * i100 % P;
    q[i] = (P + 1 - p[i]) % P;
    drz[i + M - 1] = {p[i], q[i], 1};
  }
  FORD (i, M - 1, 1) {
    drz[i] = Merge(drz[2 * i], drz[2 * i + 1]);
  }
  vector<Ev> evs;
  RE (i, n - 1) {
    evs.PB({x[i + 1] - x[i], v[i] + v[i + 1], i, 0});
    if (v[i] > v[i + 1]) {
      evs.PB({x[i + 1] - x[i], v[i] - v[i + 1], i, 2});
    } else if (v[i] < v[i + 1]) {
      evs.PB({x[i + 1] - x[i], v[i + 1] - v[i], i, 1});
    }
  }
  sort(ALL(evs));
  int cur_p = 1;
  set<int> active;
  RE (i, n) {
    active.insert(i);
    segs[i] = {i, i, N, 0, 1};
  }
  int prv_p = -1;
  int res = 0;
  for (auto ev : evs) {
    prv_p = cur_p;
    int t = ev.t_num * Inv(ev.t_den) % P;
    debug(ev.pos, ev.typ);
    if (ev.typ == 0) {
      int b2 = ev.pos + 1;
      auto it = active.find(b2);
      assert(*it == b2);
      int b1 = *prev(it);
      active.erase(it);
      debug(segs[b1].p, segs[b2].p);
      cur_p = cur_p * Inv(segs[b1].p) % P * Inv(segs[b2].p) % P;
      segs[b1].R = segs[b2].R;
      mini(segs[b1].fir_right, segs[b2].fir_right);
      maxi(segs[b1].last_left, segs[b2].last_left);
//       if (segs[b1].fir_right <= segs[b1].last_left) {
//         cur_p = 0;;
//       }
      segs[b1].p = GetP(segs[b1]);
      debug(segs[b1].p);
      cur_p = cur_p * segs[b1].p % P;
    } else {
      int b = *prev(active.upper_bound(ev.pos));
      cur_p = cur_p * Inv(segs[b].p) % P;
      if (ev.typ == 1) {
        mini(segs[b].fir_right, ev.pos + 1);
      } else {
        maxi(segs[b].last_left, ev.pos);
      }
      segs[b].p = GetP(segs[b]);
      cur_p = cur_p * segs[b].p % P;
    }
    int diff = (P + prv_p - cur_p) % P;
    debug(diff);
    res = (res + diff * t) % P;
    if (cur_p == 0) { break; }
  }
  cout<<res<<endl;

  
  return 0;
}
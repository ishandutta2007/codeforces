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

const int N = 1e5 + 5;
const int M = 1 << 17;
int dp[N];
const int P = 1e9 + 7;
int plyn[N][3];
vector<TIII> drz[2 * M + 5];
struct Barrier {
  int u, l, r, s, i;
  bool operator<(const Barrier& other) const {
    return u > other.u;
  }
};
void Put(int i, int pos, int h, int ind) {
  pos += M - 1;
  while (pos) {
    drz[pos].PB({i, h, ind});
    pos /= 2;
  }
}

void GoRec(int bl, int br, int v, int l, int r, int maxh, int i) {
  if (bl > r || br < l) { return; }
  if (bl >= l && br <= r) {
    while (!drz[v].empty() && drz[v].back().nd <= maxh) {
      auto& node = drz[v].back();
      if (plyn[node.st][node.rd] == 0) {
        plyn[node.st][node.rd] = i;
      }
      drz[v].pop_back();
    }
    return;
  }
  int m = (bl + br) / 2;
  GoRec(bl, m, 2 * v, l, r, maxh, i);
  GoRec(m + 1, br, 2 * v + 1, l, r, maxh, i);
}

void Go(int l, int r, int maxh, int i) {
  GoRec(1, M, 1, l, r, maxh, i);
}

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int h, w, n;
  cin>>h>>w>>n;
  vector<Barrier> barriers;
  RE (i, n) {
    int u, l, r, s;
    cin>>u>>l>>r>>s;
    barriers.PB({u, l, r, s, i});
  }
  sort(ALL(barriers));
  // TODO ustaw from_up na drzewku
  RE (i, w) {
    Put(i, i, h + 1, 2);
  }
  for (auto& barrier : barriers) {
    Go(barrier.l, barrier.r, barrier.u + barrier.s, barrier.i);
    int pos[2];
    if (barrier.l == 1) {
      pos[0] = barrier.r + 1;
    } else {
      pos[0] = barrier.l - 1;
    }
    if (barrier.r == w) {
      pos[1] = barrier.l - 1;
    } else {
      pos[1] = barrier.r + 1;
    }
    REP (t, 2) {
      Put(barrier.i, pos[t], barrier.u, t);
    } 
  }
  dp[n + 1] = 1;
  RE (i, max(n, w)) {
    REP (t, 3) {
      if (plyn[i][t] == 0) {
        plyn[i][t] = n + 1;
      }
    }
  }
  FORD (ii, SZ(barriers) - 1, 0) {
    int i = barriers[ii].i;
    dp[i] = dp[plyn[i][0]] + dp[plyn[i][1]];
    dp[i] %= P;
    debug(i, plyn[i][0], plyn[i][1], dp[i]);
  }
  int res = 0;
  RE (i, w) {
    debug(i, plyn[i][2]);
    res += dp[plyn[i][2]];
  }
  cout<<res % P<<endl;
  
  return 0;
}
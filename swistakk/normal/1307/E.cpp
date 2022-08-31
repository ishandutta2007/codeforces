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

const int N = 5e3 + 5;
int which[N];
bool is_cow[N][N];
int32_t pref[N][N];
int sweet[N];
const int P = 1e9 + 7;
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m;
  cin>>n>>m;
  VI cnt_sweet(n + 2);
  RE (i, n) {
    int a;
    cin>>a;
    sweet[i] = a;
    cnt_sweet[a]++;
    which[i] = cnt_sweet[a];
  }
  VVI cows_at_sweet(n + 2);
  RE (i, m) {
    int f, h;
    cin>>f>>h;
    is_cow[f][h] = 1;
    cows_at_sweet[f].PB(h);
  }
  RE (i, n) {
    RE (j, n) {
      pref[i][j] = pref[i][j - 1] + is_cow[i][j];
    }
  }
  RE (i, n) {
    sort(ALL(cows_at_sweet[i]));
  }
  int best_eat = 0, best_ways = 0;
  FOR (left_stop, 0, n) {
    if (left_stop && !is_cow[sweet[left_stop]][which[left_stop]]) { continue; }
    int here = sweet[left_stop];
    int cows = !!left_stop;
    int ways = 1;
    if (left_stop) {
      RE (i, n) {
        if (is_cow[here][i] && i != which[left_stop] && which[left_stop] + i <= cnt_sweet[here]) {
          if (cows == 1) {
            cows = 2;
            ways = 1;
          } else {
            ways++;
          }
        }
      }
    }
    VI up_till(n + 2);
    RE (i, left_stop - 1) {
      up_till[sweet[i]]++;
    }
    RE (kind, n) {
      if (kind == here) { continue; }
      int L = up_till[kind];
      int R = cnt_sweet[kind] - up_till[kind];
      if (L > R) {
        swap(L, R);
      }
      if (left_stop == 0) {
        debug(kind, L, R, pref[kind][R]);
      }
      if (pref[kind][L] >= 1 && pref[kind][R] >= 2) {
        cows += 2;
        ways = (ways * pref[kind][L] % P * (pref[kind][R] - 1)) % P;
      } else if (pref[kind][R] >= 1) {
        cows++;
        ways = (ways * (pref[kind][R] + pref[kind][L])) % P;
      }
    }
    debug(left_stop, cows, ways);
    if (cows > best_eat) {
      best_eat = cows;
      best_ways = ways;
    } else if (cows == best_eat) {
      best_ways = (best_ways + ways) % P;
    }
  }
  cout<<best_eat<<" "<<best_ways<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
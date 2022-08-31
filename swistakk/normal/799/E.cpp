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

struct Thing {
  int cost, l[2];
  Thing() {
    l[0] = l[1] = 0;
  }
  bool operator<(const Thing& oth) const {
    return cost < oth.cost;
  }
};
const int N = 2e5 + 5;
const int M = 1 << 18;

Thing th[N];
struct Node {
  int to_take, sum_cost;
  Node() {
    to_take = 0, sum_cost = 0;
  }
};
Node drz[2 * M + 5];
int cur_must_cost;
void Change(int a, int must_take) {
  int C = th[a].cost;
  a += M;
  if (drz[a].to_take == 0) {
    cur_must_cost -= C;
  }
  drz[a].to_take = 1 - must_take;
  if (drz[a].to_take == 0) {
    cur_must_cost += C;
  }
  drz[a].sum_cost = drz[a].to_take * C;
  a /= 2;
  while (a) {
    drz[a].to_take = drz[2 * a].to_take + drz[2 * a + 1].to_take;
    drz[a].sum_cost = drz[2 * a].sum_cost + drz[2 * a + 1].sum_cost;
    a /= 2;
  }
}
int Best(int k, int v) {
  if (k == 0) {
    return 0;
  }
  if (drz[v].to_take == k) {
    return drz[v].sum_cost;
  }
  if (drz[2 * v].to_take > k) {
    return Best(k, 2 * v);
  }
  return Best(k - drz[2 * v].to_take, 2 * v + 1) + drz[2 * v].sum_cost;
}

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m, k;
  cin>>n>>m>>k;
  RE (i, n) {
    cin>>th[i].cost;
  }
  int liked;
  REP (tr, 2) {
    cin>>liked;
    if (liked < k) {
      cout<<-1<<endl;
      return 0;
    }
    RE (i, liked) {
      int a;
      cin>>a;
      th[a].l[tr] = 1;
    }
  }
  sort(th + 1, th + 1 + n);
  VI both, only1, only2;
  RE (i, n) {
    drz[i + M].sum_cost = th[i].cost;
    drz[i + M].to_take = 1;
    if (th[i].l[0] && th[i].l[1]) {
      both.PB(i);
    } else if (th[i].l[0]) {
      only1.PB(i);
    } else if (th[i].l[1]) {
      only2.PB(i);
    }
  }
  FORD (a, M - 1, 1) {
    drz[a].to_take = drz[2 * a].to_take + drz[2 * a + 1].to_take;
    drz[a].sum_cost = drz[2 * a].sum_cost + drz[2 * a + 1].sum_cost;
  }
  int best_res = 1e18;
  int from_both = min(SZ(both), k);
  for (int ii = 0; ii < from_both; ii++) {
    Change(both[ii], 1);
  }
  for (int ii = 0; ii < k - from_both; ii++) {
    Change(only1[ii], 1);
    Change(only2[ii], 1);
  }
  int cnt_taken = from_both + 2 * (k - from_both);
  debug(cnt_taken);
  if (cnt_taken > m) {
    cout<<"-1\n";
    return 0;
  }
  int to_activate = k - from_both;
  debug(cur_must_cost);
  mini(best_res, cur_must_cost + Best(m - cnt_taken, 1));
  //int min_both_taken = max(0ll, k - min(SZ(only1), SZ(only2)));
  FORD (ii, from_both - 1, 0) {
    Change(both[ii], 0);
    if (SZ(only1) <= to_activate || SZ(only2) <= to_activate) { break; }
    Change(only1[to_activate], 1);
    Change(only2[to_activate], 1);
    to_activate++;
    cnt_taken++;
    debug(cnt_taken);
    if (cnt_taken > m) { break; }
    debug(cur_must_cost);
    mini(best_res, cur_must_cost + Best(m - cnt_taken, 1));
  }
  if (best_res > 1e17) {
    cout<<"-1\n";
  } else {
    cout<<best_res<<endl;
  }
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
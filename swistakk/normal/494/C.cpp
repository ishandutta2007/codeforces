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
typedef double LD;
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

// set<int> imp;
const LD kEps = 1e-6;
const int N = 1e5 + 5;
// const int M = 1 << 17;
// int drz[2 * M + 5];
bool cmp(pair<PII, int> a, pair<PII, int> b) {
  if (a.st.st != b.st.st) { return a.st.st < b.st.st; }
  return a.st.nd > b.st.nd;
}
int a[N], l[N], r[N];
LD p[N];
int Read(int lll, int rr) {
  int heh = 0;
  FOR (i, lll, rr) {
    maxi(heh, a[i]);
  }
  return heh;
}
vector<int> slo[N];
int par[N];

const int Q = 5e3 + 5;
LD dp[Q][2 * Q];

void Dfs(int v) {
  for (auto nei : slo[v]) {
    Dfs(nei);
  }
  int min_sure = 0;
  if (SZ(slo[v]) == 0) {
    dp[v][0] = 1;
    min_sure = Read(l[v], r[v]);
  } else {
    maxi(min_sure, Read(l[v], l[slo[v][0]] - 1));
    maxi(min_sure, Read(r[slo[v].back()] + 1, r[v]));
    for (int ii = 0; ii < SZ(slo[v]) - 1; ii++) {
      maxi(min_sure, Read(r[slo[v][ii]] + 1, l[slo[v][ii + 1]] - 1));
    }
    vector<LD> so_far;
    so_far.resize(SZ(slo[v]));
    LD prev = 0;
    FOR (i, 0, 2 * Q - 5) {
      LD p_here = 1;
      for (int j = 0; j < SZ(slo[v]); j++) {
        int nei = slo[v][j];
        so_far[j] += dp[nei][i];
        p_here *= so_far[j];
      }
      dp[v][i] = p_here - prev;
      prev = p_here;
    }
    //assert(fabs(prev - 1.) < kEps);
  }
  debug2(v, min_sure);
  FOR (i, 0, 10) {
    cerr<<dp[v][i]<<" ";
  }
  cerr<<endl;
  FOR (i, 0, min_sure - 1) {
    dp[v][min_sure] += dp[v][i];
    dp[v][i] = 0;
  }
  FOR (i, 0, 10) {
    cerr<<dp[v][i]<<" ";
  }
  cerr<<endl;
  for (int i = 2 * Q - 1; i >= 1; i--) {
    dp[v][i] = (1 - p[v]) * dp[v][i] + p[v] * dp[v][i - 1];
  }
  dp[v][0] = dp[v][0] * (1 - p[v]);
  
  FOR (i, 0, 10) {
    cerr<<dp[v][i]<<" ";
  }
  cerr<<endl;
}
  

int main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, q);
  int max_a = 0;
  RE (i, n) {
    cin>>a[i];
    maxi(max_a, a[i]);
//     drz[i + M - 1] = a[i];
  }
//   for (int i = M - 1; i >= 1; i--) {
//     drz[i] = max(drz[2 * i], drz[2 * i + 1]);
//   }
  int bon = max_a - q;
  RE (i, n) {
    a[i] -= bon;
    maxi(a[i], 0);
  }
  RE (i, q) {
    cin>>l[i]>>r[i]>>p[i];
//     mapka[l[i] - 1] = 1;
//     mapka[l[i]] = 1;
//     mapka[r[i]] = 1;
//     mapka[r[i] + 1] = 1;
  }
  q++;
  l[q] = 0;
  r[q] = n;
  p[q] = 0;
  vector<pair<PII, int>> rec;
  RE (i, q) {
    rec.PB(MP(MP(l[i], r[i]), i));
  }
  sort(ALL(rec), cmp);
//   int depth = -1;
//   int rightmost = -1;
  vector<int> stack;
  stack.PB(q);
  for (int ii = 1; ii < SZ(rec); ii++) {
    auto act = rec[ii];
    while (act.st.st > r[stack.back()]) {
      stack.pop_back();
    }
    slo[stack.back()].PB(act.nd);
    stack.PB(act.nd);
  }
  RE (i, q) {
    debugv(slo[i]);
  }
  LD res = 0;
  
  Dfs(q);
  
  FOR (i, 0, 2 * Q - 2) {
    res += dp[q][i] * i;
  }
  
  
  
  
  
  
  
  
  cout<<res + bon<<"\n";
  
  
  return 0;
}
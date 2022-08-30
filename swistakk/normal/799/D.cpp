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

int Solve(int a, int b, VI exts) {
  debug(a, b, exts);
  if (a > b) {
    swap(a, b);
  }
  if (a <= 1 && b <= 1) {
    return 0;
  }
  set<PII> secik;
  secik.insert({1, 1});
  int cnt = 0;
  for (auto x : exts) {
    cnt++;
    set<PII> n_secik;
    for (auto p : secik) {
      if (p.st < a) {
        n_secik.insert({x * p.st, p.nd});
      }
      if (p.nd < b) {
        n_secik.insert({p.st, x * p.nd});
      }
    }
    for (auto p : n_secik) {
      if (p.st >= a && p.nd >= b) {
        return cnt;
      }
    }
    secik = n_secik;
  }
  return 2e9;
  //~ RE (cand, SZ(exts)) {
    //~ int prod = 1;
    //~ REP (i, cand) {
      //~ prod = prod * exts[i];
    //~ }

}
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int a, b, h, w, n;
  cin>>a>>b>>h>>w>>n;
  VI hehs;
  RE (i, n) {
    int xx;
    cin>>xx;
    hehs.PB(xx);
  }
  sort(ALL(hehs));
  reverse(ALL(hehs));
  int r1 = Solve((h + a - 1) / h, (w + b - 1) / w, hehs), r2 =  Solve((w + a - 1) / w, (h + b - 1) / h, hehs);
  if (r1 > 1e9 && r2 > 1e9) {
    cout<<-1<<endl;
  } else {
    cout<<min(r1, r2)<<endl;
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
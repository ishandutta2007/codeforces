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


int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  string s;
  cin>>s;
  int n = SZ(s);
  s = "$" + s;
  VI a(n + 2);
  VI ones;
  int sqr = 0;
  while ((sqr + 1) * (sqr + 1) <= 2 * n) {
    sqr++;
  }
  sqr = 400;
// #ifdef LOCAL
//   sqr = 1;
// #endif
  ones.PB(0);
  RE (i, n) {
    a[i] = a[i - 1] + (s[i] == '1');
    if (s[i] == '1') {
      ones.PB(i);
    }
  }
  int res = 0;
  ones.PB(n + 1);
  RE (i, SZ(ones) - 2) {
    FOR (j, i, min(i + sqr - 1, SZ(ones) - 2)) {
      int L = ones[i] - ones[i - 1];
      int R = ones[j + 1] - ones[j];
      int cnt_ones = j - i + 1;
      int min_len = ones[j] - ones[i] + 1;
      int max_len = min_len + L + R - 2;
      if (L > R) {
        swap(L, R);
      }
      int cp = res;
      int32_t fir_ok_bef_diag = (min_len + cnt_ones - 1) / cnt_ones * cnt_ones;
      int32_t fir_diag = min_len + L - 1;
      int32_t last_diag = min_len + R - 1;
      int32_t fir_ok_on_diag = (fir_diag + cnt_ones - 1) / cnt_ones * cnt_ones;
      int32_t last_ok_bef_diag = fir_ok_on_diag - cnt_ones;
      int32_t bef_diags = (last_ok_bef_diag - fir_ok_bef_diag + cnt_ones) / cnt_ones;
      int32_t fir_len = fir_ok_bef_diag - min_len + 1;
      res += 1ll * fir_len * bef_diags + 1ll * bef_diags * (bef_diags - 1) / 2 * cnt_ones;
      int32_t last_ok_on_diag = last_diag / cnt_ones * cnt_ones;
      int32_t diags = (last_ok_on_diag - fir_ok_on_diag + cnt_ones) / cnt_ones;
      res += 1ll * diags * L;
      int32_t fir_ok_aft_diag = last_ok_on_diag + cnt_ones;
      int32_t last_ok_aft_diag = max_len / cnt_ones * cnt_ones;
      int32_t aft_diags = (last_ok_aft_diag - fir_ok_aft_diag + cnt_ones) / cnt_ones;
      int32_t last_len = max_len - last_ok_aft_diag + 1;
      res += 1ll * aft_diags * last_len + 1ll * aft_diags * (aft_diags - 1) / 2 * cnt_ones;
      //debug(i, j, ones[i], ones[j], L, R, min_len, max_len, res - cp);
    }
  }
  debug(1.0 * clock() / CLOCKS_PER_SEC);
  int max_rat = n / sqr + 2;
  RE (rat, max_rat) {
    vector<pair<int32_t, int32_t>> vals;
    //unordered_map<int, VI> vals;
    //vals[0].PB(0);
    vals.PB({0, 0});
    RE (i, n) {
      vals.PB({i - rat * a[i], i});
    }
    sort(ALL(vals));
    for (int i = 0; i < SZ(vals); i++) {
      if (i != SZ(vals) - 1 && vals[i + 1].st == vals[i].st) { continue; }
      int beg = i;
      while (beg && vals[beg - 1].st == vals[beg].st) { beg--; }
      int min_diff = rat * (sqr + 1);
      int fir_bad = beg;
      FOR (j, beg, i) {
        while (vals[fir_bad].nd + min_diff <= vals[j].nd) { fir_bad++; }
        res += fir_bad - beg;
      }
    }
  }
  cout<<res<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
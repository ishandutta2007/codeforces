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
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

struct Str {
  string s;
  bool operator<(const Str& p) const {
    if (p.s == "") { return s != ""; }
    if (SZ(s) != SZ(p.s)) {
      return SZ(s) < SZ(p.s);
    }
    return s < p.s;
  }
};





int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  vector<vector<Str>> best(3, vector<Str>(256));
  best[0][15] = {"x"};
  best[0][0x33] = {"y"};
  best[0][0x55] = {"z"};
  best[1] = best[0];
  best[2] = best[0];
  set<pair<Str, PII>> que;
  REP (tr, 3) {
    que.insert({{"x"}, {tr, 15}});
    que.insert({{"y"}, {tr, 0x33}});
    que.insert({{"z"}, {tr, 0x55}});
  }
  vector<pair<Str, PII>> processed;
  auto Relax = [&](Str cand, int lvl, int val) {
    if (cand < best[lvl][val]) {
      que.erase({best[lvl][val], {lvl, val}});
      best[lvl][val] = cand;
      que.insert({best[lvl][val], {lvl, val}});
    }
  };
  while (!que.empty()) {
    auto it = que.begin();
    auto p = *it;
    processed.PB(p);
    que.erase(que.begin());
    int lvl = p.nd.st;
    int val = p.nd.nd;
    Str s = p.st;
    if (lvl == 0) {
      Str cand = {"!" + s.s};
      Relax(cand, 0, 255 - val);
    }
    REP (tr, 3) {
      if (tr > lvl) {
        Relax(s, tr, val);
      }
    }
    Str parenth = {"(" + s.s + ")"};
    Relax(parenth, 0, val);
    if (lvl == 1) {
      for (auto prv : processed) {
        if (prv.nd.st == 0) {
          Str cand = {s.s + "&" + prv.st.s};
          Relax(cand, 1, val & prv.nd.nd);
        }
      }
      for (auto prv : processed) {
        if (prv.nd.st == 2) {
          Str cand = {prv.st.s + "|" + s.s};
          Relax(cand, 2, val | prv.nd.nd);
        }
      }
    }
    if (lvl == 2) {
      for (auto prv : processed) {
        if (prv.nd.st == 1) {
          Str cand = {s.s + "|" + prv.st.s};
          Relax(cand, 2, val | prv.nd.nd);
        }
      }
    }
    if (lvl == 0) {
      for (auto prv : processed) {
        if (prv.nd.st == 1) {
          Str cand = {prv.st.s + "&" + s.s};
          Relax(cand, 1, val & prv.nd.nd);
        }
      }
    }
  }
        
  map<string, string> res;
  REP (mask, 256) {
    string s;
    s.resize(8);
    REP (bit, 8) {
      s[bit] = '0' + (!!(mask & (1 << bit)));
    }
    reverse(ALL(s));
    res[s] = best[2][mask].s;
  }
  debug(best[2][0x33].s);
  debug(best[0][0xCC].s);
  debug(best[2][0xCC].s);
  debug(res["11001100"]);
  debug(res["00111111"]);
  
  int n;
  cin>>n;
  RE (i, n) {
    string s;
    cin>>s;
    cout<<res[s]<<"\n";
  }
  
  return 0;
}
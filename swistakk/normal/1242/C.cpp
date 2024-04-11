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

void Exit() {
  cout<<"No\n";
  exit(0);
}

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int k;
  cin>>k;
  VVI boxes(k + 2);
  int sum = 0;
  VI sums(k + 2);
  map<int, int> wh_box;
  map<int, int> vis;
  RE (i, k) {
    int n;
    cin>>n;
    RE (j, n) {
      int a;
      cin>>a;
      boxes[i].PB(a);
      wh_box[a] = i;
      sum += a;
      sums[i] += a;
    }
  }
  if (sum % k) {
    Exit();
  }
  int goal = sum / k;
  VI need_add(k + 2);
  RE (i, k) {
    need_add[i] = goal - sums[i];
    debug(i, need_add[i]);
  }
  map<int, VPII> masks;
  RE (box, k) {
    for (auto val : boxes[box]) {
      //if (vis[val]) { continue; }
      int mask = 0;
      int curval = val;
      int curbox = box;
      int fail = 0;
      VPII vec;
      do {
        vis[curval] = 1;
        mask |= 1 << curbox;
        int need = curval + need_add[curbox];
        int go = wh_box[need];
        debug(curval, curbox, need, go);
        if (go == 0) { fail = 1; break; }
        if (go != box && (mask & (1 << go))) { fail = 1; break; }
        if (go == box && need != val) { fail = 1; break; }
        vec.PB({curval, go});
        curbox = go;
        curval = need;
      } while (curval != val);
      debug(fail);
      mask /= 2;
      if (!fail && masks.count(mask) == 0) {
        debug(mask);
        masks[mask] = vec;
      }
    }
  }
  debug(masks);
      
  vector<int> dp(1 << k);
  int full_mask = (1 << k) - 1;
  dp[0] = 1;
  for (auto item : masks) {
    int mask = item.st;
    int complem = full_mask - mask;
    for (int heh = complem; ; heh = (heh - 1) & complem) {
      if (dp[heh]) {
        dp[heh + mask] = mask;
      }
      if (heh == 0) { break; }
    }
  }
  if (dp.back()) {
    cout<<"Yes\n";
    int heh = full_mask;
    VI val(k + 2);
    VI rev(k + 2);
    VI per(k + 2);
    while (heh) {
      int mask = dp[heh];
      debug(mask);
      for (auto p : masks[mask]) {
        val[wh_box[p.st]] = p.st;
        rev[wh_box[p.st]] = p.nd;
      }
      heh -= mask;
    }
    RE (i, k) {
      per[rev[i]] = i;
    }
    RE (i, k) {
      cout<<val[i]<<" "<<per[i]<<"\n";
    }
  } else {
    Exit();
  }

  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
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
template<typename TH> void _dbg(const char* sdbg, TH hh) { cerr<<sdbg<<"="<<hh<<"\n"; }
template<typename TH, typename... TA> void _dbg(const char* sdbg, TH hh, TA... t) {
  while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<hh<<","; _dbg(sdbg+1, t...);
}
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
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

const int N = 1e6 + 5;
int ans[N];
int right_part[N];
int left_part[N];
VPII qs[N];
PII zap[N];
int val[N];
int sumuj[N];
int h[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n, m;
  cin>>n>>m;
  RE (i, n) {
    cin>>h[i];
  }
  RE (i, m) {
    int a, b;
    cin>>a>>b;
    qs[a].PB({b, i});
    zap[i] = {a, b};
  }
  vector<set<PII>> moms_on_suf;
  moms_on_suf.resize(n + 2);
  moms_on_suf[0].insert({1e9 + 5, n + 1});
  VI cur{(int)1e9 + 5};
  FORD (i, n, 1) {
    for (auto q : qs[i]) {
      int kl = 0, kp = SZ(cur) - 1, faj = 0;
      while (kl <= kp) {
        int aktc = (kl + kp) / 2;
        if (cur[aktc] > q.st) {
          faj = aktc;
          kl = aktc + 1;
        } else {
          kp = aktc - 1;
        }
      }
      right_part[q.nd] = faj;
    }
    int kl = 0, kp = SZ(cur) - 1, faj = 0;
    while (kl <= kp) {
      int aktc = (kl + kp) / 2;
      if (cur[aktc] > h[i]) {
        faj = aktc;
        kl = aktc + 1;
      } else {
        kp = aktc - 1;
      }
    }
    if (faj == SZ(cur) - 1) {
      cur.PB(0);
    }
    if (h[i] != cur[faj + 1]) {
      moms_on_suf[faj + 1].insert({h[i], i});
    }
    cur[faj + 1] = h[i];
  }
  int asc_len = SZ(cur) - 1;
  RE (i, m) {
    ans[i] = asc_len - 1;
  }
  cur = VI{0};
  FOR (i, 0, n) {
    if (i) {
      for (auto q : qs[i]) {
        int kl = 0, kp = SZ(cur) - 1, faj = 0;
        while (kl <= kp) {
          int aktc = (kl + kp) / 2;
          if (cur[aktc] < q.st) {
            faj = aktc;
            kl = aktc + 1;
          } else {
            kp = aktc - 1;
          }
        }
        left_part[q.nd] = faj;
        maxi(ans[q.nd], 1 + left_part[q.nd] + right_part[q.nd]);
      }
      int kl = 0, kp = SZ(cur) - 1, faj = 0;
      while (kl <= kp) {
        int aktc = (kl + kp) / 2;
        if (cur[aktc] < h[i]) {
          faj = aktc;
          kl = aktc + 1;
        } else {
          kp = aktc - 1;
        }
      }
      if (faj == SZ(cur) - 1) {
        cur.PB(0);
      }
      cur[faj + 1] = h[i];
      int need = asc_len - faj - 1;
      debug(asc_len, faj + 1);
      auto it = moms_on_suf[need].upper_bound({h[i], n + 5});
      if (it != moms_on_suf[need].end() && i + 1 < it->nd) {
        val[i + 1]++;
        val[it->nd]--;
      }
    } else {
      int need = asc_len;
//       debug(asc_len, faj + 1);
      auto it = moms_on_suf[need].upper_bound({h[i], n + 5});
      if (it != moms_on_suf[need].end() && i + 1 < it->nd) {
        val[i + 1]++;
        val[it->nd]--;
      }
    }
  }
  RE (i, n) {
    sumuj[i] = sumuj[i - 1] + val[i];
  }
  RE (i, m) {
    if (ans[i] == asc_len - 1 && sumuj[zap[i].st]) {
      cout<<asc_len<<"\n";
    } else {
      cout<<ans[i]<<"\n";
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
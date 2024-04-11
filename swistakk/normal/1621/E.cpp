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

struct Sol {
  void Test() {
    int n, m;
    cin>>n>>m;
    VI ages(n + 2);
    RE (i, n) {
      cin>>ages[i];
    }
    sort(ages.begin() + 1, ages.begin() + 1 + n, greater<int>());
    VI ceils(m + 2);
    VVI alt_ceils(m + 2);
    RE (i, m) {
      int k;
      cin>>k;
      int S = 0;
      VI g;
      RE (j, k) {
        int x;
        cin>>x;
        S += x;
        g.PB(x);
      }
      ceils[i] = ((S + k - 1) / k);
      for (auto e : g) {
        alt_ceils[i].PB((S - e + k - 2) / (k - 1));
      }
      //order.PB({ceils[i], i});
    }
    VI ceils_ord = ceils;
    sort(ceils_ord.begin() + 1, ceils_ord.begin() + m + 1, greater<int>());
    VVI bad(3, VI(m + 2));
    VVI pref_bad(3, VI(m + 2));
    RE (i, m) {
      REP (tr, 3) {
        bad[tr][i] = ages[i] < ceils_ord[i + tr - 1];
        pref_bad[tr][i] = pref_bad[tr][i - 1] + bad[tr][i];
      }
    }
    // znajdz najpozniejsza ktora jest >=
    function<int(int)> Get = [&](int c) {
      int kl = 1, kp = m, faj = 0;
      while (kl <= kp) {
        int aktc = (kl + kp) / 2;
        if (ceils_ord[aktc] >= c) {
          faj = aktc;
          kl = aktc + 1;
        } else {
          kp = aktc - 1;
        }
      }
      return faj;
    };
    function<int(int, int, int)> Check = [&](int tr, int L, int R) {
      return pref_bad[tr][R] - pref_bad[tr][L - 1];
    };
    RE (i, m) {
      int wh = Get(ceils[i]);
      assert(ceils_ord[wh] == ceils[i]);
      for (auto alt : alt_ceils[i]) {
        int zium = Get(alt);
        if (zium >= wh) {
          if (Check(1, 1, wh - 1) == 0 && Check(2, wh, zium - 1) == 0 && ages[zium] >= alt && Check(1, zium + 1, m) == 0) {
            cout<<"1";
          } else {
            cout<<"0";
          }
        } else {
          if (Check(1, 1, zium) == 0 && ages[zium + 1] >= alt && Check(0, zium + 2, wh) == 0 && Check(1, wh + 1, m) == 0) {
            cout<<"1";
          } else {
            cout<<"0";
          }
        }
      }
    }
    cout<<"\n";
  }
};


int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int t;
  cin>>t;
  RE (i, t) {
    Sol sol;
    sol.Test();
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
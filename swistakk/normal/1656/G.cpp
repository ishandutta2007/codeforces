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
  VI rep;
  int Find(int x) {
    if (rep[x] == x) { return x; }
    return rep[x] = Find(rep[x]);
  }
  void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    rep[a] = b;
  }
  void Test() {
    int n;
    cin>>n;
    rep.resize(n + 2);
    VI a(n + 2);
    VI cnt(n + 2);
    RE (i, n) {
      cin>>a[i];
      cnt[a[i]]++;
    }
    VI odds;
    RE (i, n) {
      if (cnt[i] % 2) {
        odds.PB(i);
      }
    }
    int any = 0;
    int mid = (n + 1) / 2;
    if (SZ(odds) >= 2) { cout<<"NO\n"; return; }
    if (SZ(odds) == 1) {
      if (a[(n + 1) / 2] == odds[0] && cnt[odds[0]] == 1) { cout<<"NO\n"; return; }
      if (a[(n + 1) / 2] != odds[0]) {
        RE (i, n) {
          if (a[i] == odds[0]) {
            swap(a[i], a[(n + 1) / 2]);
            any = i;
            break;
          }
        }
      } else {
        RE (i, n) {
          if (i != mid && a[i] == odds[0]) {
            any = i;
            break;
          }
        }
      }
//       RE (i, n) {
//         if (a[i] == odds[0]) {
//           a[i] = a[(n + 1) / 2];
//         }
//       }
    }
    cout<<"YES\n";
    VPII ps;
    VI prv(n + 2);
    VI pos;
    RE (i, n) {
      if (2 * i == n + 1) {
      } else {
        pos.PB(i);
      }
    }
    for (auto p : pos) {
      if (prv[a[p]] == 0) {
        prv[a[p]] = p;
      } else {
        ps.PB(PII{prv[a[p]], p});
        prv[a[p]] = 0;
      }
    }
    assert(n / 2 == SZ(ps));
    for (auto p : pos) {
      rep[p] = p;
    }
    VI to(n + 2);
    RE (i, n / 2) {
      to[i] = ps[i - 1].st;
      to[n - i + 1] = ps[i - 1].nd;
      Union(i, ps[i - 1].st);
      Union(n - i + 1, ps[i - 1].nd);
    }
    RE (i, n / 2) {
      if (Find(i) != Find(n - i + 1)) {
        swap(to[i], to[n + 1 - i]);
        Union(i, n + 1 - i);
      }
    }
    RE (i, n / 2) {
      if (Find(i) != Find(1)) {
        Union(1, i);
        int cp = to[1];
        to[1] = to[i];
        to[i] = to[n];
        to[n] = to[n + 1 - i];
        to[n + 1 - i] = cp;
      }
    }
    if (n % 2 == 1) {
      to[mid] = mid;
      int inv_any = -1;
      RE (i, n) {
        if (to[i] == any) {
          inv_any = i;
        }
      }
      swap(to[inv_any], to[mid]);
//       if (any) {
//         
//         
//       } else {
//         
//         
//       }
    }
    RE (i, n) {
      cout<<to[i]<<" ";
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
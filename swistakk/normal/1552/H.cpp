#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
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

int r1, r2, c1, c2;


int Ask(VPII pts) {
#ifdef LOCAL
  int cnt = 0;
  for (auto p : pts) {
    if (r1 <= p.st && p.st <= r2 && c1 <= p.nd && p.nd <= c2) {
      cnt++;
    }
  }
  return cnt;
#else
  cout<<"? "<<SZ(pts)<<endl;
  for (auto p : pts) {
    cout<<p.st<<" "<<p.nd<<" ";
  }
  cout<<endl;
  int a;
  cin>>a;
  return a;
#endif
}

int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int cl = clock();
  //int cl = 3215;
  debug(cl);
  srand(cl);
  int R = 200;
#ifdef LOCAL
  r1 = 1 + rand() % R;
  r2 = 1 + rand() % R;
  c1 = 1 + rand() % R;
  c2 = 1 + rand() % R;
  if (r1 > r2) { swap(r1, r2); }
  if (r1 == r2) { r1 = 10, r2 = 20; }
  if (c1 > c2) { swap(c1, c2); }
  if (c1 == c2) { c1 = 10, c2 = 20; }
  debug(r1, r2, c1, c2, r2 - r1 + 1, c2 - c1 + 1);
#endif
  
  VPII q;
  RE (i, R) {
    RE (j, R) {
      q.PB({i, j});
    }
  }
  int area = Ask(q);
  VPII cands;
  FOR (i, 2, area - 1) {
    if (area % i == 0 && i <= R && area / i <= 200) {
      cands.PB({i, area / i});
    }
  }
  REP (turns, 3) {
    map<int, VPII> best_map;
    int max_grp = 500;
    int ba, bb, binters;
    RE (a, R / 2 + 5) {
      RE (b, R / 2 + 5) {
        REP (inters, 2) {
          map<int, VPII> cnt;
          for (auto cand : cands) {
            int h = cand.st;
            int w = cand.nd;
            VI ws{w / a};
            if (w % a) {
              ws.PB(w / a + 1);
            }
            VI hs{h / b};
            if (h % b) {
              hs.PB(h / b + 1);
            }
//             if (a == 1 && b == 2 && inters == 1) {
//               debug(hs, ws);
//             }
            for (auto hh : hs) {
              for (auto ww : ws) {
                int ppp = ww * h + hh * w - hh * ww * (1 + inters);
                cnt[ppp].PB(cand);
              }
            }
          }
          int here = 0;
          for (auto& v : cnt) {
            maxi(here, SZ(v.nd));
          }
          if (here < max_grp) {
            best_map = cnt;
            max_grp = here;
            ba = a;
            bb = b;
            binters = inters;
          }
        }
      }
    }
    q.clear();
    RE (i, R) {
      RE (j, R) {
        int include = 0;
        if (i % bb == 0 || j % ba == 0) { include = 1; }
        if (i % bb == 0 && j % ba == 0 && binters) { include = 0; }
        if (include) {
          q.PB({i, j});
        }
      }
    }
    int ziom = Ask(q);
//     if (best_map[ziom].empty()) {
//       debug(bb, ba, binters, best_map, ziom);
//     }
    cands = best_map[ziom];
  }
  debug(cands);
  assert(SZ(cands) == 1 || (SZ(cands) == 2 && cands[0].st == cands[1].nd));
  cout<<"! "<<2 * (cands[0].st + cands[0].nd - 2)<<endl;
  debug(cands[0]);
  debug(r2 - r1 + 1, c2 - c1 + 1);
    
        
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
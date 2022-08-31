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

int a1 = 1, b1 = 2, a2 = 4, b2 = 2;
int c1 = 1, d1 = 6, c2 = 4, d2 = 9;

int cnt;
// int In(VI x) {
//   debug(x);
//   return (x[0] <= a1 && x[1] <= b1 && x[2] >= a2 && x[3] >= b2) + 
//          (x[0] <= c1 && x[1] <= d1 && x[2] >= c2 && x[3] >= d2);
// }

//int orig_n;
int orig_n;
int In(VI x) {
  
  if (x[0] > x[2] || x[1] > x[3]) {
    return 0;
  }
  cnt++;
  if (cnt > 200) {
    assert(0);
  }
  cout<<"? "<<x[0]<<" "<<x[1]<<" "<<min(orig_n, x[2])<<" "<<min(orig_n, x[3])<<endl;
  int hehs;
  cin>>hehs;
  return hehs;
}
    
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
//   int orig_n;
//   cin>>orig_n;
//   int n = (1 << 16);
  int n;
  cin>>n;
  orig_n = n;
  VI bb{1, 1, n, n};
  REP (tr, 2) {
    int kl = 1, kp = n;
    while (kl <= kp) {
      int aktc = (kl + kp) / 2;
      VI cand = bb;
      cand[tr] = aktc;
      if (In(cand) == 2) {
        kl = aktc + 1;
        bb[tr] = aktc;
      } else {
        kp = aktc - 1;
      }
    }
  }
  FOR (tr, 2, 3) {
    int kl = bb[tr - 2], kp = n;
    while (kl <= kp) {
      int aktc = (kl + kp) / 2;
      VI cand = bb;
      cand[tr] = aktc;
      if (In(cand) == 2) {
        kp = aktc - 1;
        bb[tr] = aktc;
      } else {
        kl = aktc + 1;
      }
    }
  }
  debug(bb);
  VVI zioms(2);
  REP (rec_ind, 2) {
    VI rec = bb;
    REP (tr, 2) {
      int kl = rec[tr], kp = rec[tr + 2];
//       VI pre_cand = rec;
//       pre_cand[tr]++;
//       if (In(pre_cand) == 0) {
//         continue;
//       }
      while (kl <= kp) {
        int aktc = (kl + kp) / 2;
        VI cand = rec;
        cand[tr] = aktc;
        if (In(cand) >= 1) {
          kl = aktc + 1;
          rec[tr] = aktc;
        } else {
          kp = aktc - 1;
        }
      }
    }
    FOR (tr, 2, 3) {
      int kl = rec[tr - 2], kp = rec[tr];
      VI pre_cand = rec;
//       pre_cand[tr]--;
//       if (In(pre_cand) == 0) {
//         continue;
//       }
      while (kl <= kp) {
        int aktc = (kl + kp) / 2;
        VI cand = rec;
        cand[tr] = aktc;
        if (In(cand) >= 1) {
          kp = aktc - 1;
          rec[tr] = aktc;
        } else {
          kl = aktc + 1;
        }
      }
    }
    zioms[rec_ind] = rec;
    VI bb_cp = bb;
    if (rec_ind == 0) {
      REP (tr, 2) {
        VI cand = bb;
        cand[tr + 2] = rec[tr] - 1;
        //debug(cand, In(cand));
        if (In(cand)) {
          bb = cand;
          goto X;
        }
      }
      FOR (tr, 2, 3) {
        VI cand = bb;
        cand[tr - 2] = rec[tr] + 1;
        //debug(cand, In(cand));
        if (In(cand)) {
          bb = cand;
          goto X;
        }
      }
      assert(0);
    }
    X: ;
    debug(rec_ind, rec, bb);
  }
  cout<<"! ";
  REP (tr, 2) {
    
    REP (i, 4) {
      cout<<zioms[tr][i]<<" ";
    }
    //cout<<endl;
  }
  cout<<endl;
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
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


int s[3];
const int N = 2e5 + 5;
int c[6];
int summed[6];
int survivors[N];
int need[6];
int Max4(int b, int cc, int d, int e) {
  return max(max(max(b, cc), d), e);
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int n;
  cin>>n;
  cin>>s[0]>>s[1]>>s[2];
  sort(s, s + 3);
  int sum = s[0] + s[1] + s[2];
  multiset<int> opps;
  int hrs = 0;
  RE (i, n) {
    int guy;
    cin>>guy;
    if (guy > s[1] + s[2]) {
      hrs++;
      if (guy > sum) {
        cout<<"-1\n";
        return 0;
      }
    } else {
      opps.insert(guy);
    }
  }
  debug(hrs);
  summed[0] = s[0];
  summed[1] = s[1];
  summed[2] = s[2];
  summed[3] = s[0] + s[1];
  summed[4] = s[0] + s[2];
  summed[5] = s[1] + s[2];
  int inv = 0;
  if (summed[2] > summed[3]) {
    swap(summed[2], summed[3]);
    inv = 1;
  }
  int nic = 4;
  while (1) {
    auto it = opps.end();
    it--;
    int rem = -1;
    if (*it > summed[3]) {
      if (*it > summed[4]) {
        rem = sum - summed[5];
      } else {
        rem = sum - summed[4];
      }
      hrs++;
      opps.erase(it);
      it = opps.upper_bound(rem);
      if (it != opps.begin()) {
        it--;
        opps.erase(it);
      }
    } else {
      break;
    }
  }
  debug(hrs);
  debugv(opps);
  for (auto it : opps) {
    int ziom = 0;
    while (summed[ziom] < it) {
      ziom++;
    }
    assert(ziom <= 3);
    c[ziom]++;
  }
  REP (i, 4) {
    debug(i, c[i]);
  }
  int best = n;
  FOR (a, 0, n) {
    int b = -1;
    if (inv) {
      b = Max4(c[3] - a, (c[3] + c[2] + 1 - a) / 2, (c[3] + c[2] + c[1] + 1 - 2 * a) / 2, (c[3] + c[2] + c[1] + c[0] + 1 - 3 * a) / 2);
    } else {
      b = Max4(c[3], (c[3] + c[2] + 1 - a) / 2, (c[3] + c[2] + c[1] + 1 - 2 * a) / 2, (c[3] + c[2] + c[1] + c[0] + 1 - 3 * a) / 2);
    }
    mini(best, a + max(b, 0ll));
  }
//  int kl = 0, kp = n, faj = n;
//   while (kl <= kp) {
//     int aktc = (kl + kp) / 2;
//     int fail = 0;
//     debug(aktc);
//     if (!inv) {
//       REP (i, 4) {
//         need[i] = c[i];
//       }
//       int must = c[3];
//       need[3] -= must;
//       need[2] -= must;
//       if (must > aktc) {
//         fail = 1;
//       }
//       int rem = aktc - must;
//       need[2] -= rem;
//       need[1] -= rem;
//       need[0] -= rem;
//       int summ = 0;
//       FORD (i, 3, 0) {
//         debug(
//         summ += need[i];
//         if (sum > 0) {
//           fail = 1;
//         }
//       }
//     } else {
//       
//       int ab = max(max(c[3], (c[3] + c[2] + c[1] + 1) / 2), (2 * c[3] + 2 * c[2] + c[1] + c[0] + 3) / 4);
//       int b = c[3] + c[2] - ab;
//       int a = c[3] + c[2] + c[1] + c[0] - ab;
//       fail = (aktc < ab || aktc < a + b);
//     }
//     if (!fail) {
//       faj = aktc;
//       kp = aktc - 1;
//     } else {
//       kl = aktc + 1;
//     }
//   }
  cout<<hrs+best<<endl;
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
#include <bits/stdc++.h>
long long max(int a, long long b) { return max((long long)a, b); }
long long max(long long b, int a) { return max(a, (long long)b); }
#define MP make_pair
#define PB push_back
#define int long long
#define st first
#define nd second
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#ifdef LOCAL
#define debug(x) {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debug4(x, y, z, t) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#t <<" = " <<t<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debug4(x,y,z,t)
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
using namespace std;
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}

const int N = 1e5 + 5;
int pref[N][2];
int pt[N];
vector<PII> res;
int Int(int l, int r, int pl) {
  return pref[r][pl] - pref[l - 1][pl];
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  RE (i, n) {
    cin>>pt[i];
  }
  RE (i, n) {
    if (pt[n] == 2) {
      pt[i] = 3 - pt[i];
    }
  }
  RE (i, n) {
    int a = pt[i];
    a--;
    REP (tr, 2) { pref[i][tr] = pref[i - 1][tr]; }
    pref[i][a]++;
  }
  cerr<<Int(2, 4, 0)<<endl;
  pref[n + 1][0] = pref[n + 1][1] = N;
  RE (t, n) {
    debug(t);
    int p1 = 0, p2 = 0, act_pos = 0;
    int bad = 0;
    int last = 0;
    while (act_pos < n) {
      int kl = act_pos + 1, kp = n + 1, faj = -1;
      while (kl <= kp) {
        int aktc = (kl + kp) / 2;
        if (Int(act_pos + 1, aktc, 0) >= t || Int(act_pos + 1, aktc, 1) >= t) {
          faj = aktc;
          kp = aktc - 1;
        } else {
          kl = aktc + 1;
        }
      }
      if (faj == n + 1) {
        bad = 1;
        break;
      }
      if (Int(act_pos + 1, faj, 0) >= t) {
        p1++;
        last = 1;
      } else {
        p2++;
        last = 2;
      }
      act_pos = faj;
      debug(act_pos);
    }
    if (bad) { continue; }
    if (p1 > p2 && last == 1) {
      debug2(p1, p2);
      res.PB(MP(p1, t));
    }
  }
  sort(ALL(res));
  cout<<SZ(res)<<"\n";
  for (auto p : res) {
    cout<<p.st<<" "<<p.nd<<"\n";
  }
      
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
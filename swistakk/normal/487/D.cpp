#include <bits/stdc++.h>
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
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debug2(x, y) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
using std::cerr;
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::set;
using std::map;
using std::pair;
using std::max;
using std::min;
using std::ostream;
using std::fixed;
using std::ios_base;
using std::setprecision;
using std::make_pair;
using std::string;
using std::multiset;
using std::next_permutation;
using std::prev_permutation;
using std::random_shuffle;
using std::greater;
using std::lower_bound;
using std::upper_bound;
using std::reverse;
using std::swap;
using std::complex;
using std::sort;
using std::bitset;
using std::ws;
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
const int M = 1 << 18;
struct Node {
  vector<PII> pos;
};
Node drz[2 * M + 5];
string s[N];
int m;
void Fix(int r) {
  vector<PII> res;
  res.resize(m + 2);
  FOR (i, 1, m) {
    if (s[r][i] == '>') {
      int end = i + 1;
      while (end <= m && s[r][end] == '>') {
        end++;
      }
      if (end > m) {
        res[i] = MP(r, m + 1);
      } else if (s[r][end] == '<') {
        res[i] = MP(-1, -1);
      } else {
        res[i] = MP(-2, end);
      }
    } else if (s[r][i] == '<') {
      int beg = i - 1;
      while (beg && s[r][beg] == '<') {
        beg--;
      }
      if (beg == 0) {
        res[i] = MP(r, 0);
      } else if (s[r][beg] == '>') {
        res[i] = MP(-1, -1);
      } else {
        res[i] = MP(-2, beg);
      }
    } else {
      res[i] = MP(-2, i);
    }
  }
  drz[M + r - 1].pos = res;
  debugv(res);
}
int deb;
vector<PII> Merge(vector<PII>& fir, vector<PII>& sec) {
  vector<PII> res;
  res.resize(m + 2);
  if (deb) {
    cerr<<"Merguje \n";
    debugv(fir);
    debugv(sec);
  }
  FOR (i, 1, m) {
    if (sec[i].st != -2) {
      res[i] = sec[i];
    } else {
      res[i] = fir[sec[i].nd];
    }
  }
  return res;
}
    
void Update(int i) {
  Fix(i);
  i += M - 1;
  i /= 2;
  while (i) {
    drz[i].pos = Merge(drz[2 * i].pos, drz[2 * i + 1].pos);
    i /= 2;
  }
}
pair<int, int> Get(int i, int j) {
  vector<PII> act = drz[M + i - 1].pos;
  i += M - 1;
  debugv(act);
  deb = 1;
  while (i > 1) {
    if (i % 2 == 1) {
      act = Merge(drz[i - 1].pos, act);
      debugv(act);
    }
    i /= 2;
  }
  deb = 0;
  return act[j];
}
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, n);
  cin>>m;
  make(int, q);
  
  vector<PII> nic;
  nic.resize(m + 2);
  RE (i, 2 * M) { 
    drz[i].pos = nic;
  }
  RE (i, n) {
    cin>>ws;
    getline(cin, s[i]);
    s[i] = ' ' + s[i];
    Update(i);
  }

    
    
  RE (i, q) {
    make(char, c);
    if (c == 'A') {
      make2(int, x, y);
      auto res = Get(x, y);
      if (res.st == -2) {
        res.st = 0;
      }
      cout<<res.st<<" "<<res.nd<<"\n";
    } else {
      make2(int, x, y);
      cin>>s[x][y];
      Update(x);
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
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
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class A, class B, class C> struct Triple { A first; B second; C third; };
template<class T> void ResizeVec(T&, vector<int>) {}
template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
  for (T& v : vec) { ResizeVec(v, sz); }
}

const int P = 999999197;
const int M = 1e9 + 7;
VI a;
int A0;
map<int, int> mapka;
bool Can(VI b) {

  debugv(a);
  debugv(b);
  int cnt0 = 0;
  REP (tr, 26) {
    if (b[tr] == 0) { cnt0++; continue; }
    auto it = mapka.find(b[tr]);
    if (it != mapka.end()) {
      debug2(*it, b[tr]);
    }
    int good = 0;
    if (mapka.find(b[tr]) != mapka.end()) {
      if ((b[mapka[b[tr]]] == 0  && a[tr] == 0)) {
        good = 1;
      } else if (mapka.find(b[mapka[b[tr]]]) != mapka.end() && mapka[b[mapka[b[tr]]]] == tr) {
        good = 1;
      }
    }
    if (!good) { return false; }
  }
  if (cnt0 != A0) { return false; }
  cerr<<"Gitara\n";
  return true;
}


#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, m);
  make2(string, s, t);
  s = ' ' + s;
  t = ' ' + t;
  VI th;
  th.resize(26);
  int LOL = 1;
  RE (i, m) {
    LOL = LOL * P % M;
    REP (tr, 26) {
      th[tr] = th[tr] * P % M;
    }
    int c = t[i] - (int)('a');
    th[c]++;
    th[c] %= M;
    
  }
  VI sh;
  sh.resize(26);
  VI ans;
  a = th;
  A0 = 0;
  REP (tr, 26) {
    mapka[a[tr]] = tr;
    if (a[tr] == 0) {
      A0++;
    }
  }
  debugv(mapka);
  RE (i, n) {
    REP (tr, 26) {
      sh[tr] = sh[tr] * P % M;
    }
    int c = s[i] - (int)('a');
    sh[c]++;
    sh[c] %= M;
    if (i > m) {
      c = s[i - m] - (int)('a');
      sh[c] += M - LOL;
      sh[c] %= M;
    }
    debug(i);
      if (Can(sh)) {
        debug2("Udalo sie przy ", i);
        ans.PB(i - m + 1);
      }
  }
  
  cout<<SZ(ans)<<"\n";
  for (auto x : ans) {
    cout<<x<<" ";
  }
  cout<<"\n";
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
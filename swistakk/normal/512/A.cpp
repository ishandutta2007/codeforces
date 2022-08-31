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

const int N = 2e2 + 5;
string names[N];
vector<int> slo[N];
int deg[N];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  
  
  make(int, n);
  
  
  
  
  
  
  
  
  
  
  
  RE (i, n) {
    cin>>names[i];
  }
  RE (i, n - 1) {
    int a = min(names[i].length(), names[i + 1].length());
    int ok = 0;
    for (int pos = 0; pos < a; pos++) {
      if (names[i][pos] != names[i + 1][pos]) {
        ok = 1;
        int x = (int)(names[i][pos]);
        int y = (int)(names[i + 1][pos]);
        slo[x].PB(y);
        deg[y]++;
        break;
      }
    }
    if (!ok) {
      if (names[i].length() > names[i + 1].length()) {
        cout<<"Impossible\n";
        return 0;
      }
    }
  }
  vector<int> que;
  REP (i, N) {
    if (deg[i] == 0) {
      que.PB(i);
    }
  }
  vector<char> ord;
  for (int i = 0; i < SZ(que); i++) {
    int v = que[i];
    if (v >= (int)('a') && v <= (int)('z')) {
      ord.PB(char(v));
    }
    for (int nei : slo[v]) {
      deg[nei]--;
      if (deg[nei] == 0) {
        que.PB(nei);
      }
    }
  }
  if (SZ(que) == N) {
    for (char x : ord) {
      cout<<x;
    }
    cout<<"\n";
  } else {
    cout<<"Impossible\n";
  }
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
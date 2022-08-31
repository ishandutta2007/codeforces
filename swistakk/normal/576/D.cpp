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

typedef vector<bitset<155>> Matrix ;
int n;
Matrix Transpose(Matrix m) {
  Matrix x;
  x.resize(n);
  REP (i, n) {
    REP (j, n) {
      x[i][j] = m[j][i];
    }
  }
  return x;
}
const int N = 2e2;
int dis[N];
Matrix Mult(Matrix m1, Matrix m2) {
  Matrix res;
  res.resize(n);
  m2 = Transpose(m2);
  REP (i, n) {
    REP (j, n) {
      res[i][j] = (m1[i] & m2[j]).any();
    }
  }
  return res;
}

Matrix ID() {
  Matrix res;
  res.resize(n);
  REP (i, n) {
    res[i][i] = 1;
  }
  return res;
}
Matrix pow(Matrix m, int a) {
  Matrix res = ID();
  while (a) {
    if (a % 2) {
      res = Mult(res, m);
    }
    m = Mult(m, m);
    a /= 2;
  }
  return res;
}
void Print(Matrix m) {
    REP (i, n) {
      REP (j, n) {
        cerr<<m[i][j];
      }
      cerr<<endl;
    }
}
const int kInf = 2e9;
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int m;
  cin>>n>>m;
  vector<TIII> edge;
  RE (i, m) {
    int a, b, d;
    cin>>a>>b>>d;
    edge.PB({d, a - 1, b - 1});
  }
  edge.PB({kInf, 0, 0});
  sort(ALL(edge));
  Matrix st = ID();
  Print(Mult(st, st));
  Matrix to_mult;
  to_mult.resize(n);
  int last = 0;
  int best = kInf;
  for (int ii = 0; ii < SZ(edge); ii++) {
    cerr<<"to_mult\n";
    Print(to_mult);
    //Print(Transpose(to_mult));
    auto& e = edge[ii];
    
    REP (i, n) {
      if (st[0][i]) {
        dis[i] = last;
      } else {
        dis[i] = kInf;
      }
    }
    REP (i, n) {
      REP (jj, ii) {
        cerr<<edge[jj].nd<<" to "<<edge[jj].rd<<endl;
        mini(dis[edge[jj].rd], dis[edge[jj].nd] + 1);
      }
    }
    mini(best, dis[n - 1]);
    cerr<<"st\n";
    Print(st);
    debug(e.st - last);
    st = Mult(st, pow(to_mult, e.st - last));
    to_mult[e.nd][e.rd] = 1;
    last = e.st;
  }
  
  
  if (best == kInf) {
    cout<<"Impossible\n";
  } else {
    cout<<best<<"\n";
  }
  return 0;
}
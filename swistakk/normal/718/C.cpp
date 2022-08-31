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

const int P = 1e9 + 7;
struct Matrix {
  int a[4];
  int& operator[](int i) {
    return a[i];
  }
};
Matrix Id() {
  return {1, 0, 0, 1};
}
Matrix Mult(Matrix a, Matrix b) {
  Matrix m;
  m[0] = (a[0] * b[0] + a[1] * b[2]) % P;
  m[1] = (a[0] * b[1] + a[1] * b[3]) % P;
  m[2] = (a[2] * b[0] + a[3] * b[2]) % P;
  m[3] = (a[2] * b[1] + a[3] * b[3]) % P;
  return m;
}

Matrix Add(Matrix a, Matrix b) {
  Matrix m;
  REP (i, 4) {
    m[i] = (a[i] + b[i]) % P;
  }
  return m;
}

const int M = (1 << 17);
pair<Matrix, Matrix> drz[2 * M + 5];
    
Matrix spow(Matrix m, int b) {
  Matrix r = Id();
  while (b) {
    if (b % 2) {
      r = Mult(r, m);
    }
    m = Mult(m, m);
    b /= 2;
  }
  return r;
}

Matrix Sum(int a) {
  return Mult(drz[a].st, drz[a].nd);
}

void Upd(int a) {
  if (a >= M) { return; } 
  drz[a].st = Add(Sum(2 * a), Sum(2 * a + 1));
}

void Mult(int a, int b, Matrix m) {
  a += M - 1;
  b += M - 1;
  drz[a].nd = Mult(drz[a].nd, m);
  if (a != b) {
    drz[b].nd = Mult(drz[b].nd, m);
  }
  while (a) {
    if (a / 2 != b / 2) {
      if (a % 2 == 0) {
        drz[a + 1].nd = Mult(drz[a + 1].nd, m);
      }
      if (b % 2 == 1) {
        drz[b - 1].nd = Mult(drz[b - 1].nd, m);
      }
    }
    Upd(a);
    if (a != b) {
      Upd(b);
    }
    a /= 2;
    b /= 2;
  }
}

int Read(int a, int b) {
  a += M - 1;
  b += M - 1;
  Matrix l = Id();
  Matrix r{0, 0, 0, 0};
  if (a != b) {
    r = Id();
  }
  while (a) {
    l = Mult(l, drz[a].nd);
    r = Mult(r, drz[b].nd);
    if (a / 2 != b / 2) {
      if (a % 2 == 0) {
        l = Add(l, Sum(a + 1));
      }
      if (b % 2 == 1) {
        r = Add(r, Sum(b - 1));
      }
    }
    a /= 2;
    b /= 2;
  }
  Matrix s = Add(l, r);
  debug(s[0], s[1], s[2], s[3]);
  return s[1];
}



int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  REP (i, 2 * M + 5) {
    drz[i].st = drz[i].nd = Id();
  }
  FORD (i, M - 1, 1) {
    Upd(i);
  }
  int n, m;
  cin>>n>>m;
  
  Matrix fib{1, 1, 1, 0};
  RE (i, n) {
    int a;
    cin>>a;
    Mult(i, i, spow(fib, a));
    //drz[i - 1].nd = spow(fib, a);
  }
  RE (i, m) {
    int t, l, r;
    cin>>t>>l>>r;
    if (t == 1) {
      int x;
      cin>>x;
      Mult(l, r, spow(fib, x));
    } else {
      cout<<Read(l, r)<<"\n";
    }
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
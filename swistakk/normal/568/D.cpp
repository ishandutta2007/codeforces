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

struct Frac {
  int p, q;
  Frac(int p_, int q_) {
    int g = __gcd(p_, q_);
    if (g) {
      p = p_ / g;
      q = q_ / g;
    }
    if (q < 0) {
      q *= -1;
      p *= -1;
    }
  }
//   Frac operator+(Frac f) {
//     return Frac(p * f.q + f.p * q, q * f.q);
//   }
  bool operator<(const Frac& f) const {
    if (p != f.p) {
      return p < f.p;
    }
    return q < f.q;
  }
  bool operator==(const Frac& f) const {
    return p == f.p && q == f.q;
  }
};

struct Point {
  Frac x, y;
  bool operator<(const Point& f) const {
    if (!(x == f.x)) {
      return x < f.x;
    }
    return y < f.y;
  }
  bool operator==(Point p) {
    return x == p.x && y == p.y;
  }
};

struct Line {
  int A, B, C, id;
};

bool Parallel(Line l1, Line l2) {
  return (l1.A * l2.B == l2.A * l1.B);
}

Point Inter(Line l1, Line l2) {
  int det = l1.B * l2.A - l2.B * l1.A;
  return Point{Frac(l2.C * l1.B - l1.C * l2.B, det), Frac(l2.C * l1.A - l1.C * l2.A, det)};
}

bool Common(Line l1, Line l2, Line l3) {
  if (Parallel(l1, l2) || Parallel(l2, l3)) {
    return false;
  }
  return Inter(l1, l2) == Inter(l2, l3);
}

VPII res;

bool Rec(vector<Line>& lines, int k) {
  int n = SZ(lines);
  debug2(n, k);
  if (k <= 0) {
    return (n <= 0);
  }
  if (n <= k) {
    for (auto x : lines) {
      res.PB({x.id, -1});
    }
    return true;
  }
  int m = n;
  int min_sz = (n + k - 1) / k;
  if (n > k * k) {
    m = k * k + 1;
    min_sz = k + 1;
  }
  set<Point> branched;
  REP (i, m) {
    FOR (j, i + 1, m - 1) {
      if (Parallel(lines[i], lines[j])) {
        continue;
      }
      vector<int> here{i, j};
      Point ziom = Inter(lines[i], lines[j]);
      if (branched.count(ziom)) {
        continue;
      }
      branched.insert(ziom);
      FOR (l, j + 1, m - 1) {
        if (Common(lines[i], lines[j], lines[l])) {
          here.PB(l);
        }
      }
      if (SZ(here) >= min_sz) {
        vector<Line> rest;
        res.PB({lines[i].id, lines[j].id});
        for (int l = 0; l < n; l++) {
          if (l != i && l != j && !Common(lines[i], lines[j], lines[l])) {
            rest.PB(lines[l]);
          }
        }
        
        int hehs = Rec(rest, k - 1);
        if (n > k * k) {
          return hehs;
        } else {
          if (hehs) {
            return true;
          }
          res.pop_back();
        }
      }
    }
  }
  return false;
}
    

#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make2(int, n, k);
  vector<Line> lines;
  RE (i, n) {
    make3(int, A, B, C);
    lines.PB({A, B, C, i});
  }
  debug(Common(lines[0], lines[1], lines[2]));
  if (Rec(lines, k)) {
    cout<<"YES\n"<<SZ(res)<<endl;;
    assert(SZ(res) <= k);
    for (auto p : res) {
      cout<<p.st<<" "<<p.nd<<endl;
    }
  } else {
    cout<<"NO\n";
  }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
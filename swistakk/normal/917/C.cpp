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
template<class T> ostream& operator<<(ostream& out, set<T> vec) { out<<"("; for (auto& v: vec) out<<v<<", "; return out<<")"; }

const int N = 72;
const int kInf = 1e18;

struct Matrix {
  array<array<int, N>, N> d;
  array<int, N>& operator[](int a) {
    return d[a];
  }
  Matrix() {
    REP (i, N) {
      REP (j, N) {
        d[i][j] = kInf;
      }
    }
  }
};

Matrix Id() {
  Matrix res;
  REP (i, N) {
    res[i][i] = 0;
  }
  return res;
}

Matrix Mult(Matrix& L, Matrix R) {
  Matrix res; 
  REP (i, N) {
    REP (j, N) {
      REP (k, N) {
        mini(res[i][j], L[i][k] + R[k][j]);
      }
    }
  }
  return res;
}

Matrix Pow(Matrix A, int b) {
  Matrix R = Id();
  while (b) {
    if (b % 2) {
      R = Mult(R, A);
    }
    A = Mult(A, A);
    b /= 2;
  }
  return R;
}
void Print(Matrix& M, int d) {
  cerr<<"M"<<d<<endl;
  REP (i, d) {
    REP (j, d) {
      if (M[i][j] >= kInf / 2) {
        cerr<<"oo ";
      } else {
        cerr<<M[i][j]<<" ";
      }
    }
    cerr<<endl;
  }
}
int c[N]; 
int32_t main() {

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  cerr << fixed << setprecision(10);
  cin.tie(0);
  //double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  int x, k, n, q;
  cin>>x>>k>>n>>q;
  VI mapuj(1 << k);
  VI inv(1 << k);
  //int cnt = 0;
  VI subsets;
  REP (mask, 1 << k) {
    if (__builtin_popcount(mask) == x) {
      mapuj[mask] = SZ(subsets);
      inv[SZ(subsets)] = mask;
      subsets.PB(mask);
    }
  }
  debug(subsets);
  RE (i, k) {
    cin>>c[i];
  }
  Matrix typical;
  for (auto sub : subsets) {
    if (sub % 2 == 0) {
      typical[mapuj[sub]][mapuj[sub / 2]] = 0;
    } else {
      int rem = sub / 2;
      RE (i, k) {
        if ((sub & (1 << i)) == 0) {
          typical[mapuj[sub]][mapuj[rem + (1 << (i - 1))]] = c[i];
        }
      }
    }
  }
  Print(typical, SZ(subsets));
  VPII spec;
  RE (i, q) {
    int p, w;
    cin>>p>>w;
    spec.PB({p, w});
  }
  sort(ALL(spec));
  auto GetAtX = [&](int pos) { // macierz ktorej ostatni element odpowiada x=pos
    Matrix res;
    for (auto sub : subsets) {
      if (sub % 2 == 0) {
        res[mapuj[sub]][mapuj[sub / 2]] = 0;
      } else {
        int rem = sub / 2;
        RE (i, k) {
          // ziom skacze na pos - (k - i)
          int to = pos - (k - i);
          int bon = 0;
          for (auto spe : spec) {
            if (spe.st == to) {
              bon = spe.nd;
            }
          }
          if ((sub & (1 << i)) == 0) {
            res[mapuj[sub]][mapuj[rem + (1 << (i - 1))]] = c[i] + bon;
          }
        }
      }
    }
    return res;
  };
  Matrix cur_mat = Id();
  //Print(cur_mat, SZ(subsets));
  int cur_step = x;
  while (cur_step < n) {
    int beg = cur_step - k + 1;
    int fir_atleast_beg = n + 1;
    for (auto spe : spec) {
      if (spe.st >= beg) {
        mini(fir_atleast_beg, spe.st);
      }
    }
    if (fir_atleast_beg <= cur_step + 1) {
      cur_mat = Mult(cur_mat, GetAtX(cur_step + 1));
      cur_step++;
    } else {
      int steps_to_do = fir_atleast_beg - cur_step - 1;
      cur_mat = Mult(cur_mat, Pow(typical, steps_to_do));
      cur_step = fir_atleast_beg - 1;
    }
    debug(cur_step);
    //Print(cur_mat, SZ(subsets));
  }
  int start_mask = 0;
  FORD (i, k - 1, k - x) {
    start_mask += (1 << i);
  }
  int cur_mask = start_mask;
  int res = kInf;
  while (1) {
    mini(res, cur_mat[mapuj[start_mask]][mapuj[cur_mask]]);
    if (cur_mask % 2 == 0) {
      cur_mask /= 2;
      cur_mat = Mult(cur_mat, GetAtX(cur_step + 1));
      cur_step++;
      //cur_mat = Mult(cur_mat, typical);
    } else {
      break;
    }
  }
  cout<<res<<endl;

  
  return 0;
}
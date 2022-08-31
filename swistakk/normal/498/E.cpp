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

const int R = 7;
const int P = 1e9 + 7;
struct Matrix {
  int side;
  long long M;
  vector<vector<long long> > mat;
  static const long long kDefaultMod = 1ll << 62;
  
  Matrix (int _side = 0, long long _M = kDefaultMod) {
    side = _side;
    M = _M;
    do_resize(side);
  }
  
  void do_resize(int side_) {
    side = side_;
    mat.resize(side_);
    REP (i, side_) {
      mat[i].resize(side_);
    }
  }
  
  vector<long long>& operator[](int a) {
    return mat[a];
  }
  
  Matrix operator*(Matrix& mat2) {
    if (side != mat2.side || M != mat2.M) {
      return Matrix();
    }
    Matrix copy = mat2;
    Matrix prod = Matrix(side, M);
    REP (i, side) {
      REP (j, side) {
        prod[i][j] = 0;
        REP (k, side) {
          prod[i][j] += mat[i][k] * copy[k][j];
          prod[i][j] %= M;
        }
      }
    }
    return prod;
  }
  
  Matrix& operator=(Matrix& mat2) {
    if (side != mat2.side) {
      side = mat2.side;
      do_resize(side);
    }
    
    REP (i, side) {
      REP (j, side) {
        mat[i][j] = mat2[i][j];
      }
    }
    return *this;
  }
  
  Matrix& operator*=(Matrix& mat2) {
    Matrix copy = *this;
    Matrix tmp = copy * mat2;
    REP (i, side) {
      REP (j, side) {
        mat[i][j] = tmp[i][j];
      }
    }
    return *this;
  }
  
  Matrix operator+(Matrix& mat2) {
    if (side != mat2.side || M != mat2.M) {
      return Matrix();
    }
    Matrix copy = mat2;
    Matrix prod = Matrix(side, M);
    REP (i, side) {
      REP (j, side) {
        prod[i][j] = (mat[i][j] + mat2[i][j]) % M;
      }
    }
    return prod;
  }
  
  Matrix& operator+=(Matrix& mat2) {
    Matrix copy = *this;
    Matrix tmp = copy + mat2;
    REP (i, side) {
      REP (j, side) {
        mat[i][j] = tmp[i][j];
      }
    }
    return *this;
  }
  
  Matrix& pow(long long exp) {
    Matrix act = Matrix::get_id(side, M);
    //cout<<side<<"lol "<<act<<"\n";
    Matrix tmp = *this;
    while (exp) {
      if (exp & 1) {
        act *= tmp;
      }
      tmp *= tmp;
      exp /= 2;
    }
    *this = act;
    //cout<<"lol "<<act<<"\n";
    return *this;
  }
  
  long long trace() {
    long long tmp = 0;
    REP (i, side) {
      tmp += mat[i][i];
      tmp %= M;
    }
    return tmp;
  }
  
  static Matrix get_id(int side, long long M = kDefaultMod) {
    Matrix id = Matrix(side, M);
    REP (i, side) {
      id[i][i] = 1;
    }
    return id;
  }
  
  static Matrix get_to_fib(ll M = kDefaultMod) {
    Matrix m(2, M);
    m[1][1] = m[1][2] = m[2][1] = 1;
    return m;
  }
    
  friend ostream& operator<<(ostream& out, Matrix& m);
};
 
ostream& operator<<(ostream& out, Matrix& m) {
  out << "Matrix' side: " << m.side << "\n";
  REP (i, m.side) {
    out << "(";
    REP (j, m.side) {
      out << m[i][j];
      if (j != m.side - 1) {
        out << ", ";
      }
    }
    out << ")\n";
  }
  return out;
}

Matrix mats[R + 2];
int w[R + 2];
#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  Matrix m = Matrix::get_id(4, P);
  //cout<<m<<endl;
  
  RE (i, R) {
    cin>>w[i];
  }
  RE (i, R) {
    mats[i].do_resize(1 << i);
    mats[i].M = P;
    REP (left, (1 << i)) {
      REP (right, (1 << i)) {
        int dp[2] = {0, 1};
        REP (bit, i) {
          int new_dp[2];
          if ((left & (1 << bit)) == 0 && (right & (1 << bit)) == 0) {
            new_dp[1] = dp[0];
          } else {
            new_dp[1] = dp[0] + dp[1];
          }
          new_dp[0] = dp[0] + dp[1];
          REP (tr, 2) {
            dp[tr] = new_dp[tr] % P;
          }
        }
        mats[i][left][right] = dp[1];
      }
    }
  }
  //Matrix H = mats[3].pow(7);
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      cerr<<mats[3][i][j]<<" ";
    }
    cerr<<"\n";
  }
  vector<int> vec_old(1 << R);
  vec_old[0] = 1;
  RE (i, R) {
    //mats[i].do_resize(1 << R);
    mats[i].pow(w[i]);
    if (i <= 3) {
      REP (j, 1 << i) {
        REP (k, 1 << i) {
          cerr<<mats[i][j][k]<<" ";
        }
        cerr<<"\n";
      }
    }
    vector<int> vec_new(1 << i);
    REP (j, 1 << i) {
      REP (k, 1 << i) {
        vec_new[j] = (vec_new[j] + vec_old[k] * mats[i][j][k]) % P;
      }
    }
    REP (j, 1 << i) {
      vec_old[j] = vec_new[j];
    }
    debug(i);
    debugv(vec_old);
  }
  cout<<vec_old[0]<<"\n";
    
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  return 0;
}
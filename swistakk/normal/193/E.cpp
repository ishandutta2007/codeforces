#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <iomanip>
#include <assert.h>
#define MP make_pair
#define PB push_back
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#ifdef LOCAL
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debugv(x)
#endif
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
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.X << ", " << pair.Y << ")";}

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
  
  void do_resize(int side) {
    mat.resize(side + 1);
    for (int i = 0; i <= side; i++) {
      mat[i].resize(side + 1);
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
    for (int i = 1; i <= side; i++) {
      for (int j = 1; j <= side; j++) {
        prod[i][j] = 0;
        for (int k = 1; k <= side; k++) {
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
    
    for (int i = 1; i <= side; i++) {
      for (int j = 1; j <= side; j++) {
        mat[i][j] = mat2[i][j];
      }
    }
    return *this;
  }
  
  Matrix& operator*=(Matrix& mat2) {
    Matrix copy = *this;
    Matrix tmp = copy * mat2;
    for (int i = 1; i <= side; i++) {
      for (int j = 1; j <= side; j++) {
        mat[i][j] = tmp[i][j];
      }
    }
    return *this;
  }
  
  Matrix& pow(long long exp) {
    Matrix act = Matrix::get_id(side, M);
    Matrix tmp = *this;
    while (exp) {
      if (exp & 1) {
        act *= tmp;
      }
      tmp *= tmp;
      exp /= 2;
    }
    *this = act;
    return *this;
  }
  
  long long trace() {
    long long tmp = 0;
    for (int i = 1; i <= side; i++) {
      tmp += mat[i][i];
      tmp %= M;
    }
  }
  
  static Matrix get_id(int side, long long M = kDefaultMod) {
    Matrix id = Matrix(side, M);
    for (int i = 1; i <= side; i++) {
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
  for (int i = 1; i <= m.side; i++) {
    out << "(";
    for (int j = 1; j <= m.side; j++) {
      out << m[i][j];
      if (j != m.side) {
        out << ", ";
      }
    }
    out << ")\n";
  }
  return out;
}

ll fib(ll pot, ll mod) {
  Matrix act = Matrix::get_id(2, mod);
  Matrix m(2, mod);
  m[1][1] = m[1][2] = m[2][1] = 1;
  while (pot) {
    if (pot & 1) {
      act *= m;
    }
    m *= m;
    pot /= 2;
  }
  return act[1][2];
}

const int N = 10001 * 1001;
ll f[N];

int main()
{
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  
  ll reszta;
  // while(cin>>reszta) {
  cin>>reszta;
  ll _5to9 = 1;
  RE (i, 9) {
    _5to9 *= 5;
  }
  
  ll _5to13 = _5to9 * 625;
  
  const ll M = 1e13;
  f[1] = 1;
  FOR (i, 2, 4 * _5to9 - 1) {
    f[i] = f[i - 1] + f[i - 2];
    f[i] %= _5to9;
    /* f[i] %= M;
    if (i <= 100) {
      cout<<f[i]<<" ";
      if (i % M == 0) {
        cout<<endl;
      }
    }  */
  }
  
  vector<ll> kandydaci;
  REP (i, 4 * _5to9) {
    if (reszta % _5to9 == f[i]) {
      kandydaci.PB(i);
    }
  }
  
  
  vector<ll> nowi;
  
  for (ll x : kandydaci) {  
    ll period = 4 * _5to9;
    Matrix period_fib = Matrix::get_to_fib(_5to13).pow(period);
    Matrix act = Matrix::get_to_fib(_5to13).pow(x);
    REP (i, 625) {
      ll ind = x + i * period;
      if (act[1][2] == reszta % _5to13) {
        nowi.PB(ind);
      }
      act *= period_fib;
    }
  }
  
  vector<ll> nowsi;
  
  
  for (ll x : nowi) {
    //cout<<x<<" ";
    ll heheczki = 1 << 13;
    ll period = 4 * _5to13;
    Matrix period_fib = Matrix::get_to_fib(heheczki).pow(period);
    Matrix act = Matrix::get_to_fib(heheczki).pow(x);
    REP (i, heheczki) {
      ll ind = x + i * 4 * _5to13;
      if (act[1][2] == reszta % heheczki) {
        nowsi.PB(ind);
      }
      act *= period_fib;
    }
  }
  //cout<<endl;
  //cout<<SZ(nowsi)<<endl;
  sort(ALL(nowsi));
  if (nowsi.empty()) {
    cout<<"-1\n";
  } else {
    cout<<nowsi[0]<<"\n";
  }
  
  /* while (1) {
    int a;
    cin>>a;
    cout<<f[a]<<endl;
  } */
  //}
  
  
  // nie zapomnij o ll
  return 0;
}
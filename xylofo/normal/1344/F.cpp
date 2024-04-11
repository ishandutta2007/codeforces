#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


#ifdef LOCAL
#include "pretty_debug.h"
#else
#define debug(...) //ignore
#endif

void bad(string s = "NO") {
  cout << s << endl;
  exit(0);
}

typedef bitset<2000> bs;

int solveLinear(vector<bs>& A, vi& b, bs& x, int m) {
  int n = sz(A), rank = 0, br;
  assert(m <= sz(x));
  vi col(m); iota(all(col), 0);
  rep(i,0,n) {
    for (br=i; br<n; ++br) if (A[br].any()) break;
    if (br == n) {
      rep(j,i,n) if(b[j]) return -1;
      break;
    }
    int bc = (int)A[br]._Find_next(i-1);
    swap(A[i], A[br]);
    swap(b[i], b[br]);
    swap(col[i], col[bc]);
    rep(j,0,n) if (A[j][i] != A[j][bc]) {
      A[j].flip(i); A[j].flip(bc);
    }
    rep(j,i+1,n) if (A[j][i]) {
      b[j] ^= b[i];
      A[j] ^= A[i];
    }
    rank++;
  }

  x = bs();
  for (int i = rank; i--;) {
    if (!b[i]) continue;
    x[col[i]] = 1;
    rep(j,0,i) b[j] ^= A[j][i];
  }
  return rank; // (multiple solutions if rank < m)
}


template<class T, int N> struct Matrix {
  typedef Matrix M;
  array<array<T, N>, N> d{};
  M operator*(const M& m) const {
    M a;
    rep(i,0,N) rep(j,0,N)
      rep(k,0,N) a.d[i][j] ^= d[i][k]&m.d[k][j];
    return a;
  }
};
using B = Matrix<bool,2>;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);

  // E/W = 00
  // R = 01
  // B = 10
  // Y = 11

  int n, k;
  cin >> n >> k;

  vector<B> per(n);
  rep(i,0,n) per[i].d[0][0] = per[i].d[1][1] = 1;

  vector<bs> eq;
  vi b;

  rep(_,0,k) {
    string s;
    int r,x;
    cin>>s>>r;

    if(s == "mix") {
      bs b1, b2;
      rep(i,0,r) {
        cin>>x;
        --x;
        if(per[x].d[0][0]) b1.set(2*x);
        if(per[x].d[0][1]) b1.set(2*x+1);
        if(per[x].d[1][0]) b2.set(2*x);
        if(per[x].d[1][1]) b2.set(2*x+1);
      }
      eq.emplace_back(b1);
      eq.emplace_back(b2);
      cin>>s;
      if(s == "W") { b.emplace_back(0); b.emplace_back(0); }
      if(s == "R") { b.emplace_back(0); b.emplace_back(1); }
      if(s == "B") { b.emplace_back(1); b.emplace_back(0); }
      if(s == "Y") { b.emplace_back(1); b.emplace_back(1); }
      continue;
    }

    B a;
    if(s == "RB") a.d[0][1] = a.d[1][0] = 1;
    if(s == "RY") a.d[0][0] = a.d[1][1] = a.d[0][1] = 1;
    if(s == "YB") a.d[0][0] = a.d[1][1] = a.d[1][0] = 1;

    rep(i,0,r) {
      cin>>x;
      --x;
      per[x] = a*per[x];
    }
  }

  bs sol;
  int t = solveLinear(eq,b,sol,2*n);
  if(t == -1) bad();
  cout << "YES" << endl;

  string ans;
  rep(i,0,n) {
    if(sol[2*i] == 0 && sol[2*i+1] == 0) ans += '.';
    if(sol[2*i] == 0 && sol[2*i+1] == 1) ans += 'R';
    if(sol[2*i] == 1 && sol[2*i+1] == 0) ans += 'B';
    if(sol[2*i] == 1 && sol[2*i+1] == 1) ans += 'Y';
  }
  cout << ans << endl;
}
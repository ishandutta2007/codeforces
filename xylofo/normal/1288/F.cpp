#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(i, a) for(auto& i : a)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


typedef double T; // long double, Rational, double + mod<P>...
typedef vector<T> vd;
typedef vector<vd> vvd;

const T eps = 1e-8, inf = 1/.0;
#define MP make_pair
#define ltj(X) if(s == -1 || MP(X[j],N[j]) < MP(X[s],N[s])) s=j

struct LPSolver {
  int m, n;
  vi N, B;
  vvd D;

  LPSolver(const vvd& A, const vd& b, const vd& c) :
    m(sz(b)), n(sz(c)), N(n+1), B(m), D(m+2, vd(n+2)) {
      rep(i,0,m) rep(j,0,n) D[i][j] = A[i][j];
      rep(i,0,m) { B[i] = n+i; D[i][n] = -1; D[i][n+1] = b[i];}
      rep(j,0,n) { N[j] = j; D[m][j] = -c[j]; }
      N[n] = -1; D[m+1][n] = 1;
    }

  //vi tmp;
  void pivot(int r, int s) {
    T *a = D[r].data(), inv = 1 / a[s];
    //tmp.clear(); // tmp -> speedup when input sparse
    //rep(i,0,n+2) if(abs(a[i]) > eps) tmp.push_back(i);
    rep(i,0,m+2) if (i != r && abs(D[i][s]) > eps) {
      T *b = D[i].data(), inv2 = b[s] * inv;
      rep(j,0,n+2) b[j] -= a[j] * inv2;
      //for(int j : tmp) b[j] -= a[j] * inv2;
      b[s] = a[s] * inv2;
    }
    rep(j,0,n+2) if (j != s) D[r][j] *= inv;
    rep(i,0,m+2) if (i != r) D[i][s] *= -inv;
    D[r][s] = inv;
    swap(B[r], N[s]);
  }

  bool simplex(int phase) {
    int x = m + phase - 1;
    for (;;) {
      int s = -1;
      rep(j,0,n+1) if (N[j] != -phase) ltj(D[x]);
      if (D[x][s] >= -eps) return true;
      int r = -1;
      rep(i,0,m) {
        if (D[i][s] <= eps) continue;
        if (r == -1 || MP(D[i][n+1] / D[i][s], B[i])
            < MP(D[r][n+1] / D[r][s], B[r])) r = i;
      }
      if (r == -1) return false;
      pivot(r, s);
    }
  }

  T solve(vd &x) {
    int r = 0;
    rep(i,1,m) if (D[i][n+1] < D[r][n+1]) r = i;
    if (D[r][n+1] < -eps) {
      pivot(r, n);
      if (!simplex(2) || D[m+1][n+1] < -eps) return -inf;
      rep(i,0,m) if (B[i] == -1) {
        int s = 0;
        rep(j,1,n+1) ltj(D[i]);
        pivot(i, s);
      }
    }
    bool ok = simplex(1); x = vd(n);
    rep(i,0,m) if (B[i] < n) x[B[i]] = D[i][n+1];
    return ok ? D[m][n+1] : inf;
  }
};


void bad(string s = "-1") {
  cout << s << endl;
  exit(0);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n1, n2, m, cost_r, cost_b;
  cin >> n1 >> n2 >> m >> cost_r >> cost_b;
  int n = n1 + n2;
  string s1, s2;
  cin>>s1>>s2;
  string s = s1 + s2;

  vector<vi> adj(n);
  rep(i,0,m) {
    int u,v;
    cin>>u>>v;
    --u,--v;
    v += n1;
    adj[u].push_back(i);
    adj[v].push_back(i);
  }

  auto red = [&](int i) {return i;};
  auto blue = [&](int i) {return i+m;};

  vvd A;
  vd b;
  rep(i,0,m) {
    vd row(2*m,0);
    row[red(i)] = 1;
    row[blue(i)] = 1;
    A.emplace_back(row);
    b.emplace_back(1);
  }

  rep(i,0,n) {
    if(s[i] == 'U') {
      // skip
    }
    else if(s[i] == 'R') {
      vd row(2*m,0);
      for(int x : adj[i]) {
        row[red(x)] = -1;
        row[blue(x)] = 1;
      }
      A.emplace_back(row);
      b.emplace_back(-1);
    }
    else if(s[i] == 'B') {
      vd row(2*m,0);
      for(int x : adj[i]) {
        row[red(x)] = 1;
        row[blue(x)] = -1;
      }
      A.emplace_back(row);
      b.emplace_back(-1);
    }
    else assert(false);
  }

  vd c(2*m,0);
  rep(i,0,m) {
    c[red(i)] = -cost_r;
    c[blue(i)] = -cost_b;
  }

  LPSolver simplex(A,b,c);
  vd xx;
  auto ans = simplex.solve(xx);
  if(ans == -inf) bad();

  ll ans2 = 0;
  rep(i,0,m) {
    if(xx[red(i)] > 0.5) ans2 += cost_r;
    else if(xx[blue(i)] > 0.5) ans2 += cost_b;
  }

  cout << ans2 << endl;
  rep(i,0,m) {
    if(xx[red(i)] > 0.5) cout << 'R';
    else if(xx[blue(i)] > 0.5) cout << 'B';
    else cout << 'U';
  }
  cout << endl;
}
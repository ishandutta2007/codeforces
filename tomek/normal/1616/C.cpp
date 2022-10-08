#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int _n=(n), i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << endl;

void init_io() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
}

inline bool in_line(int x0, int y0, int x1, int y1, int x2, int y2) {
  x1 -= x0;
  y1 -= y0;
  x2 -= x0;
  y2 -= y0;

  return x1 * y2 - x2 * y1 == 0;
}

int count_replacements(const vector<int> &array, int aa, int bb) {
  int res = 0;
  REP(i, int(array.size())) {
    if (i != aa && i != bb && !in_line(aa, array[aa], bb, array[bb], i, array[i])) {
      ++res;
    }
  }
  return res;
}

int solve_one() {
  int n; cin >> n;
  vector<int> array(n);
  for (int &x: array) cin >> x;

  if (n==1) return 0;
  
  int best = n;
  REP(bb, n) REP(aa, bb) {
    int val = count_replacements(array, aa, bb);
    best = min(best, val);
  }
  return best;
}

int main() {
  init_io();

  int ntc; cin >> ntc;
  REP(tc, ntc) {
    auto x = solve_one();
    cout << x << "\n";
  }
}
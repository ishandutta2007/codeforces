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

int solve_one() {
  int n; cin >> n;
  std::map<int, int> cnt;
  REP(i,n) {
    int x; cin >> x;
    if (x<0) x=-x;
    cnt[x] += 1;
  }
  int total = 0;
  for (const auto [k, v] : cnt) {
    int m = k == 0 ? 1 : 2;
    total += min(v, m);
  }
  return total;
}

int main() {
  init_io();

  int ntc; cin >> ntc;
  REP(tc, ntc) {
    auto x = solve_one();
    cout << x << "\n";
  }
}
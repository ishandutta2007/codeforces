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
  vector<int> a(n);
  for (int &x : a) cin >> x;
  int limit; cin >> limit;

  int max0 = 0, max1 = 0, max2 = 0;
  REP(i, n) {
    int new_max0 = max0;
    new_max0 = max(new_max0, max1);
    new_max0 = max(new_max0, max2);

    int new_max1 = 1 + max0;

    int new_max2 = 0;
    if (i-1 >= 0 && a[i-1] + a[i] >= 2 * limit) {
      new_max2 = max(new_max2, 1 + max1);
    }
    if (i-2 >= 0 && a[i-1] + a[i] >= 2 * limit && a[i-2] + a[i-1] + a[i] >= 3 * limit) {
      new_max2 = max(new_max2, 1 + max2);
    }

    max0 = new_max0;
    max1 = new_max1;
    max2 = new_max2;
  }
  
  int res = max0;
  res = max(res, max1);
  res = max(res, max2);

  return res;
}

int main() {
  init_io();

  int ntc; cin >> ntc;
  REP(tc, ntc) {
    auto x = solve_one();
    cout << x << "\n";
  }
}
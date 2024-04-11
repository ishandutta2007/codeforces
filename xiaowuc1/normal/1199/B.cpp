#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

void solve() {
  double h, l;
  cin >> h >> l;
  double ret;
  /*
  ret^2 = (ret-h)^2 + l^2
  ret^2 = ret^2 - 2 * ret * h + h^2 + l^2
  2 * ret * h = h^2 + l ^ 2
  ret = (h^2 + l^2) / 2h
  */
  cout << fixed << setprecision(9) << (h*h+l*l)/(2*h) - h << "\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}
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

int l[1000000];
void solve() {
  int n, x, y;
  cin >> n >> x >> y;
  for(int i = 1; i <= n; i++) cin >> l[i];
  for(int i = 1; i <= n; i++) {
    bool good = true;
    for(int a = 1; a <= x && i-a >= 1; a++) good &= l[i] < l[i-a];
    for(int a = 1; a <= y && i+a <= n; a++) good &= l[i] < l[i+a];
    if(good) {
      cout << i << endl;
      break;
    }
  }
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
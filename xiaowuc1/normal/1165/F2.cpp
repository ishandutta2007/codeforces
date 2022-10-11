#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;

int want[300000];
int n;
int total;
vector<int> sales[300000];
int saled[300000];

bool can(int days) {
  // numSaleNeeded + 2 * (total - numSaleNeeded) == days
  // 2 * total - numSaleNeeded == days
  int numSaleNeeded = 2 * total - days;
  int have = days;
  memset(saled, 0, sizeof(saled));
  for(int i = min(200000, days); i > 0; i--) {
    have = min(have, i);
    for(int out: sales[i]) {
      while(have > 0 && saled[out] < want[out]) {
        saled[out]++;
        numSaleNeeded--;
        have--;
      }
    }
  }
  return numSaleNeeded <= 0;
}

void solve() {
  int m;
  cin >> n >> m;
  for(int i = 1; i <= n; i++) {
    cin >> want[i];
    total += want[i];
  }
  while(m--) {
    int d, t;
    cin >> d >> t;
    sales[d].push_back(t);
  }
  int lhs = total;
  int rhs = 2*total;
  while(lhs != rhs) {
    int mid = (lhs+rhs)/2;
    if(can(mid)) rhs = mid;
    else lhs = mid+1;
  }
  cout << lhs << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}
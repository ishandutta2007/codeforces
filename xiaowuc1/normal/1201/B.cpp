#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
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

ll l[1000005];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i];
  }
  sort(l, l+n);
  ll tot = 0;
  for(int i = 0; i < n; i++) {
    tot += l[i];
  }
  if(tot%2 == 0 && 2 * l[n-1] <= tot) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <fstream>

#define pii pair<ll,ll>
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
using namespace std;

ll n, t, k, x, y, m;
ll a[100500], b[100500];
string s;

int main() {
  cin >> t;
  for (int ii = 0; ii < t; ii++){
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n == 3) {
      if (a[1] % 2) {
      cout << "-1\n";
      } else {
        cout << a[1] / 2 << "\n";
      }
      continue;
    }
    ll k = 0;
    for (int i = 1; i < n - 1; i++) {
      k += a[i];
    }
    if (k == n-2) {
      cout << "-1\n";
      continue;
    }
    ll ans = 0;
    for (int i = 1; i < n-1; i++) {
      ans += (a[i] + 1) / 2;
    }
    cout << ans << "\n";
  }
  return 0;
}
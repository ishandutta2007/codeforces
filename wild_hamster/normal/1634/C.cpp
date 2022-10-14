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

ll n, t, k, x, y;
ll a[55555], b[55555];
string s;

int main() {
  cin >> t;
  for (int ii = 0; ii < t; ii++) {
    cin >> n >> k;
    if (k == 1) {
      cout << "YES\n";
      for (int i = 0; i < n; i++) {
        cout << i + 1 << "\n";
      }
      continue;
    }
    if (n % 2 == 1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < k; j++) {
        cout << 1 + (i % 2) + j * 2 + (i / 2) * 2 * k << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
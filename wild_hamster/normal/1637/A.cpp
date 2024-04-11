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
  for (int ii = 0; ii < t; ii++) {
    cin >> n;
    bool x = false;
    for (int j = 0; j < n; j++) {
      cin >> a[j];
      if (j > 0 && a[j-1] > a[j]) {
        x = true;
      }
    }
    if (x) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
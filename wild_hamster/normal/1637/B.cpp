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
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      for (int k = i; k <= j; k++) {
        ans += (a[k] == 0);
      }
      ans += j - i + 1;
    }
  }
  cout << ans << "\n";
  }
  return 0;
}
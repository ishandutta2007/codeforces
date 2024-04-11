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

ll n, t, k;
ll a[55555], b[55555];
string s;

int main() {
  cin >> t;
  for (int ii = 0; ii < t; ii++) {
    cin >> n >> k;
    cin >> s;
    ll l = 0;
    for (int i = 0; i < n / 2; i++) {
      if (s[i] != s[n-i-1]) {
        l = 1;
      }
    }
    if (l && k > 0) {
      cout << 2 << "\n";
    } else {
      cout << 1 << "\n";
    }
  }
  return 0;
}
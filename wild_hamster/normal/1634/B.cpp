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
    cin >> n >> x >> y;
    x %= 2;
    y %= 2;
    for (int i = 0; i < n; i++) {
      cin >> k;
      x ^= (k%2);
    }
    cout << (x == y ? "Alice" : "Bob") << "\n";
  }
  return 0;
}
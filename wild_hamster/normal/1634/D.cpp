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
ll ask(ll x, ll y, ll z) {
  cout << "? " << x << " " << y << " " << z << endl;
  ll p;
  cin >> p;
  return p;
}

int main() {
  cin >> t;
  for (int ii = 0; ii < t; ii++) {
    cin >> n;
    ll l, r, mid;
    ll k1 = ask(1, 2, 4);
    ll k2 = ask(1, 3, 4);
    ll k3 = ask(2, 3, 4);
    ll base = ask(1, 2, 3);
    if (k3 >= k1 && k3 >= k2) {
      mid = 1;
      l = 2;
      r = 3;
    }

    if (k2 >= k1 && k2 >= k3) {
      mid = 2;
      l = 1;
      r = 3;
    }

    if (k1 >= k3 && k1 >= k2) {
      mid = 3;
      l = 1;
      r = 2;
    }
    for (int i = 4; i <= n; i++) {
      ll x = ask(l, mid, i);
      ll y = ask(r, mid, i);
      if (base >= x && base >= y) {
        continue;
      }
      if (x > y) {
        base = x;
        r = i;
      } else {
        base = y;
        l = i;
      }
    }
    cout << "! " << l << " " << r << endl;

  }
  return 0;
}
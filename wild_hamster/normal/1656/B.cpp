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
ll a[200500];
map<ll, ll> f, g;
ll ls[200500], rs[200500];
pii L[500500];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a+n);
    ll x = 0;
    for (int i = 0; i < n; i++) {
      if (binary_search(a, a+n, a[i] + k)) {
        x = 1;
      }
    }
    cout << (x ? "YES" : "NO") << "\n";
  }
  return 0;
}
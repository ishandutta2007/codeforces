#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

ll n, x, y, c;

ll half(ll n) {
  return n * (n + 1) / 2;
}

ll solve(ll x, ll y, ll d) {
  if (y > x) swap(x, y);
  if (d < y) return half(d + 1);
  if (d < x) return half(y) + y * (d - y + 1);
  if (d < x + y - 1) return x * y - half(x + y - 2 - d);
  return x * y;
}

ll calc(ll d) {
  return
    solve(n - x, n - y, d) +
    solve(x + 1, y + 1, d) +
    solve(n - x, y + 1, d) +
    solve(x + 1, n - y, d)
    - solve(n - x, 1, d)
    - solve(x + 1, 1, d)
    - solve(1, y + 1, d)
    - solve(1, n - y, d)
    + solve(1, 1, d);
}

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
#endif
  cin >> n >> x >> y >> c;
  --x, --y;
  ll b1 = 0, b2 = 2 * n;
  while (b1 < b2) {
    ll mid = (b1 + b2) / 2;
    if (calc(mid) < c) b1 = mid + 1; else b2 = mid;
  }
  cout << b1 << endl;
  return 0;
}
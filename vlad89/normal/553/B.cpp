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

ll big = 1100000000000000000LL;

void add(ll & a, ll b) {
  a += b;
  if (a > big) a = big;
}

ll solve(vector<int> a) {
  int n = sz(a);
  vector<ll> b (n+1);
  b[0] = 1;
  REP (i, n) {
    if (a[i] == -1 || a[i] == i) {
      add(b[i+1], b[i]);
    }
    if (i + 1 < n && (a[i] == -1 || a[i] == i+1) && (a[i+1] == -1 || a[i+1] == i)) {
      add(b[i+2], b[i]);
    }
  }
  return b[n];
}

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
#endif
  int n;
  long long k;
  cin >> n >> k;
  vector<int> a(n, -1);
  REP (i, n) {
    for (a[i] = 0; a[i] < n; ++a[i]) {
      long long v = solve(a);
      if (v >= k) break;
      k -= v;
    }
  }
  REP (i, n) {
    if (i) cout << ' ';
    cout << (a[i]+1);
  }
  cout << endl;
  return 0;
}
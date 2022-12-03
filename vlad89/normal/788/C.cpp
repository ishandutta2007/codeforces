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

const int N = 2000000;

const int INF = 1000000000;

vi calc(vector<bool> sa) {
  vector<int> a;
  REP (i, sz (sa))
    if (sa[i]) a.pb(i);
  vi x(N + 1, INF);
  x[0] = 0;
  REP (i, N) if (x[i] != INF) {
    for (int q: a) {
      if (q + i <= N && x[q + i] > x[i] + 1) {
	x[q + i] = x[i] + 1;
      }
    }
  }
  return x;
}
	
int main () {
#ifdef LocalHost
  freopen("input_big.txt", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  int k, n;
  cin >> k >> n;
  vector<bool> a(1001), b(1001);
  REP (i, n) {
    int x;
    cin >> x;
    x -= k;
    if (x > 0 && !a[x]) a[x] = true;
    if (x < 0 && !b[-x]) b[-x] = true;
    if (x == 0) {
      cout << 1 << endl;
      return 0;
    }
  }
  vi x = calc(a);
  vi y = calc(b);
  int res = INF;
  FOR (i, 1, sz(x))
    if (x[i] != INF && y[i] != INF) 
      res = min(res, x[i] + y[i]);
  if (res == INF) res = -1;
  cout << res << endl;
  return 0;
}
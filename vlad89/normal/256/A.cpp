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

int n;
int a[4444];
int succ[4444][4444];
int d[4444][4444];

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
#endif
  cin >> n;
  REP (i, n) cin >> a[i];
  REP (i, n) {
    REP (j, n) {
      if (!j) succ[i][j] = -1; else
	if (a[j-1] == a[i]) succ[i][j] = j-1; else succ[i][j] = succ[i][j-1];
    }
  }
  int ans = 1;
  for (int i = n-1; i >= 0; --i) {
    for (int j = i-1; j >= 0; --j) {
      d[i][j] = max(d[i][j], 2);
      if (succ[i][j] != -1) {
	d[j][succ[i][j]] = max(d[j][succ[i][j]], d[i][j] + 1);
      }
      ans = max(ans, d[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}
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

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector<string> a(n);
  REP (i, n) {
    cin >> a[i];
  }
  vector<int> b(n);
  REP (i, n) {
    cin >> b[i];
  }
  vector<int> ans;
  while (1) {
    bool ok = false;
    REP (i, n)
      if (b[i] == 0) {
	ans.pb(i);
	REP (j, n)
	  b[j] -= a[i][j] == '1';
	ok = true;
      }
    if (!ok) break;
  }
  cout << sz(ans) << endl;
  REP (i, sz (ans)) {
    if (i) cout << ' ';
    cout << (ans[i]+1);
  }
  cout << endl;
  return 0;
}
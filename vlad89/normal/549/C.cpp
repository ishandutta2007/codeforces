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

int dp[128][128][2];

int win(int x, int y, int k, int start) {
  memset(dp, 0, sizeof(dp));
  REP (i, x+1) {
    REP (j, y+1) { 
      REP (turn, 2) {
        if (i + j < k) continue;
	if (i + j == k) {
	  dp[i][j][turn] = j & 1 ? 0 : 1;
	  continue;
	}
	if (turn == 0) {
	  dp[i][j][turn] = min(i ? dp[i-1][j][turn^1] : 1, j ? dp[i][j-1][turn^1] : 1);
	} else {
	  dp[i][j][turn] = max(i ? dp[i-1][j][turn^1] : 0, j ? dp[i][j-1][turn^1] : 0);
	}
      }
    }
  }
  return dp[x][y][start];
}

int solve(int x, int y, int k) {
  if (x + y == k) return y & 1 ? 0 : 1;
  if (k & 1) {
    if (y < x - k) return 1;
    return y >= x - k && y <= x + k - 2 && (y&1) != (x&1);
  }
  if (y < x - k || y > x + k) return 1;
  return y >= x - k && y <= x + k && (y&1) == (x&1);
}

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
#endif
  // int k = 1;
  // REP (x, 40) {
  //   REP (y, 40) {
  //     if (x + y < k) cout << '.'; else cout << win(x, y, k, 0);
  //   }
  //   cout << endl;
  // }

  // FOR (k, 1, 20) 
  // REP (x, 50) {
  //   REP (y, 50) {
  //     if (x + y >= k) {
  // 	if (win(x, y, k, 0) != solve(x, y, k)) {
  // 	  cout << "FAILED " << x << ' ' << y << endl;
  // 	}
  //     }
  //   }
  // }
  int n, k;
  cin >> n >> k;
  int x=0, y=0;
  REP (i, n) {
    int g;
    cin >> g;
    if (g & 1) y++; else x++;
  }
  if (solve(x, y, k)) cout << "Daenerys" << endl; else cout << "Stannis" << endl;
  return 0;
}
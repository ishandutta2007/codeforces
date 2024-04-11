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
typedef vector<pii> vpii;
typedef long long ll;

vector<vpii> adj;
vector<int> mark;

bool rec(int x, int v) {
  mark[x] = v;
  for (pii p: adj[x]) {
    if (mark[p.X] != -1) {
      if (mark[p.X] != (v ^ p.Y)) return false;
    } else {
      if (!rec(p.X, v ^ p.Y)) return false;
    }
  }
  return true;
}

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
#endif
  std::ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  adj.resize(n);
  REP (i, m) {
    int x, y, z;
    cin >> x >> y >> z;
    --x, --y;
    z ^= 1;
    adj[x].pb(pii(y, z));
    adj[y].pb(pii(x, z));
  }
  mark.resize(n, -1);
  int res = 1;
  REP (i, n) if (mark[i] == -1) {
    if (!rec(i, 0)) {
      cout << 0 << endl;
      return 0;
    }
    if (i) {
      res *= 2;
      res %= 1000000007;
    }
  }
  cout << res << endl;
  return 0;
}
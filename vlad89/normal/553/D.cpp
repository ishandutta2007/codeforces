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

vector<int> bad;
vector<vi> adj;
int n, m, k;
bool ins[100000];
int decr[100000];

bool solve(long double v) {
  memset(ins, 0, sizeof(ins));
  memset(decr, 0, sizeof(decr));
  vector<int> s = bad;
  REP (i, sz (s)) ins[s[i]] = true;
  for (int i = 0; i < s.size(); ++i) {
    int x = s[i];
    for (int y: adj[x]) if (!ins[y]) {
	decr[y]++;
	if (v * sz(adj[y]) > sz(adj[y]) - decr[y]) {
	  ins[y] = true;
	  s.pb(y);
	}
    }
  }
  return sz(s) < n;
}

int main () {
#ifdef LocalHost
  freopen("input.txt", "r", stdin);
#endif
  ios_base::sync_with_stdio(false);
  cin >> n >> m >> k;
  REP (i, k) {
    int num;
    cin >> num;
    num--;
    bad.pb(num);
  }
  adj.resize(n);
  REP (i, m) {
    int q, w;
    cin >> q >> w;
    --q, --w;
    adj[q].pb(w);
    adj[w].pb(q);
  }
  long double b1 = 0, b2 = 1;
  REP (it, 64) {
    long double mid = (b1 + b2) / 2;
    if (solve(mid)) b1 = mid; else b2 = mid;
  }
  solve(b1);
  int res = 0;
  REP (i, n) if (!ins[i]) ++res;
  cout << res << endl;
  bool first = true;
  REP (i, n) if (!ins[i]) {
    if (!first) cout << ' ';
    cout << (i+1);
    first = false;
  }
  cout << endl;
  return 0;
}
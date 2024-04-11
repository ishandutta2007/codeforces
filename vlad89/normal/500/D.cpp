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

vi adj[100000];
int q[100000], w[100000], e[100000];
long long deg[100000];

void rec(int x, int from) {
  deg[x] = 1;
  REP (i, sz (adj[x])) if (adj[x][i] != from) {
    rec(adj[x][i], x);
    deg[x] += deg[adj[x][i]];
  }
}

int n;

double cost(int g) {
  long long down = min(deg[q[g]], deg[w[g]]);
  return 6.0 * down * (n-down) * e[g];
}

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    REP (i, n-1) {
      cin >> q[i] >> w[i] >> e[i];
      --q[i], --w[i];
      adj[q[i]].pb(w[i]);
      adj[w[i]].pb(q[i]);
    }
    rec(0, -1);
    double sum = 0;
    REP (i, n-1) {
      sum += cost(i);
    }
    int m;
    cin >> m;
    REP (i, m) {
      int x, v;
      cin >> x >> v;
      --x;
      sum -= cost(x);
      e[x] = v;
      sum += cost(x);
      printf("%.9lf\n", ((((double) sum / n) / (n-1))));
    }
    return 0;
}
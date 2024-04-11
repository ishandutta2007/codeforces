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

bool a[312][312];
bool vis[312];

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vi p(n);
    REP (i, n) {
      cin >> p[i];
      p[i]--;
    }
    REP (i, n) {
      string s;
      cin >> s;
      REP (j, n)
	if (s[j] == '1') a[i][j] = true;
    }
    REP (i, n) if (!vis[i]) {
      vis[i] = true;
      vector<int> st;
      st.pb(i);
      for (int cr = 0; cr < sz(st); ++cr) {
	int x = st[cr];
	REP (y, n) if (a[x][y] && !vis[y]) {
	  vis[y] = true;
	  st.pb(y);
	}
      }
      sort(all(st));
      vector<int> order;
      REP (j, sz (st))
	order.pb(p[st[j]]);
      sort(all(order));
      REP (j, sz (st))
	p[st[j]] = order[j];
    }
    REP (i, n) {
      if (i) cout << ' ';
      cout << p[i]+1;
    }
    cout << endl;
    return 0;
}
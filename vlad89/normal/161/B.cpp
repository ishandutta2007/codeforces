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
typedef vector<pii> vpii;

int type[1024], cost[1024];

int main () {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    scanf("%d%d", &n, &k);
    vpii a, b;
    long long ans = 0;
    REP (i, n) {
	int c, t;
	scanf("%d%d", &c, &t);
	if (t == 1)
	    a.pb(pii(c, i));
	else
	    b.pb(pii(c, i));
	type[i] = t;
	cost[i] = c;
	ans += 2*c;
    }
    vector<vector<int> > res(k);
    sort(all(a));
    reverse(all(a));
    REP (i, k) {
	if (i < sz (a)) {
	    res[i].pb(a[i].Y);
	}
    }
    FOR (j, k, sz(a))
	b.pb(a[j]);
    FOR (j, sz(a), k) {
	res[j].pb(b[sz(b)-1].Y);
	b.pop_back();
    }
    REP (j, sz (b))
	res.back().pb(b[j].Y);
    REP (j, sz (res)) {
	bool off = false;
	int u = cost[res[j][0]];
	REP (k, sz (res[j])) {
	    int id = res[j][k];
	    if (type[id] == 1)
		off = true;
	    u = min(u, cost[res[j][k]]);
	}
	if (off)
	    ans -= u;
    }
    cout << ans / 2 << '.' << (ans & 1 ? 5 : 0) << endl;
    REP (i, sz (res)) {
	cout << sz(res[i]);
	REP (j, sz (res[i]))
	    cout << ' ' << res[i][j]+1;
	cout << endl;
    }
    return 0;
}
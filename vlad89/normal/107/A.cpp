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

const int N = 1024;
pii out[N];

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int n, p;
    scanf ("%d%d", &n, &p);
    vector<bool> start;
    REP (i, n)
	start.pb(true);
    REP (i, p) {
	int q, w, e;
	scanf ("%d%d%d", &q, &w, &e);
	--q, --w;
	out[q] = pii (w, e);
	start[w] = false;
    }
    vector<pii> ans;
    vector<int> fl;
    REP (i, n)
	if (start[i] && out[i].Y) {
	    int x, y = out[i].Y;
	    for (x = i; out[x].Y; x = out[x].X)
		y = min(y, out[x].Y);		
	    ans.pb(pii(i, x));
	    fl.pb(y);
	}
    printf("%d\n", sz(ans));
    REP (i, sz (ans))
	printf("%d %d %d\n", ans[i].X+1, ans[i].Y+1, fl[i]);
    return 0;
}
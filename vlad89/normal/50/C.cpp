#include <iostream>
#include <memory.h>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),a.end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) SORT(a),(a).resize(unique(ALL(a))-a.begin())
#define SZ(a) ((int) a.size())
#define pb push_back

#define VAR(a,b) __typeof(b) a=(b)
#define FORE(it,a) for(VAR(it,(a).begin());it!=(a).end();it++)
#define X first
#define Y second
#define DEBUG(x) cout << #x << " = " << x << endl;

#define INF 1000000000

typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long ll;

PII a[123456];
const int inf = -1u/4;

int main() {
    #ifdef LocalHost
    freopen ("input.txt", "r", stdin);
    #endif
    int n;
    scanf ("%d", &n);
    REP (i, n)
	scanf ("%d%d", &a[i].X, &a[i].Y);
    int q = -inf, w = -inf, e = -inf, r = -inf;
    int minx = inf, miny = inf, maxx = -inf, maxy = -inf;
    REP (i, n) {
	q = max (q, a[i].X + a[i].Y);
	w = max (w, -a[i].X + a[i].Y);
	e = max (e, a[i].X -a[i].Y);
	r = max (r, -a[i].X -a[i].Y);

	if (a[i].X < minx) minx = a[i].X;
	if (a[i].Y < miny) miny = a[i].Y;
	if (a[i].X > maxx) maxx = a[i].X;
	if (a[i].Y > maxy) maxy = a[i].Y;
    }
    maxx++;
    maxy++;
    minx--;
    miny--;
    q++;
    w++;
    e++;
    r++;
    int res = 2 * (maxx - minx + maxy - miny) - 
	(maxx + maxy - q + maxy - minx - w + maxx - miny - e - minx - miny - r);
    cout << res << endl;
    return 0;
}
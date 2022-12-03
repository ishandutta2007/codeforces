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

int a[100001];
vector<pair<double, int> > event;
double d[100001];

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
#endif
    int n, l, v1, v2;
    scanf("%d%d%d%d", &n, &l, &v1, &v2);
    REP (i, n) {
	scanf("%d", &a[i]);
    }
    double s = (double) v2 / (v1 + v2) * l;
    int cycle = 0;
    REP (i, n) {
	event.pb(make_pair(a[i] + 0.0, -1));
	double x = a[i] - s;
	if (x < 0) {
	    x += 2 * l;
	    ++cycle;
	}
	event.pb(make_pair(x, 1));
    }
    event.pb(make_pair(0.0, cycle));
    event.pb(make_pair(2.0 * l, 0));
    sort(all(event));
    double ans = 0;
    int res = 0;
    REP (i, sz (event)-1) {
	res += event[i].Y;
	if (res >= 0)
	    d[res] += ((event[i+1].X - event[i].X)) / (2.0 * l);
    }
    REP (i, n+1)
	printf("%.13lf\n", d[i]);
    return 0;
}
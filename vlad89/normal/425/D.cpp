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

map<int, vector<int> > px, py;

bool contains(int y, int x) {
    map<int, vector<int> >::iterator it = py.find(y);
    if (it == py.end()) return false;
    return binary_search(all(it->Y), x);
}

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    REP (i, n) {
	int x, y;
	scanf("%d%d", &x, &y);
	py[y].pb(x);
	px[x].pb(y);
    }
    for (map<int, vector<int> >::iterator it = px.begin(); it != px.end(); ++it) {
	sort(all(it->Y));
    }
    for (map<int, vector<int> >::iterator it = py.begin(); it != py.end(); ++it) {
	sort(all(it->Y));
    }
    long long res = 0;
    for (map<int, vector<int> >::iterator it = px.begin(); it != px.end(); ++it) {
	int x = it->X;
	vector<int> & ys = it->Y;
	if (n / sz(ys) < sz(ys)) {
	    REP (yy, sz(ys)) {
		int y = ys[yy];
		vector<int> & xs = py[y];
		REP (xx, sz(xs)) {
		    int x2 = xs[xx];
		    if (x2 <= x) continue;
		    if (contains(y + x2 - x, x) && contains(y + x2 - x, x2)) {
			++res;
		    }
		}
	    }
	} else {
	    REP (y1, sz(ys)) {
		REP (y2, y1) {
		    if (contains(ys[y1], x + ys[y1] - ys[y2]) && contains(ys[y2], x + ys[y1] - ys[y2])) {
			++res;
		    }
		}
	    }
	}
    }
    cout << res << endl;
    return 0;
}
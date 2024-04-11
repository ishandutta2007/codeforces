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

int n;

bool isgood(int x) {
    while (x) {
	if (x % 10 != 4 && x % 10 != 7) return false;
	x /= 10;
    }
    return true;
}

vector<pii> adj[123456];

int up[123456], down[123456], v[123456];

void rec(int x, int from = -1) {
    v[x] = 1;
    REP (i, sz (adj[x])) {
	int y = adj[x][i].X;
	int g = adj[x][i].Y;	
	if (y == from) continue;
	rec(y, x);
	v[x] += v[y];
	if (g == 1)
	    down[x] += v[y];
	else
	    down[x] += down[y];
    }
}

void rec2(int x, int from = -1) {
    int S = 0;
    REP (i, sz (adj[x])) {
	int y = adj[x][i].X;
	int g = adj[x][i].Y;	
	if (y == from) continue;

	if (g == 1)
	    S += v[y];
	else
	    S += down[y];
    }
    
    REP (i, sz (adj[x])) {
	int y = adj[x][i].X;
	int g = adj[x][i].Y;	
	if (y == from) continue;
	
	if (g == 1) {
	    up[y] = n - v[y];	    
	} else {
	    up[y] = up[x] + S - down[y];
	}

	rec2(y, x);
    }
}

int main () {    
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
#endif
    scanf ("%d", &n);
    int q, w, e;
    REP (i, n-1) {
	scanf ("%d%d%d", &q, &w, &e);
	--q, --w;
	bool c = isgood(e);
	adj[q].pb(pii(w, c));
	adj[w].pb(pii(q, c));
    }
    rec(0);
    rec2(0);
    long long res = 0;
    REP (i, n) {
	res += (long long) (down[i] + up[i]) * (down[i] + up[i] - 1);
	//	cout << up[i] << ' ' << down[i] << endl;
    }
    cout << res << endl;
    return 0;
}
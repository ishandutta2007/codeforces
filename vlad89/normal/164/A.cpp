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

int n, m;
int a[100000];
vi adj[100000], radj[100000];
int sz;
int st[100000];
bool path[100000][2];

void solve(int q, vi adj[100000]) {
    sz = 0;
    REP (i, n) 
	if (a[i] == q) {
	    st[sz++] = i;
	    path[i][q-1] = true;
	}
    for (int cr = 0; cr < sz; ++cr) {
	int x = st[cr];
	for (int i = 0; i < sz(adj[x]); ++i) {
	    int y = adj[x][i];
	    if (!path[y][q-1] && (q != 1 || a[y] != 1)) {
		path[y][q-1] = true;
		if (a[y] != 1) {
		    st[sz++] = y;
		}
	    }
	}
    }
}

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    REP (i, n) {
	scanf("%d", a+i);
    }
    int q, w;
    REP (i, m) {
	scanf("%d%d", &q, &w);
	--q, --w;
	adj[q].pb(w);
	radj[w].pb(q);
    }
    solve(1, adj);
    solve(2, radj);
    REP (i, n) {
	if (path[i][0] && path[i][1]) {
	    printf("1\n");
	} else {
	    printf("0\n");
	}
    }
    return 0;
}
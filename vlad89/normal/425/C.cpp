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

int a[128128];

map<int, vector<int> > bpos;

const int inf = -1u/4;

int d[301];

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
#endif
    int n, m, s, e;
    scanf("%d%d%d%d", &n, &m, &s, &e);
    REP (i, n) scanf("%d", a+i);
    int x;
    REP (i, m) {
	scanf("%d", &x);
	bpos[x].pb(i);
    }
    int max_oper = s / e;
    d[0] = -1;
    int res = 0;
    FOR (i, 1, max_oper + 1) d[i] = inf;
    REP (i, n) {
	vector<int> & x = bpos[a[i]];
	for (int j = max_oper - 1; j >= 0; --j) {
	    if (d[j] != inf) {		
		vector<int>::iterator it = lower_bound(all(x), d[j]+1);
		if (it != x.end()) {
		    d[j+1] = min(d[j+1], *it);
		    if (i+1 + d[j+1]+1 + e * (j + 1) <= s) {
			//			cout << i+1 + d[j+1]+1 + e * (j + 1) << endl;
			res = max(res, j+1);
		    }
		}
	    }
	}
    }
    cout << res << endl;
    return 0;
}
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

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> a (n);
    REP (i, n) {
	cin >> a[i];
    }
    int best = -1u/4;
    best = -best;
    REP (j, n) {
	REP (i, j+1) {
	    vector<int> q, w;
	    int res = 0;
	    REP (k, n) {
		if (k >= i && k <= j) {
		    q.pb(a[k]);
		    res += a[k];
		} else {
		    w.pb(a[k]);
		}
	    }
	    sort(all(q));
	    sort(all(w));
	    reverse(all(w));
	    best = max(best, res);
	    REP (i, min(min(m, sz(q)), sz(w))) {
		res -= q[i];
		res += w[i];
		best = max(best, res);
	    }
	}
    }
    cout << best << endl;
    return 0;
}
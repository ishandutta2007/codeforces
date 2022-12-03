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

const int inf = -1u/4;

int n, m, k;
int a[128][128];

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m >> k;
    REP (i, n) REP (j, m) cin >> a[i][j]; 
    int res = inf;
    if (n <= k) {
	REP (i, 1<<n) {
	    int sum = 0;
	    REP (w, m) {
		int change = 0;
		REP (q, n) {
		    change += a[q][w] != !!(i & (1<<q));
		}
		sum += min(change, n-change);
	    }
	    res = min(res, sum);
	}
    } else {
	REP (i, n) {
	    int sum = 0;
	    REP (q, n) {
		int change = 0;
		REP (w, m) {
		    if (a[i][w] != a[q][w]) {
			++change;
		    }
		}
		sum += min(change, m-change);
	    }
	    res = min(res, sum);
	}
    }
    cout << (res > k ? -1 : res) << endl;
    return 0;
}
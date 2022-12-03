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

vector<pii> trans(vector<pii> a, int p) {
    vector<pii> b;
    int u = sz(a);
    REP (i, u) {
	if (a[i].Y < p) {
	    b.pb(a[i]);
	    continue;
	}
	if (a[i].X > p) {
	    b.pb(pii(a[i].X - p - 1, a[i].Y - p - 1));
	    continue;
	}
	if (a[i].X < p) {
	    b.pb(pii(a[i].X, p-1));
	}
	if (a[i].Y > p) {
	    b.pb(pii(0, a[i].Y - p - 1));
	}
    }
    UN(b);
    return b;
}

int main () {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
#endif
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    l1--, r1--, l2--, r2--;
    vector<pii> a, b;
    a.pb(pii(l1, r1));
    b.pb(pii(l2, r2));
    
    int k = (1<<30) - 1;
    int res = 0;
    while (k) {
	REP (i, sz (a)) {
	    REP (j, sz (b)) {
		res = max(res, min(a[i].Y, b[j].Y) - max(a[i].X, b[j].X) + 1);
	    }
	}
	if (k == 1) break;
	
	a = trans(a, k / 2);
	b = trans(b, k / 2);
	
	k /= 2;
    }
    cout << res << endl;
    return 0;
}
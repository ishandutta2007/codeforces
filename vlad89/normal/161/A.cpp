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

pii a[123456];
pii b[123456];

int main () {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
#endif
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    REP (i, n) {
	scanf("%d", &a[i].X);
	a[i].Y = i;
    }
    REP (i, m) {
	scanf("%d", &b[i].X);
	b[i].Y = i;
    }
    sort(a, a + n);
    sort(b, b + m);
    int j = 0;
    vector<pii> ans;
    REP (i, n) {
	while (j < m && b[j].X < a[i].X - x) ++j;
	if (j < m && b[j].X <= a[i].X + y) {
	    ans.pb(pii(a[i].Y, b[j].Y));
	    ++j;
	}
    }
    printf("%d\n", sz(ans));
    REP (i, sz (ans)) {
	printf("%d %d\n", ans[i].X+1, ans[i].Y+1);
    }
    return 0;
}
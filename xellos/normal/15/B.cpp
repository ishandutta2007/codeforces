#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int T;
	cin >> T;
	while(T--) {
		int n, m, x[2], y[2];
		cin >> n >> m >> x[0] >> y[0] >> x[1] >> y[1];
		int nl = max(-x[0], -x[1]);
		int nr = min(n-x[0], n-x[1]);
		int ml = max(-y[0], -y[1]);
		int mr = min(m-y[0], m-y[1]);
		cat ans = 1LL * n * m - 2LL * (nr-nl) * (mr-ml);
		int nl_o = max(nl + x[0], nl + x[1]);
		int nr_o = min(nr + x[0], nr + x[1]);
		int ml_o = max(ml + y[0], ml + y[1]);
		int mr_o = min(mr + y[0], mr + y[1]);
		if(nl_o < nr_o && ml_o < mr_o)
			ans += 1LL * (nr_o-nl_o) * (mr_o-ml_o);
		cout << ans << "\n";
	}
	return 0;
}

// look at my code
// my code is amazing
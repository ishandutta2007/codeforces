#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;

int bx1, by1, bx2, by2;

int query(int x1, int y1, int x2, int y2, bool swp) {
	if(swp) swap(x1, y1), swap(x2, y2);
	printf("? %d %d %d %d\n", x1, y1, x2, y2); fflush(stdout);
	int ans;
	scanf("%d", &ans);
	if(bx1 >= x1 && bx2 <= x2 && by1 >= y1 && by2 <= y2) ans--;
	return ans;
}

void get_lr(int &xl, int &xr, int mny, int mxy, bool swp) {
	int l = 1, r = n;
	while(l < r) {
		int m = (l + r) / 2;
		if(query(1, mny, m, mxy, swp) == 0) l = m + 1;
		else r = m;
	}
	xr = l;
	l = 1, r = xr;
	while(l < r) {
		int m = (l + r + 1) / 2;
		if(query(m, mny, xr, mxy, swp) == 0) r = m - 1;
		else l = m;
	}
	xl = l;
}

int main() {
	scanf("%d", &n);
	int xl = 1, xr = n, yl = 1, yr = n;
	get_lr(xl, xr, 1, n, false);
	get_lr(yl, yr, xl, xr, true);
	bx1 = xl; by1 = yl; bx2 = xr; by2 = yr;
	int xl2, xr2, yl2, yr2;
	get_lr(xl2, xr2, 1, n, false);
	get_lr(yl2, yr2, xl2, xr2, true);
	printf("! %d %d %d %d %d %d %d %d\n", xl, yl, xr, yr, xl2, yl2, xr2, yr2); fflush(stdout);
}
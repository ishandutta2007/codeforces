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

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

struct no {
	int x; // leaves
	int ql, qr;
	int lpops;
};

void join(no &a, no &b, no &c) {
	c.lpops = b.lpops;
	c.ql = a.ql + a.qr;
	if(c.lpops > c.ql) c.ql = 0, c.lpops -= a.ql + a.qr;
	else c.ql -= c.lpops, c.lpops = 0;
	c.lpops += a.lpops;
	c.qr = b.ql + b.qr;
}

const int N = 112345;
no tr[4 * N];

void upd(int i, int l, int r, int p, int op, int x) {
	//printf("[%d] (%d, %d)\n", i, l, r);
	if(l == r) {
		if(op == 0) {
			tr[i].lpops = 1;
		} else {
			tr[i].lpops = 0;
			tr[i].x = x;
			tr[i].ql = 1;
			//printf("tr[%d].x = %d\n", i, x);
		}
		return;
	}
	int m = (l + r) / 2;
	if(p <= m) upd(2 * i, l, m, p, op, x);
	else upd(2 * i + 1, m + 1, r, p, op, x);
	join(tr[2 * i], tr[2 * i + 1], tr[i]);
	//printf("tr[%d].ql,qr = %d,%d\n", i, tr[i].ql, tr[i].qr);
}

int main() {
	int i, j, m, p, op, x;
	rd(m);
	for(i = 0; i < m; i++) {
		rd(p); p--; rd(op);
		if(op == 1) rd(x);
		upd(1, 0, m - 1, p, op, x);
		//printf("%d + %d\n", tr[1].ql, tr[1].qr);
		if(tr[1].ql + tr[1].qr == 0) { puts("-1"); continue; }
		int g = 1;
		int l = 0, r = m - 1;
		int pos = tr[1].ql + tr[1].qr;
		while(l != r) {
			int mid = (l + r) / 2;
			if(tr[g].ql < pos) {
				pos -= tr[g].ql;
				g = 2 * g + 1;
				l = mid + 1;
			} else r = mid, g = 2 * g;
		}
		//printf("tr[%d].x = %d\n", g, tr[g].x);
		printf("%d\n", tr[g].x);
	}
}
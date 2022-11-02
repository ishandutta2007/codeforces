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
#	define debug(args...) ((void) 0)
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

const int N = 212345;
int dpl[N], dpr[N], a[N];
int tr[N << 2];

void build(int i, int l, int r) {
	tr[i] = 0;
	if(l == r) return;
	int m = (l + r) / 2;
	build(2 * i, l, m);
	build(2 * i + 1, m + 1, r);
}

#define set set_

void set(int i, int l, int r, int p, int x) {
	if(l == r) return (void) (tr[i] = max(tr[i], x));
	int m = (l + r) / 2;
	if(p <= m) set(2 * i, l, m, p, x);
	else set(2 * i + 1, m + 1, r, p, x);
	tr[i] = max(tr[2 * i], tr[2 * i + 1]);
}

int get(int i, int l, int r, int qr) {
	if(l > qr) return INT_MIN;
	if(r <= qr) return tr[i];
	int m = (l + r) / 2;
	return max(get(2 * i, l, m, qr), get(2 * i + 1, m + 1, r, qr));
}

int n;

int main() {
	int i, j;
	int k, l, r;
	rd(k); rd(n);
	while(k--) {
		rd(l); rd(r); l--; r--;
		a[l]++;
		a[r + 1]--;
	}
	for(i = 1; i < n; i++)
		a[i] += a[i - 1];
	dpl[0] = 1;
	const int m = 100000;
	set(1, 0, m, a[0], dpl[0]);
	for(i = 1; i < n; i++) {
		dpl[i] = 1 + get(1, 0, m, a[i]);
		set(1, 0, m, a[i], dpl[i]);
	}
	build(1, 0, m);
	dpr[n - 1] = 1;
	set(1, 0, m, a[n - 1], dpr[n - 1]);
	for(i = n - 2; i >= 0; i--) {
		dpr[i] = 1 + get(1, 0, m, a[i]);
		set(1, 0, m, a[i], dpr[i]);
	}
	int mx = 0;
	for(i = 0; i < n; i++)
		mx = max(mx, dpl[i] + dpr[i] - 1);
	printf("%d\n", mx);
}
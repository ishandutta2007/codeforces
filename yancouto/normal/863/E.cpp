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

int n;

int en = 1;

const int N = 212345;
const int T = N * 4 * 4;

int tr[T], lz[T], L[T], R[T];

int& get(int &i) {
	if(i == 0) {
		i = en++;
		if(en == T) abort();
	}
	return i;
}

void unlaze(int i, int l, int r) {
	if(lz[i] == 0) return;
	tr[i] += lz[i];
	lz[get(L[i])] += lz[i];
	lz[get(R[i])] += lz[i];
	lz[i] = 0;
}

void add(int &i, int l, int r, int ql, int qr) {
	unlaze(get(i), l, r);
	if(l > qr || r < ql) return;
	if(l >= ql && r <= qr) {
		lz[i] = 1;
		unlaze(i, l, r);
		return;
	}
	int m = (l + r) / 2;
	add(L[i], l, m, ql, qr);
	add(R[i], m + 1, r, ql, qr);
	tr[i] = min(tr[L[i]], tr[R[i]]);
}

int get(int &i, int l, int r, int ql, int qr) {
	unlaze(get(i), l, r);
	if(l > qr || r < ql) return INT_MAX;
	if(l >= ql && r <= qr) return tr[i];
	int m = (l + r) / 2;
	return min(get(L[i], l, m, ql, qr), get(R[i], m + 1, r, ql, qr));
}

const int M = 1000000000;

int l[N], r[N];

int c[N * 4], cn;

int main() {
	int i, j;
	rd(n);
	int root = 0;
	for(i = 0; i < n; i++) {
		rd(l[i]); rd(r[i]);
		c[cn++] = l[i];
		c[cn++] = l[i] - 1;
		c[cn++] = r[i];
		c[cn++] = r[i] + 1;
	}
	sort(c, c + cn);
	cn = unique(c, c + cn) - c;
	for(i = 0; i < n; i++) {
		l[i] = lower_bound(c, c + cn, l[i]) - c,
		r[i] = lower_bound(c, c + cn, r[i]) - c;
		add(root, 0, cn, l[i], r[i]);
	}
	for(i = 0; i < n; i++) {
		if(get(root, 0, cn, l[i], r[i]) > 1) {
			printf("%d\n", i + 1);
			return 0;
		}
	}
	puts("-1");
}
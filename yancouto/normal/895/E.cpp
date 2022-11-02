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

int n;

const int N = 112345;

typedef long double ld;

ld tr[N << 2];
ld lzM[N << 2], lzS[N << 2];

void build(int i, int l, int r) {
	lzM[i] = 1;
	if(l == r) {
		int x;
		scanf("%d", &x);
		tr[i] = x;
		return;
	}
	int m = (l + r) / 2;
	build(2 * i, l, m);
	build(2 * i + 1, m + 1, r);
	tr[i] = tr[2 * i] + tr[2 * i + 1];
}

void unlaze(int i, int l, int r) {
	tr[i] *= lzM[i];
	tr[i] += lzS[i] * (r - l + 1);
	if(l != r)
		for(int j = 2 * i; j <= 2 * i + 1; j++) {
			lzS[j] = lzM[i] * lzS[j] + lzS[i];
			lzM[j] = lzM[i] * lzM[j];
		}
	lzM[i] = 1;
	lzS[i] = 0;
}

ld sum(int i, int l, int r, int ql, int qr) {
	unlaze(i, l, r);
	if(r < ql || l > qr) return 0;
	if(l >= ql && r <= qr) return tr[i];
	int m = (l + r) / 2;
	return sum(2 * i, l, m, ql, qr) + sum(2 * i + 1, m + 1, r, ql, qr);
}

void add(int i, int l, int r, int ql, int qr, ld mm, ld s) {
	unlaze(i, l, r);
	if(r < ql || l > qr) return;
	if(l >= ql && r <= qr) {
		lzM[i] = mm;
		lzS[i] = s;
		unlaze(i, l, r);
		return;
	}
	int m = (l + r) / 2;
	add(2 * i, l, m, ql, qr, mm, s);
	add(2 * i + 1, m + 1, r, ql, qr, mm, s);
	tr[i] = tr[2 * i] + tr[2 * i + 1];
}


int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	build(1, 0, n - 1);
	while(q--) {
		int t, l, r, l2, r2;
		scanf("%d %d %d", &t, &l, &r); l--; r--;
		if(t == 1) {
			scanf("%d %d", &l2, &r2); l2-- ; r2--;
			ld A = sum(1, 0, n - 1, l, r) / (r - l + 1);
			ld B = sum(1, 0, n - 1, l2, r2) / (r2 - l2 + 1);
			add(1, 0, n - 1, l, r, ld(r - l) / (r - l + 1), B / (r - l + 1));
			add(1, 0, n - 1, l2, r2, ld(r2 - l2) / (r2 - l2 + 1), A / (r2 - l2 + 1));
		} else printf("%.10f\n", double(sum(1, 0, n - 1, l, r)));
	}
}
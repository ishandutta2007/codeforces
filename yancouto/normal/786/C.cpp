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

const int N = 112345;
int a[N], nx[N], lst[N], seg[N];
const int M = N * 50;
int tr[M], L[M], R[M], en = 1;

int copy(int x) {
	tr[en] = tr[x]; L[en] = L[x]; R[en] = R[x];
	return en++;
}

int add(int i, int l, int r, int p, int x) {
	int j = copy(i);
	tr[j] += x;
	if(l == r) return j;
	int m = (l + r) / 2;
	if(p <= m) L[j] = add(L[j], l, m, p, x);
	else R[j] = add(R[j], m + 1, r, p, x);
	return j;
}

int mx(int i, int l, int r, int k) {
	if(l == r) return l;
	int m = (l + r) / 2;
	if(tr[L[i]] >= k) return mx(L[i], l, m, k);
	else return mx(R[i], m + 1, r, k - tr[L[i]]);
}

int n;

int main() {
	int i, j, k;
	rd(n);
	for(i = 0; i < n; i++) rd(a[i]);
	for(i = n - 1; i >= 0; i--) {
		nx[i] = lst[a[i]];
		lst[a[i]] = i;
	}
	for(i = n - 1; i >= 0; i--) {
		seg[i] = add(seg[i + 1], 0, n - 1, i, 1);
		if(nx[i]) seg[i] = add(seg[i], 0, n - 1, nx[i], -1);
	}
	for(k = 1; k <= n; k++) {
		i = 0;
		int ct = 0;
		while(i < n) {
			if(tr[seg[i]] <= k) i = n;
			else i = mx(seg[i], 0, n - 1, k + 1);
			ct++;
		}
		printf("%d%c", ct, " \n"[k == n]);
	}
}
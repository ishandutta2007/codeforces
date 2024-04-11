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

const int N = 112345;
int n;
int a[N], b[N], w[N];

int seg[N];
const int M = 6123456;
int L[M], R[M], tr[M];
int en = 1;
int dp[N];

inline void g(int &i) {
	if(!i) {
		assert(en < M);
		i = en++;
	}
}

void set_(int &i, int l, int r, int p, int x) {
	g(i);
	tr[i] = max(tr[i], x);
	if(l == r) return;
	int m = (l + r) / 2;
	if(p <= m) set_(L[i], l, m, p, x);
	else set_(R[i], m + 1, r, p, x);
}

int get(int i, int l, int r, int qr) {
	if(l > qr || !i) return 0;
	if(r <= qr) return tr[i];
	int m = (l + r) / 2;
	return max(get(L[i], l, m, qr), get(R[i], m + 1, r, qr));
}

int main() {
	int i, j, n, m;
	rd(n); rd(m);
	for(i = 0; i < m; i++) {
		rd(a[i]); rd(b[i]); rd(w[i]);
		w[i] = 1e5 + 9 - w[i];
	}
	int ans = 0;
	for(i = m - 1; i >= 0; i--) {
		dp[i] = max(1, get(seg[a[i]], 0, N - 1, w[i] - 1));
		dp[i] = max(dp[i], 1 + get(seg[b[i]], 0, N - 1, w[i] - 1));
		set_(seg[a[i]], 0, N - 1, w[i], dp[i]);
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
}
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
const ll B = 10000019;;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;
int K;
const int N = 112345;
int w[N], v[N], qu[N], ot[N], p[N];

int dp[15009][1009];
int cur;

inline void add(int v, int w) {
	//printf("add(%d, %d)\n", v, w);
	for(int i = 0; i <= K; i++) {
		dp[cur][i] = (cur? dp[cur - 1][i] : 0);
		if(i >= w)
			dp[cur][i] = max(dp[cur][i], (cur? dp[cur - 1][i - w] : 0) + v);
		//printf("dp[%d][%d] = %d\n", cur, i, dp[cur][i]);
	}
	cur++;
}

void solve(int l, int r) {
	//printf("solve(%d, %d)\n", l, r);
	if(l == r) {
		ll ans = 0;
		for(int i = K; i >= 1; i--)
			ans = mod(ans * B + (cur? dp[cur - 1][i] : 0));
		printf("%lld\n", ans);
		return;
	}
	int m = (l + r) / 2;
	int ocur = cur;
	if(qu[m] - (l? qu[l - 1] : 0)) {
		for(int i = m + 1; i <= r; i++)
			if(qu[i] - (i? qu[i - 1] : 0) == 0 && ot[i] < l)
				add(v[ot[i]], w[ot[i]]);
		solve(l, m);
	}
	//printf("rm last %d\n", cur - ocur);
	cur = ocur;
	if(qu[r] - qu[m]) {
		for(int i = l; i <= m; i++)
			if(qu[i] - (i? qu[i - 1] : 0) == 0 && ot[i] > r)
				add(v[i], w[i]);
		solve(m + 1, r);
	}
	//printf("rm last %d\n", cur - ocur);
	cur = ocur;
}

int main() {
	int i, q;
	scanf("%d %d", &n, &K);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &v[i], &w[i]);
		p[i + 1] = i;
		ot[i] = 1e8;
	}
	scanf("%d", &q);
	int ct = n;
	for(i = n; i < n + q; i++) {
		qu[i] = qu[i - 1];
		char t;
		scanf(" %c", &t);
		if(t == '1') {
			scanf("%d %d", &v[i], &w[i]);
			p[++ct] = i;
			ot[i] = 1e8;
		} else if(t == '2') {
			int x;
			scanf("%d", &x);
			ot[p[x]] = i;
			ot[i] = p[x];
		} else {
			qu[i]++;
		}
	}
	solve(0, n + q - 1);
}
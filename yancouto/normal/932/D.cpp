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

const int N = 412345;

int lc[N][20];
ll sum[N][20];
ll w[N]; int h[N], mx[N];
int vn = 0;

int main() {
	int q;
	rd(q);
	ll last = 0;
	mx[0] = 0;
	mx[1] = 1;
	h[1] = 1;
	vn = 1;
	while(q--) {
		ll t, p, q;
		rd(t); rd(p); rd(q);
		int R = (last ^ p);
		if(t == 1) {
			int u = ++vn;
			ll W = last ^ q;
			//printf("add pai %d W %lld\n", R, W);
			h[u] = h[R] + 1;
			w[u] = W;
			lc[u][0] = R;
			sum[u][0] = W;
			while(lc[u][0] && w[lc[u][0]] < w[u])
				lc[u][0] = lc[lc[u][0]][0];
			//printf("pai = %d\n", lc[u][0]);
			h[u] = h[lc[u][0]] + 1;
			//printf("sum[%d][%d] = %lld\nn", u, 0, W);
			for(int k = 1; k < 20; k++) {
				lc[u][k] = lc[lc[u][k - 1]][k - 1];
				sum[u][k] = sum[u][k - 1] + sum[lc[u][k - 1]][k - 1];
			}
		} else {
			ll X = last ^ q;
			//printf("%d %lld\n", R, X);
			//printf("query %d X %lld\n", R, X);
			int ans = 0;
			int u = R;
			if(w[u] > X) {
				puts("0");
				last = 0;
				continue;
			}
			for(int k = 19; k >= 0; k--)
				if((1 << k) <= h[u] && sum[u][k] <= X) {
					//printf("up 2^%d val %lld/%lld\n", k, sum[u][k], X);
					X -= sum[u][k];
					u = lc[u][k];
					ans += (1 << k);
				}
			printf("%d\n", ans);
			last = ans;
		}
	}
}
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
const int N = 212345;
const int L = 20;

int mx[N][L], mxi[N][L];
int a[N];
int nx[N][31];

int get_mxi(int l, int r) {
	int e = 31 - __builtin_clz(r - l + 1);
	if(mx[l][e] >= mx[r - (1 << e) + 1][e])
		return mxi[l][e];
	else
		return mxi[r - (1 << e) + 1][e];
}

int main() {
	int i, j;
	rd(n);
	for(i = 0; i < n; i++) rd(a[i]);
	for(i = n - 1; i >= 0; i--) {
		mx[i][0] = a[i]; mxi[i][0] = i;
		for(j = 1; i + (1 << j) - 1 < n; j++) {
			if(mx[i][j - 1] >= mx[i + (1 << (j - 1))][j - 1])
				mx[i][j] = mx[i][j - 1], mxi[i][j] = mxi[i][j - 1];
			else
				mx[i][j] = mx[i + (1 << (j - 1))][j - 1], mxi[i][j] = mxi[i + (1 << (j - 1))][j - 1];
		}
	}
	for(j = 0; j <= 30; j++) nx[n - 1][j] = n;
	for(i = n - 2; i >= 0; i--) {
		for(j = 0; j <= 30; j++)
			if((a[i + 1] >> j) & 1)
				nx[i][j] = i + 1;
			else
				nx[i][j] = nx[i + 1][j];
	}
	ll tot = (ll(n) * ll(n - 1)) / 2ll + n;
	for(i = 0; i < n; i++) {
		//printf("\n\nat %d=====\n", i);
		int cur = a[i];
		int r = i;
		while(r < n) {
			int nr = n;
			for(j = 0; j <= 30; j++)
				if(!((cur >> j) & 1))
					nr = min(nr, nx[i][j]);
			int k = get_mxi(r, nr - 1);
			//printf("cur %d r %d nr %d k %d a[k] %d\n", cur, r, nr, k, a[k]);
			if(a[k] == cur) tot -= (nr - k);
			//if(a[k] == cur) printf("-= (%d - %d) = %d\n", nr, k, nr - k);
			r = nr;
			cur |= a[nr];
		}
	}
	printf("%lld\n", tot);
}
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 3000000;
const ll INF = ll(1E18);
int p[20], n, m; ll k;
ll v[2][MAXN + 5]; int cnt[2];
void dfs(int type, ll a, int d, int l) {
	if( d == l ) {
		v[type][cnt[type]++] = a;
		return ;
	}
	if( p[d] <= INF/a ) dfs(type, a*p[d], d, l);
	dfs(type, a, d + 1, l);
}
bool check(ll x) {
	ll ret = 0;
	int q = cnt[1] - 1;
	for(int i=0;i<cnt[0];i++) {
		if( v[0][i] > x ) break;
		ll p = x / v[0][i];
		while( q && v[1][q] > p ) q--;
		ret += q + 1;
	}
	return ret >= k;
}
int main() {
	scanf("%d", &n), m = n / 2;
	for(int i=0;i<n;i++) scanf("%d", &p[i]);
	scanf("%lld", &k);
	sort(p, p + n);
	for(int i=m;i<n;i+=2)
		swap(p[i-m], p[i]);
	dfs(0, 1, 0, m), sort(v[0], v[0] + cnt[0]);
	dfs(1, 1, m, n), sort(v[1], v[1] + cnt[1]);
//	printf("%d %d\n", cnt[0], cnt[1]);
	ll le = 1, ri = 1E18;
	while( le < ri ) {
		ll mid = (le + ri) >> 1;
		if( check(mid) ) ri = mid;
		else le = mid + 1;
	}
	printf("%lld\n", ri);
}
/*
16
2 3 5 7 11 13 17 19
23 29 31 37 41 43 47 53
*/
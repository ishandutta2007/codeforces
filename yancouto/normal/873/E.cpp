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

typedef pair<pii, int> ppi;

const int N = 3123;
int a_[N], a[N], p[N], invp[N], dif[N][N], difi[N][N];
ppi eval(int s1, int s2, int s3) {
	assert(max({s1, s2, s3}) <= 2 * min({s1, s2, s3}));
	return ppi(pii(a[s1 - 1] - a[s1], a[s1 + s2 - 1] - a[s1 + s2]), a[s1 + s2 + s3 - 1] - a[s1 + s2 + s3]);
}

int bs1 = 1, bs2 = 1, bs3 = 1;

int ans[N];

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &a_[i]), p[i] = i;
	sort(p, p + n, [](int i, int j) { return a_[i] > a_[j]; });
	for(i = 0; i < n; i++) a[i] = a_[p[i]], invp[p[i]] = i;
	for(i = n - 1; i >= 0; i--) dif[i][i] = a[i] - a[i + 1], difi[i][i] = i;
	for(i = 0; i < n; i++)
		for(j = i + 1; j < n; j++)
			if(dif[i][j - 1] > dif[j][j])
				dif[i][j] = dif[i][j - 1], difi[i][j] = difi[i][j - 1];
			else
				dif[i][j] = dif[j][j], difi[i][j] = j;

	for(int s1 = 1; s1 <= n; s1++)
		for(int s2 = (s1 + 1) / 2; s1 + s2 <= n && s2 <= 2 * s1; s2++) {
			int mn = max((s1 + 1) / 2, (s2 + 1) / 2);
			int mx = min({2 * s1, 2 * s2, n - s1 - s2});
			if(mn > mx) continue;
			//printf("(%d, %d) (difi[%d][%d] = %d) - (%d - 1)\n", s1, s2, s1 + s2 + mn - 1, s1 + s2 + mx - 1, difi[s1 + s2 + mn - 1][s1 + s2 + mx - 1], s1 + s2);
			int s3 = difi[s1 + s2 + mn - 1][s1 + s2 + mx - 1] - (s1 + s2 - 1);
			if(eval(s1, s2, s3) > eval(bs1, bs2, bs3))
				bs1 = s1, bs2 = s2, bs3 = s3;
		}

	for(i = 0; i < bs1; i++) ans[p[i]] = 1;
	for(i = bs1; i < bs1 + bs2; i++) ans[p[i]] = 2;
	for(i = bs1 + bs2; i < bs1 + bs2 + bs3; i++) ans[p[i]] = 3;
	for(i = bs1 + bs2 + bs3; i < n; i++) ans[p[i]] = -1;

	for(i = 0; i < n; i++) printf("%d ", ans[i]); putchar('\n');

}
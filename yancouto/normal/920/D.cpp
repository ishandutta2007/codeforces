#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#ifdef ONLINE_JUDGE
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

#define get asd

int n;

ll k, v;

ll a[11234];
ll mx;


ll memo[5001][5001];
ll solve(int i, int mod) {
	if(i == n) return mod == 0? 0 : -1e16;
	ll &r = memo[i][mod];
	if(r != -1) return r;
	r = max(solve(i + 1, mod), solve(i + 1, (mod - (a[i] % k) + k) % k) + (a[i] % k));
	//printf("solve(%d, %d) = %lld\n", i, mod, r);
	return r;
}

int mrk[11234];

vector<int> get;
void build(int i, int mod) {
	if(i == n) return;
	if(solve(i, mod) == solve(i + 1, mod))
		return build(i + 1, mod);
	//printf("pick %lld\n", a[i]);
	get.pb(i);
	mrk[i] = 1;
	return build(i + 1, (mod - (a[i] % k) + k) % k);
}

int main() {
	int i;
	scanf("%d %lld %lld", &n, &k, &v);
	for(i = 0; i < n; i++)
		scanf("%lld", &a[i]);
	mx = v / k;
	memset(memo, -1, sizeof memo);
	ll mn = solve(0, v % k);
	//printf("%lld\n", mn);
	build(0, v % k);
	if(mn < 0 || accumulate(a, a + n, 0ll) < v) { puts("NO"); return 0; }
	puts("YES");
	if(!get.empty()) {
		i = get.back(); get.pop_back();
		for(int x : get) printf("%lld %d %d\n", ((a[x] + k - 1ll) / k), x + 1, i + 1), a[i] += a[x], a[x] = 0;
	} else i = 1;
	int j = 0;
	while(j < n && mrk[j]) j++;
	for(int g = j + 1; g < n; g++)
		if(!mrk[g] && a[g] > 0)
			printf("%lld %d %d\n", ((a[g] + k - 1ll) / k), g + 1, j + 1), a[j] += a[g], a[g] = 0;
	if(j < n && a[j] >= k)
		printf("%lld %d %d\n", a[j] / k, j + 1, i + 1), a[i] += ll(a[j] / k) * k;
	assert((a[i] % k) == (v % k) && a[i] >= v);
	j = i + 1;
	if(j == n) j = 0;
	if(a[i] > v)
		printf("%lld %d %d\n", (a[i] - v) / k, i + 1, j + 1);
}
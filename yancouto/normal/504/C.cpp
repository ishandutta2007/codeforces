#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn2 = 1000000009;
inline ll mod2(ll x) { return x % modn2; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define LLD "%I64d"
#	define debug(args...) {}
#else
#	define LLD "%lld"
#	define debug(args...) fprintf(stderr, args)
#endif
const int N = 312345;
ll tot;
int n;
int a[N], ne[N], oc[N], wa;

void solve() {
	int l = INT_MAX, r, i;
	for(i = 0; i <= n; i++) oc[i] = ne[i] = 0; wa = 0;
	for(i = 0; i < n/2; i++)
		if(a[i] != a[n - 1 - i])
			l = min(l, i), r = i;
	for(i = l; i <= r; i++)
		oc[a[i]]++;
	for(i = (n+1)/2; i < n; i++)
		if(n - 1 - i >= l && n - 1 - i <= r)
			ne[a[i]]++;
	for(i = 0; i <= n; i++)
		wa += ne[i] > oc[i];
	if(wa == 0) tot += l + 1;
	if(wa == 0) debug("%d, %d ok\n", l+1, r+1);
	for(i = r + 1; i < n-1-l; i++) {
		debug("add %d\n", i+1);
		if(++oc[a[i]] == ne[a[i]]) wa--;
		if(i < n/2 && ne[a[n-1-i]]++ == oc[a[n-1-i]]) wa++;
		if(i >= (n+1)/2 && n-i-1>=l)
			if(--ne[a[i]] == oc[a[i]]) wa--;
		if(wa == 0) tot += l + 1;
		if(wa == 0) debug("%d, %d ok\n", l+1, i+1);
	}
}

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	for(i = 0; i < n; i++) oc[a[i]]++;
	int odd = 0;
	for(i = 0; i <= n; i++) odd += oc[i] & 1;
	if(odd > 1) { puts("0"); return 0; }
	int ok = 1;
	for(i = 0; i < n/2; i++)
		ok = ok && a[i] == a[n-1-i];
	if(ok) { printf(LLD "\n", (ll(n) * ll(n + 1)) / 2); return 0; }
	solve();
	reverse(a, a + n);
	solve();
	for(i = 0; a[i] == a[n-1-i]; i++);
	tot += ll(i + 1) * ll(n-(n-1-i));
	printf(LLD "\n", tot);
}
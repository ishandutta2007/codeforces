#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define lld I64d
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif
const int N = 112345;
int a[N], b[N];

int n, m;
bool ok(int r) {
	int j = 0;
	for(int i = 0; i < n; i++) {
		while(j < m && b[j] < a[i]) j++;
		if(j < m && b[j] - a[i] <= r) continue;
		if(j && a[i] - b[j - 1] <= r) continue;
		return false;
	}
	return true;
}

int main() {
	int i, j;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(i = 0; i < m; i++)
		scanf("%d", &b[i]);
	ll l = 0, r = 2000000000;
	while(l < r) {
		ll m = (l + r) / 2;
		if(ok(m)) r = m;
		else l = m + 1;
	}
	printf("%d\n", (int) l);
}
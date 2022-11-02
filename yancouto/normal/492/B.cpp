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

int a[1123];
int main() {
	int i, j, n, l;
	scanf("%d %d", &n, &l);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	sort(a, a + n);
	double d = max(a[0], l - a[n - 1]);
	for(i = 0; i < n - 1; i++)
		d = max(d, (a[i + 1] - a[i]) / 2.);
	printf("%.1f\n", d);

}
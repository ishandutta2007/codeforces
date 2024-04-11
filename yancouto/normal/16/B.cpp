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
int tot[100];

int main() {
	int i;
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		tot[b] += a;
	}
	int ans =0 ;
	for(i = 10; i >= 1; i--) {
		int g = min(n, tot[i]);
		n -= g;
		ans += g * i;
	}
	printf("%d\n", ans);
}
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
int a[1123];

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	int ans = 360;
	for(i = 0; i < n; i++) {
		int sum = 0;
		for(j = 0; j < n; j++) {
			sum += a[(i + j) % n];
			ans = min(ans, abs(sum - (360 - sum)));
		}
	}
	printf("%d\n", ans);
}
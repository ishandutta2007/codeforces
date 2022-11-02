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

ll solve(ll n, ll m) {
	return n * n - ((n) / m) * ((n) / m);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		int k;
		scanf("%d", &k);
		if(k == 0) {
			printf("1 1\n");
			continue;
		}
		int i;
		for(i = 1; i * i < k; i++) {
			if(k % i) continue;
			int x = k / i, y = i;
			if(((x + y) & 1) || ((x - y) & 1)) continue;
			int a = (x + y) / 2, b = (x - y) / 2;
			int z = (a / b);
			if(z && ((a / z) == b)) {
				printf("%d %d\n", a, z);
				break;
			}
			if((a / (z + 1)) == b) {
				printf("%d %d\n", a, z + 1);
				break;
			}
		}
		if(i * i >= k) puts("-1");
	}
}
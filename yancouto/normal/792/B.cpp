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
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n, k, x;

const int N = 1123;
int nx[N], pr[N];

int main() {
	int i, j;
	scanf("%d %d", &n, &k);
	nx[0] = 0; pr[0] = 0;
	for(i = 1; i < n; i++) {
		pr[i] = pr[0];
		pr[0] = i;
		nx[i] = 0;
		nx[pr[i]] = i;
	}
	int p = 0;
	for(i = 0; i < k; i++) {
		scanf("%d", &x); x %= n - i;
		while(x--) p = nx[p];
		printf("%d ", p + 1);
		nx[pr[p]] = nx[p];
		pr[nx[p]] = pr[p];
		p = nx[p];
	}
	putchar('\n');

}
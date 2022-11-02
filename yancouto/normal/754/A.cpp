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

int n;
int a[1123];

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	if(accumulate(a, a + n, 0) != 0) printf("YES\n1\n1 %d\n", n);
	else {
		for(i = 0; i < n && a[i] == 0; i++);
		if(i == n) puts("NO");
		else printf("YES\n2\n1 %d\n%d %d\n", i + 1, i + 2, n);
	}
}
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

int main() {
	int i = 0, j, n;
	scanf("%d", &n);
	int ct = 0;
	for(i = 0; ct < n; ) {
		i += 5;
		int x = i;
		while(!(x % 5)) x /= 5, ct++;
	}
	if(ct == n) printf("5\n%d %d %d %d %d\n", i, i + 1, i + 2, i + 3, i + 4);
	else puts("0");
}
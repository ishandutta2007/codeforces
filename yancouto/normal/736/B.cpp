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
int ans[] = {0, 0, 1, 1, 2, 1, 2, 1, 2, 2, 2};

bool prime(int x) {
	for(int i = 2; i * i <= x; i++)
		if(!(x % i))
			return false;
	return true;
}

int main() {
	int i, j;
	scanf("%d", &n);
	if(n <= 10) { printf("%d\n", ans[n]); return 0; }
	if(n & 1) {
		if(prime(n)) puts("1");
		else if(prime(n - 2)) puts("2");
		else puts("3");
	} else puts("2");
}
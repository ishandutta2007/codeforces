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

int main() {
	int i, j;
	scanf("%d", &n);
	while(n--) {
		int a, x;
		scanf("%d", &x);
		for(a = 0; a * 3 <= x; a++)
			if(((x - a * 3) % 7) == 0)
				break;
		if(a * 3 <= x) puts("YES");
		else puts("NO");
	}
}
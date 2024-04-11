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

char s[1123456];

int main() {
	int i, j;
	scanf("%s", s);
	n = strlen(s);
	ll tot = 0;
	ll bs = 0;
	for(i = n - 1; i >= 0; i--) {
		if(s[i] == 'b') bs = mod(bs + 1);
		else {
			tot = mod(tot + bs);
			bs = mod(bs * 2);
		}
	}
	printf("%lld\n", mod(tot));
}
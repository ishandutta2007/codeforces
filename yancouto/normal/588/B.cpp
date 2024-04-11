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
	ll n;
	scanf("%lld", &n);
	for(ll i = 2; i * i <= n; i++)
		while(!(n % (i * i))) n /= i;
	printf("%lld\n", n);
}
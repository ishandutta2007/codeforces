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

ll n;
ll val[256];

int main() {
	int i, j; char c;
	scanf("%lld %c", &n, &c); n--;
	ll ans = (n / 4ll) * 16ll;
	n %= 4;
	if(n == 1 || n == 3) ans += 7;
	i = 1;
	for(char cc : "fedabc") val[cc] = i++;
	ans += val[c];
	printf("%lld\n", ans);
}
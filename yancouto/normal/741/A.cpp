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

int a[112], seen[112];

ll mdc(ll a, ll b) {
	if(!b) return a;
	return mdc(b, a % b);
}

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]), a[i]--;
	ll num = 1;
	for(i = 0; i < n; i++) {
		if(seen[i]) continue;
		int j = i;
		ll d = 0;
		while(!seen[j]) {
			seen[j] = 1;
			j = a[j];
			d++;
		}
		if(j != i) { puts("-1"); return 0; }
		if(!(d % 2)) d /= 2;
		num = (num / mdc(d, num)) * d;
	}
	printf("%lld\n", num);
}
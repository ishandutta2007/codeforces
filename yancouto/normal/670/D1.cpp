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
#	define LLD "%I64d"
#	define debug(args...) {}
#else
#	define LLD "%lld"
#	define debug(args...) fprintf(stderr, args)
#endif

ll tot = 0;
void end() { printf(LLD "\n", tot); exit(0); }
int a[112345], b[112345];

int n; ll k;
bool pos(ll m) {
	ll dust = 0;
	for(int i = 0; i < n; i++) {
		dust += max(0ll, ll(a[i]) * m - ll(b[i]));
		if(dust > 1000000009ll) return false;
	}
	return dust <= k;
}

int main() {
	int i, j;
	scanf("%d" LLD, &n, &k);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for(i = 0; i < n; i++)
		scanf("%d", &b[i]);
	//int bk = INT_MAX;
	//for(i = 0; i < n; i++)
	//	bk = min(bk, b[i] / a[i]);
	//tot += bk;
	//ll ne = 0;
	//vector<int> ze;
	//ll alln = 0;
	//for(i = 0; i < n; i++) {
	//	b[i] -= a[i] * bk;
	//	if(b[i] < a[i]) ne += a[i] - b[i], alln += a[i];
	//}
	//if(ne > k) end();
	//k -= ne; tot++;
	ll l = 0, r = INT_MAX;
	while(l < r) {
		ll m = (l + r + 1ll) / 2;
		if(pos(m)) l = m;
		else r = m - 1;
	}
	tot += l;
	end();
}
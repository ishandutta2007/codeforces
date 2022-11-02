#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
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


ll st[67]; int sn;
map<pii, bool> mp;
bool win(ll a, ll b) {
	if(a > b) swap(a, b);
	if(a == 1) return true;
	if(a == 0) return false;
	if(mp.count(pii(a, b))) return mp[pii(a, b)];
	bool &r = mp[pii(a, b)];
	if(!win(a, b % a)) return r = true;
	ll lose = b / a;
	if(a & 1) return r = !(lose & 1);
	lose = ((lose - 1) % (a + 1));
	if(lose == a) return r = true;
	return r = (lose & 1);
}

int main() {
	int i, j, n, t;
	ll a, b;
	scanf("%d", &t);
	while(t--) {
		scanf(LLD LLD, &a, &b);
		if(win(a, b)) puts("First");
		else puts("Second");
	}
}
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

char s[112345]; int o[256];
ll calc(int x) {
	ll t = 1;
	for(int i = 0; i < 6; i++)
		if(!((x >> i) & 1))
			t *= 3;
	return t;
}


int main() {
	int i, j, n;
	scanf("%s", s);
	int k = 0;
	for(i = 0; i <= 9; i++) o[i + '0'] = k++;
	for(i = 'A'; i <= 'Z'; i++) o[i] = k++;
	for(i = 'a'; i <= 'z'; i++) o[i] = k++;
	o['-'] = k++;
	o['_'] = k++;
	ll tot = 1;
	for(i = 0; s[i]; i++)
		tot = mod(tot * calc(o[s[i]]));
	printf(LLD "\n", tot);
}
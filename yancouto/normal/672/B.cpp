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

char s[112345];
int ct[256];
int main() {
	int i, j, n, tot = 0;
	scanf("%d", &n);
	scanf("%s", s);
	if(n > 26) { puts("-1"); return 0; }
	for(i = 0; i < n; i++)
		ct[s[i]]++;
	for(i = 0; i < 256; i++)
		if(ct[i] > 1)
			tot += ct[i] - 1;
	printf("%d\n", tot);
}
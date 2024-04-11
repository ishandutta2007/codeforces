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

char s[1123];
int ct[256];
int main() {
	int i, j, n;
	scanf("%s", s);
	for(i = 0; s[i]; i++)
		ct[s[i]]++;
	int p = 0;
	for(i = 0; i < 256; i++)
		p += (ct[i] & 1);
	if(p > 1 || (p == 1 && (strlen(s) % 2) == 0)) {
		if(strlen(s) % 2) puts("First");
		else puts("Second");
	} else puts("First");
}
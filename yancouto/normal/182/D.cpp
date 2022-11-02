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

char s[112345], t[112345];
int main() {
	int i, j;
	scanf("%s %s", s, t);
	int n = strlen(s), m = strlen(t);
	int tot = 0;
	for(i = 0; s[i] && t[i] && s[i] == t[i]; i++) {
		if(n % (i + 1) || m % (i + 1)) continue;
		for(j = 0; j < n && s[j] == s[j % (i + 1)]; j++);
		if(j < n) continue;
		for(j = 0; j < m && t[j] == t[j % (i + 1)]; j++);
		if(j < m) continue;
		tot++;
	}
	printf("%d\n", tot);
}
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
int mrk[256];
int main() {
	int i, j, n;
	scanf("%*d %s", s);
	for(i = 0; s[i]; i++)
		mrk[tolower(s[i])] = 1;
	for(i = 'a'; i <= 'z' && mrk[i]; i++);
	if(i <= 'z') puts("NO");
	else puts("YES");
}
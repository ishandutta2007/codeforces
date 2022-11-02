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
char s[1123456];

int main() {
	int i, j;
	scanf("%s", s);
	int ct = 0;
	int len = 0;
	for(i = 0; s[i]; i++)
		if(s[i] == '(') len++, ct++;
		else if(ct > 0) ct--, len++;
	printf("%d\n", len - ct);
}
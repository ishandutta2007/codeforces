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
char s[112345], st[112345]; int sn;
char mn[112345];

int main() {
	int i;
	scanf("%s", s);
	n = strlen(s);
	mn[n - 1] = s[n - 1];
	for(i = n - 2; i >= 0; i--)
		mn[i] = min(mn[i + 1], s[i]);
	for(i = 0; i < n; i++) {
		while(sn && st[sn - 1] <= mn[i])
			putchar(st[--sn]);
		st[sn++] = s[i];
	}
	while(sn)
		putchar(st[--sn]);
	putchar('\n');
}
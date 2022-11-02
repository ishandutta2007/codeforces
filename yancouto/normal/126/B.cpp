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

char s[1123456];
int z[1123456];
int main() {
	int i, j, n;
	scanf("%s", s);
	int l = 0, r = 0;
	n = strlen(s);
	for(i = 1; i < n; i++) {
		if(i > r) {
			for(l = i, r = i - 1; r + 1 < n && s[r + 1] == s[r + 1 - l]; r++);
			z[i] = r - l + 1;
			continue;
		}
		int k = i - l;
		if(z[k] + i - 1 < r) z[i] = z[k];
		else {
			for(l = i; r + 1 < n && s[r + 1] == s[r + 1 - l]; r++);
			z[i] = r - l + 1;
		}
	}
	int mx = z[1];
	for(i = 2; i < n; i++) {
		if(z[i] + i - 1 == n - 1 && mx >= z[i]) {
			for(j = 0; j < z[i]; j++) putchar(s[j]);
			putchar('\n');
			return 0;
		}
		mx = max(mx, z[i]);
	}
	puts("Just a legend");
}
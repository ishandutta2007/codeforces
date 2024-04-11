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
int z[112345], v[112345];
int main() {
	int i, j, n;
	scanf("%s", s);
	n = strlen(s);
	int l = 0, r = 0;
	for(i = 1; i < n; i++) {
		if(i > r) {
			for(l = i, r = i - 1; r + 1 < n && s[r + 1] == s[r + 1 - l]; r++);
			z[i] = r - l + 1;
			continue;
		}
		int k = i - l;
		if(i + z[k] - 1 < r) z[i] = z[k];
		else {
			for(l = i; r + 1 < n && s[r + 1] == s[r + 1 - l]; r++);
			z[i] = r - l + 1;
		}
	}
	for(i = 1; i < n; i++) v[i - 1] = z[i];
	sort(v, v + n - 1);
	j = 0;
	vector<pii> x;
	for(i = n - 1; i > 0; i--) {
		if(i + z[i] - 1 < n - 1) continue;
		while(j < n - 1 && v[j] < z[i]) j++;
		x.pb(pii(n - i, n - 1 - j + 1));
	}
	x.pb(pii(n, 1));
	printf("%d\n", (int) x.size());
	for(pii p : x)
		printf("%d %d\n", p.fst, p.snd);
}
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
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

void Z(char s[], int n, int z[]) { // z[i] = |lcp(s,s[i..n])|
	for(int i = 1, m = -1; i < n; i++) {
		z[i] = (m != -1 && m + z[m] >= i)?min(m + z[m] - i, z[i - m]):0;
		while (i + z[i] < n && s[i + z[i]] == s[z[i]]) z[i]++;
		if (m == -1 || i + z[i] > m + z[m]) m = i;
	}
}

const int N = 1123456;
char p[N];
int z[N], sum[N];

int main() {
	int i, n, m;
	scanf("%d %d", &n, &m);
	scanf("%s", p);
	int pn = strlen(p);
	Z(p, pn, z);
	int lst = -1e9;
	for(i = 0; i < m; i++) {
		int x;
		scanf("%d", &x); x--;
		if(lst + pn > x && z[x - lst] + (x - lst) < pn) {
			puts("0");
			return 0;
		}
		sum[x]++;
		sum[x + pn]--;
		lst = x;
	}
	ll ans = 1;
	int cur = 0;
	for(i = 0; i < n; i++) {
		cur += sum[i];
		if(cur == 0) ans = mod(ans * 26ll);
	}
	printf("%lld\n", ans);
}
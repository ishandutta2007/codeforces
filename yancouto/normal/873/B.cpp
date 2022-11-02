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

int n;

char s[112345];
int dif[112345];

int main() {
	int i, j;
	scanf("%d %s", &n, s + 1);
	int c0 = 0, c1 = 0;
	for(i = 1; i <= n; i++) {
		c0 += (s[i] == '0');
		c1 += (s[i] == '1');
		dif[i] = c0 - c1;
	}
	int best = 0;
	map<int, int> mp;
	for(i = n; i > 0; i--) {
		if(!mp.count(dif[i])) mp[dif[i]] = i;
		if(mp.count(dif[i - 1])) best = max(best, mp[dif[i - 1]] - i + 1);
	}
	printf("%d\n", best);
}
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
int ans = 0;

const int N = 1123;

int b[N]; char s[N];

int main() {
	int i, j;
	scanf("%d %s", &n, s);
	for(i = 0; i < n; i++)
		scanf("%d", &b[i]);
	map<char, int> mp;
	int tot = 0;
	int mx = 0;
	char cmx;
	for(i = 0; i < n / 2; i++) {
		if(s[i] != s[n - i - 1]) continue;
		mp[s[i]]++;
		ans += min(b[i], b[n - 1 - i]);
		mx = max<int>(mx, mp[s[i]]);
		if(mx == mp[s[i]]) cmx = s[i];
		tot++;
	}
	if(mx > tot - mx) {
		mx -= tot - mx;
		vector<int> vs;
		for(i = 0; i < n / 2; i++)
			if(s[i] != s[n - i - 1] && s[i] != cmx && s[n - i - 1] != cmx)
				vs.pb(min(b[i], b[n - i - 1]));
		sort(vs.begin(), vs.end());
		for(i = 0; i < mx; i++)
			ans += vs[i];
	}
	printf("%d\n", accumulate(b, b + n, 0) - ans);
}
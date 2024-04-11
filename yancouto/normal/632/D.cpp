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

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

int n;

const int N = 1123456;
int f[N], ans[N], a[N];

int main() {
	int i, j, m, x;
	rd(n); rd(m);
	for(i = 0; i < n; i++) {
		rd(x);
		a[i] = x;
		if(x > m) continue;
		f[x]++;
	}
	for(i = 1; i <= m; i++)
		if(f[i])
			for(j = i; j <= m; j += i)
				ans[j] += f[i];
	int lcm = max_element(ans, ans + m + 1) - ans;
	if(lcm == 0) lcm = 1;
	printf("%d %d\n", lcm, ans[lcm]);
	for(i = 0; i < n; i++)
		if(!(lcm % a[i]))
			printf("%d ", i + 1);
	putchar('\n');
}
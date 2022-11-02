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

template<class num> inline void read(num &x) {
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
const int N = 212345;
int a[N], mrk[N], ct[N], nx[N];

bool ok(int v, int i) {
	while(v > 0 && i < n) {
		//printf("prev %d mrk %d\n", i, mrk[v]);
		i = max(i, mrk[v]);
		if(i == N) return false;
		int use = min(v / a[i], ct[i]);
		//printf("[%d] %d -= %d * %d\n", i, v, use, a[i]);
		v -= use * a[i];
		i = nx[i];
	}
	return v == 0;
}

int main() {
	int i, j, c;
	read(c); read(n);
	for(i = 0; i < n; i++) read(a[i]);
	sort(a, a + n, greater<int>());
	memset(mrk, -1, sizeof mrk);
	for(i = n - 1; i >= 0; i--) {
		mrk[a[i]] = i;
		//printf("mrk[%d] = %d\n", a[i], i);
		if(a[i + 1] == a[i]) ct[i] += ct[i + 1], nx[i] = nx[i + 1];
		else nx[i] = i + 1;
		ct[i]++;
	}
	mrk[0] = N;
	for(i = 1; i < N; i++)
		if(mrk[i] == -1)
			mrk[i] = mrk[i - 1];
	int left = N, right = a[0];
	int ans = INT_MAX;
	for(i = 0; i < n; i++) {
		right = a[i];
		//printf("has %d range [%d, %d]\n", c, left, right);
		for(j = left; j >= right; j--)
			if(c - j >= 0 && !ok(c - j, i))
				ans = j;
		if(a[i] <= c) c -= a[i];
		left = a[i];
	}
	assert(c == 0);
	if(ans == INT_MAX) puts("Greed is good");
	else printf("%d\n", ans);
}
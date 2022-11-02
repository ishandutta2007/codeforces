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

const int N = 112345;
const int L = 20;
int mx[N][L], mn[N][L];

int get_mx(int l, int r) {
	int e = 31 - __builtin_clz(r - l + 1);
	return max(mx[l][e], mx[r - (1 << e) + 1][e]);
}
int get_mn(int l, int r) {
	int e = 31 - __builtin_clz(r - l + 1);
	return min(mn[l][e], mn[r - (1 << e) + 1][e]);
}

bool ok_seg(int l, int r, int x, int k) {
	int mn = get_mn(l, r);
	int mx = get_mx(l, r);
	return abs(x - mn) <= k && abs(mx - x) <= k;
}

int s[2], x[N];
bool ok(int k) {
	int ok0 = n, ok1 = n;
	for(int i = n - 1; i >= 0; i--) {
		int nok0 = ok0, nok1 = ok1;
		if(ok_seg(i + 1, ok1, i? x[i] : s[0], k)) nok0 = i;
		if(ok_seg(i + 1, ok0, i? x[i] : s[1], k)) nok1 = i;
		ok0 = nok0, ok1 = nok1;
	}
	return ok0 == 0 || ok1 == 0;
}

int main() {
	int i, j;
	rd(n); rd(s[0]); rd(s[1]);
	for(i = 1; i <= n; i++) rd(x[i]);
	for(i = n; i >= 1; i--) {
		mx[i][0] = x[i]; mn[i][0] = x[i];
		for(j = 1; i + (1 << j) - 1 < n; j++) {
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
			mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
		}
	}
	int l = abs(s[1] - s[0]), r = 1000000000;
	while(l < r) {
		int m = (l + r) / 2;
		if(ok(m)) r = m;
		else l = m + 1;
	}
	printf("%d\n", l);
}
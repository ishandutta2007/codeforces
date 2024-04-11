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

const int N = 1123;
int cp[N];

int memo[N];
int solve(int n) {
	if(n == 0) return 0;
	if(n < 0) return -100000;
	int &r = memo[n];
	if(r != -1) return r;
	r = -2;
	for(int i = 4; i <= n; i++)
		if(cp[i] && solve(n - i) >= 0)
			r = max(r, 1 + solve(n - i));
	return r;
}

int a[N];

int main() {
	memset(memo, -1, sizeof memo);
	int i, j;
	rd(n);
	for(i = 2; i < N; i++)
		if(!cp[i])
			for(j = i + i; j < N; j += i)
				cp[j] = 1;
	for(i = 1; i <= 200; i++)
		a[i] = solve(i);
	for(i = 0; i < n; i++) {
		int x;
		rd(x);
		int mx = -1;
		for(j = (x % 4); j <= x && j <= 200; j += 4)
			if(a[j] >= 0)
				mx = max(mx, (x - j) / 4 + a[j]);
		printf("%d\n", mx);
	}
}
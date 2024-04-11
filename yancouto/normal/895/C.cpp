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

int ps[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
const int PN = 19;

int ct[100];
ll odd[100], ev[100];
int a[100];

int memo[71][1 << PN];
ll solve(int i, int bm) {
	if(i == 71) return (bm == 0);
	int &r = memo[i][bm];
	if(r != -1) return r;
	r = 0;
	if(ct[i] == 0) return r = solve(i + 1, bm);
	return r = mod(ev[i] * solve(i + 1, bm) + odd[i] * solve(i + 1, bm ^ a[i]));
}

const int N = 112345;
ll fat[N], ifat[N];
inline ll choose(ll n, ll x) {
	if(n < 0 || x > n || x < 0) return 0;
	return mod(fat[n] * mod(ifat[x] * ifat[n - x]));
}

inline ll fexp(ll x, ll p) {
	ll r = 1;
	for(; p; p >>= 1, x = mod(x * x))
		if(p & 1)
			r = mod(r * x);
	return r;
}


int main() {
	memset(memo, -1, sizeof memo);
	int i, j;
	fat[0] = 1;
	for(i = 1; i < N; i++)
		fat[i] = mod(ll(i) * fat[i - 1]);
	ifat[N - 1] = fexp(fat[N - 1], modn - 2);
	for(i = N - 2; i >= 0; i--)
		ifat[i] = mod(ifat[i + 1] * ll(i + 1));
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		ct[x]++;
		a[x] = 0;
		int ox = x;
		for(j = 0; j < PN; j++) {
			int pr = 0;
			while(!(x % ps[j])) {
				x /= ps[j];
				pr = !pr;
			}
			a[ox] |= (pr << j);
		}
	}
	for(i = 1; i <= 70; i++) {
		for(j = 0; j <= ct[i]; j++)
			if(j & 1)
				odd[i] += choose(ct[i], j);
			else
				ev[i] += choose(ct[i], j);
		odd[i] = mod(odd[i]);
		ev[i] = mod(ev[i]);
	}
	printf("%lld\n", mod(solve(0, 0) + modn - 1));
}
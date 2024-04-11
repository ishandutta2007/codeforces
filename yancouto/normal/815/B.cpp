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

inline ll fexp(ll x, ll p) {
	ll r = 1;
	for(; p; p >>= 1, x = mod(x * x))
		if(p & 1)
			r = mod(r * x);
	return r;
}

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
bool add = true;

const int N = 412345;
ll a[N], b[N], fat[N], invf[N];

void do_1() {
	int i;
	for(i = 0; i < n - 1; i++) {
		if(add) b[i] = mod(a[i] + a[i + 1]);
		else b[i] = mod(a[i] - a[i + 1] + modn);
		add = !add;
	}
	n--;
	for(i = 0; i < n; i++)
		a[i] = b[i];
}

ll choose(int n, int k) {
	if(n < 0 || k > n || k < 0) return 0;
	return mod(fat[n] * mod(invf[k] * invf[n - k]));
}

int main() {
	int i, j;
	rd(n);
	for(i = 0; i < n; i++) rd(a[i]);
	while(n > 1 && (((n - 1) % 2) || !add)) do_1();
	if(n == 1) { printf("%lld\n", a[0]); return 0; }
	fat[0] = 1;
	for(i = 1; i < N; i++) fat[i] = mod(ll(i) * fat[i - 1]);
	invf[N - 1] = fexp(fat[N - 1], modn - 2);
	for(i = N - 2; i >= 0; i--)
		invf[i] = mod(invf[i + 1] * ll(i + 1));
	int op = (n - 1) / 4;
	if(op) {
		for(i = 0; i < n - op * 4; i++) {
			b[i] = 0;
			for(j = i; j < n; j += 2)
				b[i] = mod(b[i] + choose(2 * op, (j - i) / 2) * a[j]);
		}
		for(i = 0; i < n - op * 4; i++)
			a[i] = b[i];
		n -= op * 4;
	}
	while(n > 1) do_1();
	printf("%lld\n", a[0]);
}
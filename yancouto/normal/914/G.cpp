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

// To calculate c[i] = sum (a[j] * b[k]) st j | k == i
// Use c = itf(tf(a) * tf(b)), where * is element by element multiplication

// Common transformations and inverses:
// OR  - (a, b) => (a, a + b)     | (a, b) => (a, b - a)
// AND - (a, b) => (a + b, b)     | (a, b) => (a - b, b)
// XOR - (a, b) => (a + b, a - b) | (a, b) => ((a + b) / 2, (a - b) / 2)

typedef ll num;

void tf_xor(num a[], int l, int r) {
	if(l == r) return;
	int m = (l + r) / 2;
	tf_xor(a, l, m);
	tf_xor(a, m + 1, r);
	for(int i = l; i <= m; i++) {
		int j = (m + 1 + (i - l));
		num A = a[i]; num B = a[j];
		a[i] = mod(A + B);
		a[j] = mod(A - B + modn);
	}
}

void itf_xor(num a[], int l, int r) {
	if(l == r) return;
	int m = (l + r) / 2;
	for(int i = l; i <= m; i++) {
		int j = (m + 1 + (i - l));
		num A = a[i]; num B = a[j];
		a[i] = mod((A + B) * ((modn + 1) / 2ll));
		a[j] = mod((A - B + modn) * ((modn + 1) / 2ll));
	}
	itf_xor(a, l, m);
	itf_xor(a, m + 1, r);
}

void tf_and(num a[], int l, int r) {
	if(l == r) return;
	int m = (l + r) / 2;
	tf_and(a, l, m);
	tf_and(a, m + 1, r);
	for(int i = l; i <= m; i++) {
		int j = (m + 1 + (i - l));
		num A = a[i]; num B = a[j];
		a[i] = mod(A + B);
	}
}

void itf_and(num a[], int l, int r) {
	if(l == r) return;
	int m = (l + r) / 2;
	for(int i = l; i <= m; i++) {
		int j = (m + 1 + (i - l));
		num A = a[i]; num B = a[j];
		a[i] = mod(A - B + modn);
	}
	itf_and(a, l, m);
	itf_and(a, m + 1, r);
}


const int K = 17;

// overwrites b such that b[i] = sum (a[j]) such that (j | i) == i and popcount(j) = k
void tf_dor(int k, num a[], num b[], int l, int r) {
	if(l == r) return (void) (b[l] = a[l] * (__builtin_popcount(l) == k));
	int m = (l + r) / 2;
	tf_dor(k, a, b, l, m);
	tf_dor(k, a, b, m + 1, r);
	for(int i = l; i <= m; i++)
		b[m + 1 + (i - l)] = mod(b[m + 1 + (i - l)] + b[i]);
}

// Ranked mobius transform (transform above for all k)
void tf_dor(int k, num a[], num b[K+1][1 << K]) {
	for(int i = 0; i <= k; i++)
		tf_dor(i, a, b[i], 0, (1 << k) - 1);
}

// Convolutes two transforms. c[j][i] = sum(a[g][i] * b[k - g][i]) for 0 <= g <= j
void conv(int k, num a[K+1][1 << K], num b[K+1][1 << K], num c[K+1][1 << K]) {
	for(int j = 0; j <= k; j++)
		for(int i = 0; i < (1 << k); i++) {
			c[j][i] = 0;
			for(int g = 0; g <= j; g++)
				c[j][i] = mod(c[j][i] + a[g][i] * b[j - g][i]);
		}
}

// Inverse of ranked mobius transform for k
void itf_dor(num a[], int l, int r) {
	if(l == r) return;
	int m = (l + r) / 2;
	for(int i = l; i <= m; i++)
		a[m + 1 + (i - l)] = mod(a[m + 1 + (i - l)] - a[i] + modn);
	itf_dor(a, l, m);
	itf_dor(a, m + 1, r);
}

// Inverse of ranked mobius transform for all k
void itf_dor(int k, num a[K+1][1 << K], num b[]) {
	for(int j = 0; j <= k; j++) {
		itf_dor(a[j], 0, (1 << k) - 1);
		for(int i = 0; i < (1 << k); i++)
			if(__builtin_popcount(i) == j)
				b[i] = a[j][i];
	}
}

// use when you want to calculate c[i] = sum (a[j] * b[k]) such that (j | k) == i and (j & k) = 0
// example use (if the size of a and b is (1 << k))
// tf(k, a, a_);
// tf(k, b, b_);
// conv(k, a_, b_, ans);
// itf(k, ans, c);
// the answer will now be stored in c


ll base[1 << K];
ll a_[K+1][1 << K], ans[K+1][1 << K];
ll p[3][1 << K];
ll f[1 << K];

int main() {
	int n, i, j;
	rd(n);
	while(n--) {
		int x;
		rd(x);
		base[x]++;
	}
	// p[0]
	tf_dor(K, base, a_);
	conv(K, a_, a_, ans);
	itf_dor(K, ans, p[0]);
	// p[1]
	for(i = 0; i < (1 << K); i++) p[1][i] = base[i];
	// p[2]
	for(i = 0; i < (1 << K); i++) p[2][i] = base[i];
	tf_xor(p[2], 0, (1 << K) - 1);
	for(i = 0; i < (1 << K); i++) p[2][i] = mod(p[2][i] * p[2][i]);
	itf_xor(p[2], 0, (1 << K) - 1);

	f[0] = 0; f[1] = 1;
	for(i = 2; i < (1 << K); i++) f[i] = mod(f[i - 1] + f[i - 2]);
	for(j = 0; j < 3; j++) {
		for(i = 0; i < (1 << K); i++)
			p[j][i] = mod(p[j][i] * f[i]);
		tf_and(p[j], 0, (1 << K) - 1);
		if(j)
			for(i = 0; i < (1 << K); i++)
				p[0][i] = mod(p[0][i] * p[j][i]);
	}
	itf_and(p[0], 0, (1 << K) - 1);
	ll ans = 0;
	for(i = 0; i < K; i++)
		ans = mod(ans + p[0][1 << i]);
	printf("%lld\n", ans);
}
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

typedef complex<double> num;
const double pi = acos(-1.0);
const int N = 1123456;
int p[N];

// DFT se type = 1 e IDFT se i = -1
// Se for multiplicar lembre-se de deixar cada vetor com n>=soma dos graus dos pols
// n tem que ser potencia de 2
void FFT(num v[], num ans[], int n, int type) {
	assert(!(n & (n - 1)));
	int i, sz, o;
	p[0] = 0;
	for(i = 1; i < n; i++) p[i] = (p[i >> 1] >> 1) | ((i & 1)? (n >> 1) : 0);
	for(i = 0; i < n; i++) ans[i] = v[p[i]];
	for(sz = 1; sz < n; sz <<= 1) {
		const num wn(cos(type * pi / sz), sin(type * pi / sz));
		for(o = 0; o < n; o += (sz << 1)) {
			num w = 1;
			for(i = 0; i < sz; i++) {
				const num u = ans[o + i], t = w * ans[o + sz + i];
				ans[o + i] = u + t;
				ans[o + i + sz] = u - t;
				w *= wn;
			}
		}
	}
	if(type == -1) for(i = 0; i < n; i++) ans[i] /= n;
}

num aux[N], aux2[N];

inline double sign(double x) {
	return (x > .5) - (x < -.5);
}

inline void sqr(num v[], num d[], int n) {
	FFT(v, aux, n, 1);
	for(int i = 0; i < n; i++) aux[i] = aux[i] * aux[i];
	FFT(aux, d, n, -1);
	for(int i = 0; i < n; i++)
		d[i] = sign(abs(d[i]));
}

inline void mul(num a[], num b[], int n) {
	FFT(a, aux, n, 1);
	FFT(b, aux2, n, 1);
	for(int i = 0; i < n; i++) aux[i] = aux[i] * aux2[i];
	FFT(aux, b, n, -1);
	for(int i = 0; i < n; i++)
		b[i] = sign(abs(b[i]));
}

int n;

num pol[N], ans[N];

inline void out(int x) {
	int ct = 0, y = 0;
	while(x) ct++, y = (y << 3) + (y << 1) + (x % 10), x /= 10;
	while(ct--) putchar('0' + (y % 10)), y /= 10;
	putchar(' ');
}

int main() {
	int i, k, x;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		pol[x] = 1;
	}
	ans[0] = 1;
	for(i = 0; (1 << i) <= k; i++) {
		if(k & (1 << i)) mul(pol, ans, (1 << (i + 11)));
		if((1 << (i + 1)) <= k) sqr(pol, pol, (1 << (i + 11)));
	}
	for(i = 0; i < (1 << 20); i++)
		if(ans[i] != num(0))
			out(i);
	putchar('\n');
}
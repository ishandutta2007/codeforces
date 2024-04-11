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


const int N = 17;

int n;

void mult(ll A[N][N], ll B[N][N], ll C[N][N]) {
	int i, j, k;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			C[i][j] = 0;
			for(k = 0; k < n; k++)
				C[i][j] = mod(C[i][j] + A[i][k] * B[k][j]);
		}
}

void cp(ll src[N][N], ll dst[N][N]) {
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			dst[i][j] = src[i][j];
}

void id(ll A[N][N]) {
	int i, j;
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			A[i][j] = (i == j);
}

ll ans[N][N], aux[N][N];

void fexp(ll A[N][N], ll x) {
	id(ans);
	for(; x; x >>= 1) {
		if(x & 1ll) {
			mult(ans, A, aux);
			cp(aux, ans);
		}
		mult(A, A, aux);
		cp(aux, A);
	}
	cp(ans, A);
}

ll A[N][N], v[N], v2[N];

int main() {
	int i, j, g;
	ll a, b, k; int G;
	scanf("%d %lld", &G, &k);
	v[0] = 1;
	for(g = 0; g < G; g++) {
		scanf("%lld %lld %d", &a, &b, &n); n++;
		if(b > k) b = k;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				A[i][j] = (abs(i - j) <= 1);
		fexp(A, b - a);
		for(j = 0; j < n; j++) {
			v2[j] = 0;
			for(i = 0; i < n; i++)
				v2[j] = mod(v2[j] + A[i][j] * v[i]);
		}
		for(i = n; i <= 15; i++) v2[i] = 0;
		for(i = 0; i <= 15; i++) v[i] = v2[i];
	}
	printf("%lld\n", v[0]);
}
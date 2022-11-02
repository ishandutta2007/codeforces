#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int n, b, k, x;
const int N = 102;
ll M[N][N], resp[N][N], aux[N][N];
void cp(ll f[N][N], ll to[N][N]) {
	int i, j;
	for(i = 0; i < x; i++)
		for(j = 0; j < x; j++)
			to[i][j] = f[i][j];
}

void mult(ll a[N][N], ll b[N][N], ll c[N][N]) {
	int i, j, k;
	for(i = 0; i < x; i++)
		for(j = 0; j < x; j++) {
			c[i][j] = 0;
			for(k = 0; k < x; k++)
				c[i][j] += mod(a[i][k] * b[k][j]);
			c[i][j] = mod(c[i][j]);
		}
}

void show(ll a[N][N]) {
	int i, j;
	for(i = 0; i < x; i++) {
		for(j = 0; j < x; j++)
			printf("%d ", a[i][j]);
		putchar('\n');
	}
	puts("--------------");
}

int d[20];
int main() {
	int i, dd, cur, j;
	scanf("%d %d %d %d", &n, &b, &k, &x);
	for(i = 0; i < n; i++) {
		scanf("%d", &dd);
		d[dd]++;
	}
	for(cur = 0; cur < x; cur++)
		for(j = 1; j <= 9; j++)
			M[cur][(cur * 10 + j) % x] += d[j];
	for(cur = 0; cur < x; cur++) resp[cur][cur] = 1;
	for(; b; b >>= 1) {
		if(b & 1) mult(M, resp, aux), cp(aux, resp);
		mult(M, M, aux); cp(aux, M);
	}
	printf("%d\n", (int)resp[0][k]);
}
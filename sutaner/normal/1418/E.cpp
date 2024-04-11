#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 400020
#define maxm
#define maxs
#define maxb
#define M 998244353
#define mo(x) (x = (x >= M) ? (x - M) : x)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std; 

ll inv[maxn];
int n, m, d[maxn];
int pre[maxn], suf[maxn];
void play(int a, int b){
	int pos = lower_bound(d + 1, d + 1 + n, b) - d;
	int num = n + 1 - pos;
	if (num < a) {
		printf("0\n");
		return;
	}
	printf("%lld\n", (1ll * (num - a + 1) * inv[num + 1] % M * pre[pos - 1] % M + 1ll * (num - a) * inv[num] % M * suf[pos] % M) % M);
}

int main(){
	int x, y;
	scanf("%d%d", &n, &m);
	inv[1] = 1; rep(i, 2, n + 1) inv[i] = M - M / i * inv[M % i] % M;
	rep(i, 1, n) scanf("%d", d + i);
	sort(d + 1, d + 1 + n);
	pre[0] = 0; rep(i, 1, n) pre[i] = pre[i - 1] + d[i], pre[i] %= M;	///
	suf[n + 1] = 0; per(i, n, 1) suf[i] = suf[i + 1] + d[i], suf[i] %= M; 	///
	rep(i, 1, m) scanf("%d%d", &x, &y), play(x, y);  
	return 0;
}
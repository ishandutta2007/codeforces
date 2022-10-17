#include <iostream>
#include <cstdio>
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define mid ((l + r) >> 1)
#define maxn 1005
#define bint __int128
using namespace std;
inline bint read()
{
	bint x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return x;
}
inline void write(bint x)
{
	if(x >= 10) write(x / 10);
	putchar('0' + (x % 10));
}
int n[2], vis[2][maxn];
bint a[2][maxn], t[2][maxn][2105];
inline bint gcd(bint x, bint y){return y == 0 ? x : gcd(y, x % y);}
inline void pushup(bint *f, int x){f[x] = f[lc(x)] / gcd(f[lc(x)], f[rc(x)]) * f[rc(x)];}
inline void build(int tp, int id, int x, int l, int r)
{
	if(l == r) {t[tp][id][x] = gcd(a[tp][id], a[tp ^ 1][l]); return;}
	build(tp, id, lc(x), l, mid), build(tp, id, rc(x), mid + 1, r), pushup(t[tp][id], x);	
}
inline void del(int tp, int id, int x, int l, int r, int pos)
{
	if(l == r) {t[tp][id][x] = 1; return;}
	if(pos <= mid) del(tp, id, lc(x), l, mid, pos);
	else del(tp, id, rc(x), mid + 1, r, pos);
	pushup(t[tp][id], x);
}
void solve()
{
	scanf("%d%d", &n[0], &n[1]);
	for (int j = 0; j < 2; j++) for (int i = 1; i <= n[j]; i++) a[j][i] = read(), vis[j][i] = 0;
	for (int j = 0; j < 2; j++) for (int i = 1; i <= n[j]; i++) build(j, i, 1, 1, n[j ^ 1]);
	int cnt[2] = {n[0], n[1]};
	for (int i = 1; i <= n[0] + n[1]; i++)
	{
		for (int j = 0; j < 2; j++) for (int k = 1; k <= n[j]; k++)
		{
			if(!vis[j][k] && t[j][k][1] != a[j][k])
			{
				vis[j][k] = 1, cnt[j]--;
				for (int l = 1; l <= n[j ^ 1]; l++) del(j ^ 1, l, 1, 1, n[j], k);
			}
		}
	}
	if(!cnt[0] || !cnt[1]) {printf("NO\n"); return;}
	printf("YES\n%d %d\n", cnt[0], cnt[1]);
	for (int i = 1; i <= n[0]; i++) if(!vis[0][i]) write(a[0][i]), putchar(' '); printf("\n");
	for (int i = 1; i <= n[1]; i++) if(!vis[1][i]) write(a[1][i]), putchar(' '); printf("\n");
}
int main() {int T; scanf("%d", &T); while(T--) solve(); return 0;}
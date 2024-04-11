#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 100;
const int M = 2e6 + 7;
const int inf = 1e9;
int n, m, mx, p[N], mn[N], d[M][2], sum = 0;
int a[N][N];
bool check() {
	L(t, 0, (1 << mx) - 1) {
		int ds = 0, bs = 0;
		L(i, 1, mx) if(t & (1 << (i - 1))) ds += p[i];
		if(!ds) continue;
		L(i, 1, mx) if(t & (1 << (i - 1))) L(j, 1, mx) if(t & (1 << (j - 1))) bs += a[i][j];
		if(bs >= ds) return 0;
	}
	return 1;
}
int Cnt(int x) { return x == 0 ? 0 : Cnt(x / 10) + 1; }
char sa[N], sb[N];
bool get() {
	L(x, 1, mx) L(i, 1, mx) if(a[x][i]) {
		if(p[x] > 1) {
			a[x][i] --, p[x] --;
			if(check()) return printf("%d %d\n", mn[x] + p[x], mn[i]), 1;
			a[x][i] ++, p[x] ++;
		}
		if(p[i] > 1) {	
			a[x][i] --, p[i] --;
			if(check()) return printf("%d %d\n", mn[x], mn[i] + p[i]), 1;
			a[x][i] ++, p[i] ++;
		}
	}
	return 0;
}
int main() {
	scanf("%d", &n), mx = Cnt(n);
	L(i, 1, n) p[Cnt(i)]++;
	mn[1] = 1;
	L(i, 2, mx) mn[i] = mn[i - 1] * 10;
	L(i, 1, n - 1) scanf("%s%s", sa, sb), d[i][0] = strlen(sa), d[i][1] = strlen(sb), a[d[i][0]][d[i][1]] ++;
	if(!check()) return puts("-1"), 0;
	while(get()) sum ++;
	L(x, 1, mx) L(i, 1, mx) if(a[x][i]) printf("%d %d\n", mn[x] + p[x] - 1, mn[i] + p[i] - 1), sum ++ ;
	if(sum != n - 1) assert(0);
	return 0;
}
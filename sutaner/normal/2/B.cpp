#include <bits/stdc++.h>
#define maxn 1019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
using namespace std;

int n;
int a[maxn][maxn], b[maxn][maxn];
bool pa[maxn][maxn], pb[maxn][maxn];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("2B.in", "r", stdin);
	#endif
	scanf("%d", &n);
	int x;
	bool have_zero = 0;
	int x0 = -1, y0 = -1;
	rep(i, 1, n) rep(j, 1, n) {
		scanf("%d", &x);
		if (!x){
			have_zero = 1, x0 = i, y0 = j;
			continue;
		}
		while (!(x & 1)) a[i][j]++, x >>= 1; 
		while (x % 5 == 0) b[i][j]++, x /= 5;
	}
	per(i, n, 1) per(j, n, 1){
		if (i == n){
			if (j == n) continue;
			a[i][j] += a[i][j + 1];
		}
		else {
			if (j == n) a[i][j] += a[i + 1][j];
			a[i][j] += min(a[i + 1][j], a[i][j + 1]);
			pa[i][j] = (a[i + 1][j] < a[i][j + 1]) ? 0 : 1;
		}
	}
	per(i, n, 1) per(j, n, 1){
		if (i == n){
			if (j == n) continue;
			b[i][j] += b[i][j + 1];
		}
		else {
			if (j == n) b[i][j] += b[i + 1][j];
			b[i][j] += min(b[i + 1][j], b[i][j + 1]);
			pb[i][j] = (b[i + 1][j] < b[i][j + 1]) ? 0 : 1;
		}
	}
	if (!have_zero || min(a[1][1], b[1][1]) <= 1){
		printf("%d\n", min(a[1][1], b[1][1]));
		if (a[1][1] < b[1][1]){
			int x = 1, y = 1;
			while (1){
				if (x == n && y == n) break;
				if (x == n) printf("R"), y++;
				else if (y == n) printf("D"), x++;
				else {
					if (pa[x][y]) printf("R"), y++;
					else printf("D"), x++;
				}
			}
		}
		else {
			int x = 1, y = 1;
			while (1){
				if (x == n && y == n) break;
				if (x == n) printf("R"), y++;
				else if (y == n) printf("D"), x++;
				else {
					if (pb[x][y]) printf("R"), y++;
					else printf("D"), x++;
				}
			}
		}
	}
	else {
		printf("1\n");
		rep(i, 1, y0 - 1) printf("R");
		rep(i, 1, n - 1) printf("D");
		rep(i, 1, n - y0) printf("R");
	}
	return 0;
}
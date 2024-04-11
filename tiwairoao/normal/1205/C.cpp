#include<cstdio>
int query(int x1, int y1, int x2, int y2) {
	printf("? %d %d %d %d\n", x1, y1, x2, y2);
	fflush(stdout);
	int x; scanf("%d", &x);
	return x;
}
int num[50 + 5][50 + 5], n;
int fa[50*50 + 5], f[50*50 + 5];
int find(int x) {
	if( fa[x] == x ) return x;
	int y = fa[x]; fa[x] = find(fa[x]);
	f[x] ^= f[y];
	return fa[x];
}
void link(int x, int y, int k) {
	int fx = find(x), fy = find(y);
	fa[fx] = fy, f[fx] = f[x]^f[y]^k;
}
int d[50*50 + 5];
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			num[i][j] = (i - 1)*n + j;
	for(int i=1;i<=n*n;i++)
		fa[i] = i, f[i] = 0;
	link(num[1][1], num[2][2], !query(1, 1, 2, 2));
	for(int i=3;i<=n;i+=2)
		link(num[1][i], num[1][i-2], !query(1, i-2, 1, i));
	for(int i=4;i<=n;i+=2)
		link(num[2][i], num[2][i-2], !query(2, i-2, 2, i));
	for(int i=4;i<=n;i+=2)
		for(int j=2;j<=n;j+=2)
			link(num[i-2][j], num[i][j], !query(i-2, j, i, j));
	for(int j=1;j<=n;j+=2)
		for(int i=3;i<=n;i+=2)
			link(num[i-2][j], num[i][j], !query(i-2, j, i, j));
	link(num[2][1], num[3][2], !query(2, 1, 3, 2));
	for(int i=3;i<=n;i+=2) {
		link(num[i-2][2], num[i][2], !query(i-2, 2, i, 2));
		link(num[2][i-2], num[2][i], !query(2, i-2, 2, i));
	}
	for(int i=4;i<=n;i+=2)
		for(int j=1;j<=n;j+=2) {
			link(num[i-2][j], num[i][j], !query(i-2, j, i, j));
			link(num[j][i-2], num[j][i], !query(j, i-2, j, i));
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			find(num[i][j]);
	for(int i=1;i+2<=n;i++) {
		for(int j=1;j+1<=n;j++) {
			if( (f[num[i][j]] == f[num[i+2][j]]) == (f[num[i+1][j]] == f[num[i+2][j+1]]) || f[num[i+1][j]] != f[num[i][j+1]] || f[num[i+2][j]] != f[num[i+1][j+1]] ) {
				if( (i+j) & 1 ) d[fa[num[i][j]]] = f[num[i+2][j+1]]^(!query(i, j, i+2, j+1))^f[num[i][j]];
				else d[fa[num[i+2][j+1]]] = f[num[i][j]]^(!query(i, j, i+2, j+1))^f[num[i+2][j+1]];
				puts("!");
				for(int i=1;i<=n;i++) {
					for(int j=1;j<=n;j++)
						printf("%d", d[fa[num[i][j]]]^f[num[i][j]]);
					puts("");
				}
				return 0;
			}
			if( (f[num[j][i]] == f[num[j][i+2]]) == (f[num[j][i+1]] == f[num[j+1][i+2]]) || f[num[j][i+1]] != f[num[j+1][i]] || f[num[j][i+2]] != f[num[j+1][i+1]] ) {
				if( (i+j) & 1 )
					d[fa[num[j][i]]] = f[num[j+1][i+2]]^(!query(j, i, j+1, i+2))^f[num[j][i]];
				else
					d[fa[num[j+1][i+2]]] = f[num[j][i]]^(!query(j, i, j+1, i+2))^f[num[j+1][i+2]];
				puts("!");
				for(int i=1;i<=n;i++) {
					for(int j=1;j<=n;j++)
						printf("%d", d[fa[num[i][j]]]^f[num[i][j]]);
					puts("");
				}
				return 0;
			}
		}
	}
}
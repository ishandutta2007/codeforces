#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 2500;
const int MAXM = MAXN*MAXN/2;
struct edge{
	int x, y, k;
	friend bool operator < (const edge &a, const edge &b) {
		return a.k < b.k;
	}
}e[MAXM + 5];
int fa[MAXN + 5];
int find(int x) {
	return fa[x] = (fa[x] == x ? x : find(fa[x]));
}
void unite(int x, int y) {
	int fx = find(x), fy = find(y);
	if( fx != fy ) fa[fx] = fy;
}
int A[MAXN + 5][MAXN + 5];
int main() {
	int n, cnt = 0; scanf("%d", &n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d", &A[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) {
			if( A[i][j] != A[j][i] ) {
				puts("NOT MAGIC");
				return 0;
			}
			if( i == j && A[i][j] ) {
				puts("NOT MAGIC");
				return 0;
			}
		}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<i;j++)
			cnt++, e[cnt].k = A[i][j], e[cnt].x = i, e[cnt].y = j;
		fa[i] = i;
	}
	sort(e + 1, e + cnt + 1);
	e[cnt + 1].k = -1;
	for(int i=1;i<=cnt;i++) {
		int j = i;
		while( e[j+1].k == e[i].k ) j++;
		for(int k=i;k<=j;k++)
			if( find(e[k].x) == find(e[k].y) ) {
				puts("NOT MAGIC");
				return 0;
			}
		for(int k=i;k<=j;k++)
			unite(e[k].x, e[k].y);
		i = j;
	}
	puts("MAGIC");
}
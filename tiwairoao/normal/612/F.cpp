#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 2000;
const int INF = int(1E9);
struct node{
	int pos, val, pre[3], ans;
}a[MAXN + 5];
bool operator < (node a, node b) {
	if( a.val == b.val )
		return a.pos < b.pos;
	return a.val < b.val;
}
int dp[2][MAXN + 5][MAXN + 5], pre[2][MAXN + 5][MAXN + 5][3];
int bgn[MAXN + 5], fa[MAXN + 5], n, s, x;
void Print1(int x);
void Print2(int x, int y, int z) {
	if( y == z ) {
		Print1(pre[x][y][z][0]);
		if( a[pre[x][y][z][0]].pos <= a[y].pos ) {
			if( a[y].pos - a[pre[x][y][z][0]].pos < n - a[y].pos + a[pre[x][y][z][0]].pos ) printf("+%d\n", a[y].pos - a[pre[x][y][z][0]].pos);
			else printf("-%d\n", n - a[y].pos + a[pre[x][y][z][0]].pos);
		}
		else {
			if( a[pre[x][y][z][0]].pos - a[y].pos < n - a[pre[x][y][z][0]].pos + a[y].pos ) printf("-%d\n", a[pre[x][y][z][0]].pos - a[y].pos);
			else printf("+%d\n", n - a[pre[x][y][z][0]].pos + a[y].pos);
		}
	}
	else {
		Print2(pre[x][y][z][0], pre[x][y][z][1], pre[x][y][z][2]);
		if( x == 0 ) {
			if( pre[x][y][z][0] == 0 ) {
				if( a[pre[x][y][z][1]].pos > a[y].pos )
					printf("-%d\n", a[pre[x][y][z][1]].pos - a[y].pos);
				else
					printf("-%d\n", n + a[pre[x][y][z][1]].pos - a[y].pos);//ok
			}
			else {
				if( a[pre[x][y][z][2]].pos > a[y].pos )
					printf("-%d\n", a[pre[x][y][z][2]].pos - a[y].pos);
				else
					printf("-%d\n", n + a[pre[x][y][z][2]].pos - a[y].pos);
			}
		}
		else {
			if( pre[x][y][z][0] == 0 ) {
				if( a[pre[x][y][z][1]].pos < a[z].pos )
					printf("+%d\n", a[z].pos - a[pre[x][y][z][1]].pos);//ok
				else
					printf("+%d\n", n - a[pre[x][y][z][1]].pos + a[z].pos);
			}
			else {
				if( a[pre[x][y][z][2]].pos < a[z].pos )
					printf("+%d\n", a[z].pos - a[pre[x][y][z][2]].pos);//ok
				else
					printf("+%d\n", n - a[pre[x][y][z][2]].pos + a[z].pos);
			}
		}
	}
}
void Print1(int x) {
	if( x == 0 ) return ;
	Print2(a[x].pre[0], a[x].pre[1], a[x].pre[2]);
}
int main() {
	scanf("%d%d", &n, &s);
	a[0].pos = s, a[0].val = -INF-5;
	for(int i=1;i<=n;i++) {
		scanf("%d", &x);
		a[i].pos = i, a[i].val = x;
	}
	sort(a, a+n+1);
	int lst = 0;
	memset(dp, 127, sizeof dp);
	a[n+1].val = -INF-5;
	for(int i=1;i<=n+1;i++) {
		if( a[i].val != a[lst].val ) {
			int p = i-lst;
			for(int j=0;j<p;j++) {
				dp[0][lst+j][lst+j] = dp[1][lst+j][lst+j] = bgn[a[lst+j].pos];
				pre[0][lst+j][lst+j][0] = pre[1][lst+j][lst+j][0] = fa[a[lst+j].pos];
			}
			for(int len=2;len<=i-lst;len++) {
				for(int j=0;j<p;j++) {
					int k = (j+len-1) % p;
					if( dp[1][lst+(j+1)%p][lst+k] + (a[lst+k].pos+n-a[lst+j].pos)%n < dp[0][lst+(j+1)%p][lst+k] + (a[lst+(j+1)%p].pos+n-a[lst+j].pos)%n ) {
						dp[0][lst+j][lst+k] = dp[1][lst+(j+1)%p][lst+k] + (a[lst+k].pos+n-a[lst+j].pos)%n;
						pre[0][lst+j][lst+k][0] = 1; pre[0][lst+j][lst+k][1] = lst+(j+1)%p; pre[0][lst+j][lst+k][2] = lst+k;
					}
					else {
						dp[0][lst+j][lst+k] = dp[0][lst+(j+1)%p][lst+k] + (a[lst+(j+1)%p].pos+n-a[lst+j].pos)%n;
						pre[0][lst+j][lst+k][0] = 0; pre[0][lst+j][lst+k][1] = lst+(j+1)%p; pre[0][lst+j][lst+k][2] = lst+k;
					}
					if( dp[1][lst+j][lst+(k+p-1)%p] + (a[lst+k].pos+n-a[lst+(k+p-1)%p].pos)%n < dp[0][lst+j][lst+(k+p-1)%p] + (a[lst+k].pos+n-a[lst+j].pos)%n ) {
						dp[1][lst+j][lst+k] = dp[1][lst+j][lst+(k+p-1)%p] + (a[lst+k].pos+n-a[lst+(k+p-1)%p].pos)%n;
						pre[1][lst+j][lst+k][0] = 1; pre[1][lst+j][lst+k][1] = lst+j; pre[1][lst+j][lst+k][2] = lst+(k+p-1)%p;
					}
					else {
						dp[1][lst+j][lst+k] = dp[0][lst+j][lst+(k+p-1)%p] + (a[lst+k].pos+n-a[lst+j].pos)%n;
						pre[1][lst+j][lst+k][0] = 0; pre[1][lst+j][lst+k][1] = lst+j; pre[1][lst+j][lst+k][2] = lst+(k+p-1)%p;
					}
				}
			}
			for(int j=1;j<=n;j++)
				bgn[j] = INF;
			for(int j=0;j<p;j++) {
				if( dp[0][lst+j][lst+(j+p-1)%p] < dp[1][lst+(j+1)%p][lst+j] ) {
					a[lst+j].ans = dp[0][lst+j][lst+(j+p-1)%p];
					a[lst+j].pre[0] = 0; 
					a[lst+j].pre[1] = lst+j;
					a[lst+j].pre[2] = lst+(j+p-1)%p;
					
				}
				else {
					a[lst+j].ans = dp[1][lst+(j+1)%p][lst+j];
					a[lst+j].pre[0] = 1;
					a[lst+j].pre[1] = lst+(j+1)%p;
					a[lst+j].pre[2] = lst+j;
				}
				for(int k=1;k<=n;k++)
					if( a[lst+j].ans + min(n-abs(a[lst+j].pos-k), abs(a[lst+j].pos-k)) < bgn[k] ) {
						bgn[k] = a[lst+j].ans + min(n-abs(a[lst+j].pos-k), abs(a[lst+j].pos-k));
						fa[k] = lst+j;
					}
			}
			if( i == n+1 ) {
				int minx = lst;
				for(int j=0;j<p;j++) {
					if( a[lst+j].ans < a[minx].ans )
						minx = lst + j;
				}
				printf("%d\n", a[minx].ans);
				Print1(minx);
			}
			lst = i;
		}
	}
}
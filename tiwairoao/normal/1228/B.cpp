#include<cstdio>
const int MAXN = 1000;
const int MOD = int(1E9) + 7;
int A[MAXN + 5][MAXN + 5], B[MAXN + 5][MAXN + 5];
int main() {
	int h, w; scanf("%d%d", &h, &w);
	for(int i=1;i<=h;i++) {
		int r; scanf("%d", &r);
		for(int j=1;j<=r;j++)
			A[i][j] = 1;
		A[i][r + 1] = 0;
		for(int j=r+2;j<=w;j++)
			A[i][j] = -1;
	}
	for(int i=1;i<=w;i++) {
		int c; scanf("%d", &c);
		for(int j=1;j<=c;j++)
			B[j][i] = 1;
		B[c + 1][i] = 0;
		for(int j=c+2;j<=h;j++)
			B[j][i] = -1;
	}
	int ans = 1;
	for(int i=1;i<=h;i++)
		for(int j=1;j<=w;j++)
			if( A[i][j] == -1 ) {
				if( B[i][j] == -1 )
					ans = 2LL*ans%MOD;
			}
			else {
				if( B[i][j] != -1 && A[i][j] != B[i][j] ) {
					ans = 0;
					break;
				}
			}
	printf("%d\n", ans);
}
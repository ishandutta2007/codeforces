#include <cstdio>
#include <cstring>
const int MAXN = 150000;
const int INF = (1<<30);
int dp[5][MAXN + 5], pre[5][MAXN + 5];
char s[MAXN + 5];
void print(int x, int y) {
	if( y == 0 ) return ;
	if( dp[x][y] != dp[pre[x][y]][y-1] )
		printf("%d ", y);
	print(pre[x][y], y-1);
}
void solve() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	dp[0][0] = 0;
	for(int i=1;i<5;i++)
		dp[i][0] = INF;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<5;j++)
			dp[j][i] = dp[j][i-1] + 1, pre[j][i] = j;
		if( s[i] == 'o' ) {
			for(int j=0;j<5;j++) {
				if( j == 0 ) {
					if( dp[1][i] > dp[j][i-1] )
						dp[1][i] = dp[j][i-1], pre[1][i] = j;
				}
				else if( j == 4 )
					continue;
				else {
					if( dp[1][i] > dp[j][i-1] )
						dp[1][i] = dp[j][i-1], pre[1][i] = j;
				}
			}
		}
		else if( s[i] == 'n' ) {
			for(int j=0;j<5;j++) {
				if( j == 1 ) {
					if( dp[2][i] > dp[j][i-1] )
						dp[2][i] = dp[j][i-1], pre[2][i] = j;
				}
				else {
					if( dp[0][i] > dp[j][i-1] )
						dp[0][i] = dp[j][i-1], pre[0][i] = j;
				}
			}
		}
		else if( s[i] == 'e' ) {
			for(int j=0;j<5;j++) {
				if( j == 2 )
					continue;
				else {
					if( dp[0][i] > dp[j][i-1] )
						dp[0][i] = dp[j][i-1], pre[0][i] = j;
				}
			}
		}
		else if( s[i] == 't' ) {
			for(int j=0;j<5;j++) {
				if( j == 0 ) {
					if( dp[3][i] > dp[j][i-1] )
						dp[3][i] = dp[j][i-1], pre[3][i] = j;
				}
				else {
					if( dp[3][i] > dp[j][i-1] )
						dp[3][i] = dp[j][i-1], pre[3][i] = j;
				}
			}
		}
		else if( s[i] == 'w' ) {
			for(int j=0;j<5;j++) {
				if( j == 3 ) {
					if( dp[4][i] > dp[j][i-1] )
						dp[4][i] = dp[j][i-1], pre[4][i] = j;
				}
				else {
					if( dp[0][i] > dp[j][i-1] )
						dp[0][i] = dp[j][i-1], pre[0][i] = j;
				}
			}
		}
		else {
			for(int j=0;j<5;j++) {
				if( dp[0][i] > dp[j][i-1] )
					dp[0][i] = dp[j][i-1], pre[0][i] = j;
			}
		}
	}
	int t = 0;
	for(int i=0;i<5;i++)
		if( dp[i][n] < dp[t][n] ) t = i;
	printf("%d\n", dp[t][n]);
	print(t, n), puts("");
}
/*
0 - ""
1 - "o"
2 - "on"
3 - "t"
4 - "tw"
*/
int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}
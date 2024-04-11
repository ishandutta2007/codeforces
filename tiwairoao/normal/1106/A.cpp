#include<cstdio>
const int MAXN = 500 + 5;
char M[MAXN][MAXN]; 
int main() {
	int n; scanf("%d", &n);
	for(int i=0;i<n;i++)
		scanf("%s", M[i]);
	int ans = 0;
	for(int i=1;i<n-1;i++)
		for(int j=1;j<n-1;j++)
			if( M[i][j] == 'X' &&
			M[i-1][j-1] == 'X' &&
			M[i-1][j+1] == 'X' &&
			M[i+1][j-1] == 'X' &&
			M[i+1][j+1] == 'X' ) ans++;
	printf("%d\n", ans);
}
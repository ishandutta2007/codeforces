#include <stdio.h>
const int N=1050;
int Base[N][N],dp[N][N],sol;
int Get(int x1, int y1, int x2, int y2){ x1--;y1--;return dp[x2][y2]-dp[x2][y1]-dp[x1][y2]+dp[x1][y1];}
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) scanf("%i",&Base[i][j]),dp[i][j]=dp[i-1][j]+dp[i][j-1]+Base[i][j]-dp[i-1][j-1];
	for(i=1;i<=n;i++) for(j=1;j<=m;j++){
		if(Base[i][j]) continue;
		if(Get(i,j,n,j)) sol++;
		if(Get(1,j,i,j)) sol++;
		if(Get(i,j,i,m)) sol++;
		if(Get(i,1,i,j)) sol++;
	}
	printf("%i\n",sol);
	return 0;
}
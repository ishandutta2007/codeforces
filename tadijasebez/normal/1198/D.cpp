#include <bits/stdc++.h>
using namespace std;
const int N=50;
int sum[N+1][N+1],dp[N][N][N][N];
char s[N+1][N+2];
void ckmn(int &a, int b){ a=min(a,b);}
int main()
{
    int n;
    scanf("%i",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=n;j++)
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(s[i][j]=='#');
	}
	for(int h=1;h<=n;h++)
		for(int w=1;w<=n;w++)
			for(int x=0;x<n-h+1;x++)
				for(int y=0;y<n-w+1;y++)
				{
					if(sum[x+h][y+w]-sum[x][y+w]-sum[x+h][y]+sum[x][y]!=0) dp[x][y][x+h-1][y+w-1]=max(h,w);
					for(int z=1;z<h;z++) ckmn(dp[x][y][x+h-1][y+w-1],dp[x][y][x+z-1][y+w-1]+dp[x+z][y][x+h-1][y+w-1]);
					for(int z=1;z<w;z++) ckmn(dp[x][y][x+h-1][y+w-1],dp[x][y][x+h-1][y+z-1]+dp[x][y+z][x+h-1][y+w-1]);
				}
	printf("%i\n",dp[0][0][n-1][n-1]);
	return 0;
}
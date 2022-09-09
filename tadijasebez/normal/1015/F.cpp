#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int mod=1e9+7;
const int N=205;
char s[N];
int link[N],go[N][2],dp[2][N][N],c,p=1;
int main()
{
	int n,i,m,j;
	scanf("%i",&n);n*=2;
	scanf("%s",s+1);m=strlen(s+1);
	link[1]=0;
	go[0][0]=go[0][1]=0;
	go[0][s[1]-'(']=1;
	for(i=1;i<=m;i++)
	{
		if(i==m) go[i][0]=go[i][1]=i;
		else
		{
			int g=s[i+1]-'(';
			go[i][g]=i+1;
			link[i+1]=go[link[i]][g];
			go[i][g^1]=go[link[i]][g^1];
		}
		//printf("%i %i\n",go[i][0],go[i][1]);
	}
	for(i=0;i<=m;i++) for(j=0;j<N;j++) dp[p][i][j]=0;
	dp[p][0][0]=1;
	while(n--)
	{
		for(i=0;i<=m;i++) for(j=0;j<N;j++) dp[c][i][j]=0;
		for(i=0;i<=m;i++) for(j=0;j<N;j++)
		{
			if(j>0) dp[c][go[i][1]][j-1]+=dp[p][i][j],dp[c][go[i][1]][j-1]%=mod;
			if(j+1<N) dp[c][go[i][0]][j+1]+=dp[p][i][j],dp[c][go[i][0]][j+1]%=mod;
		}
		c^=1;p^=1;
	}
	printf("%i\n",dp[p][m][0]);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
const int N=2050;
int add(int x, int y){ x+=y;return x>=mod?x-mod:x;}
int sub(int x, int y){ x-=y;return x<0?x+mod:x;}
char base[N][N];
int dp_l[N][N],dp_u[N][N];
int sum_l[N][N],sum_u[N][N];
int ptr_l[N][N],ptr_u[N][N];
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",base[i]+1);
		for(int j=1;j<=m;j++)
		{
			sum_l[i][j]=sum_l[i][j-1]+(base[i][j]=='R');
			sum_u[i][j]=sum_u[i-1][j]+(base[i][j]=='R');
		}
	}
	if(n==1 && m==1) return 0*printf("1\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==1 && j==1)
			{
				dp_l[i][j]=dp_u[i][j]=1;
				continue;
			}
			ptr_l[i][j]=max(ptr_l[i][j-1],1);
			while(sum_l[i][m]-sum_l[i][ptr_l[i][j]]>m-j) ptr_l[i][j]++;
			ptr_u[i][j]=max(ptr_u[i-1][j],1);
			while(sum_u[n][j]-sum_u[ptr_u[i][j]][j]>n-i) ptr_u[i][j]++;
			dp_l[i][j]=add(sub(dp_u[i-1][j],dp_u[ptr_u[i][j]-1][j]),dp_l[i][j-1]);
			dp_u[i][j]=add(sub(dp_l[i][j-1],dp_l[i][ptr_l[i][j]-1]),dp_u[i-1][j]);
		}
	}
	printf("%i\n",add(sub(dp_l[n][m],dp_l[n][m-1]),sub(dp_u[n][m],dp_u[n-1][m])));
	return 0;
}
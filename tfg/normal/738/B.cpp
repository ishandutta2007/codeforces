#include <cstdio>

int m[1010][1010];
int N,M;

int csum[1010][1010];
int rsum[1010][1010];

int main()
{
	scanf("%i %i",&N,&M);
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			scanf("%i",&m[i][j]);
			csum[i][j]=csum[i-1][j]+m[i][j];
			rsum[i][j]=rsum[i][j-1]+m[i][j];
		}
	}
	long long int ans=0;
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M;j++)
		{
			if(m[i][j]==1)
				continue;
			if(csum[i-1][j])
				ans++;
			if(csum[N][j]-csum[i][j])
				ans++;
			if(rsum[i][j-1])
				ans++;
			if(rsum[i][M]-rsum[i][j])
				ans++;
		}
	}
	printf("%lli\n",ans);
}
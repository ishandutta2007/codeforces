#include <bits/stdc++.h>
using namespace std;
const int N=55;
const int K=2505;
const int inf=1e9+7;
int id[N],a[N];
char col[N];
bool comp(int i, int j){ return a[i]<a[j];}
int dp[N][K];
int main()
{
    int n,s,k,i,j,l,r;
	scanf("%i %i %i",&n,&s,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),id[i]=i;
	scanf("%s",col+1);
	for(i=0;i<N;i++) for(j=0;j<K;j++) dp[i][j]=inf;
	sort(id+1,id+1+n,comp);
	for(j=1;j<=n;j++)
	{
		i=id[j];
		for(l=1;l<=n;l++)
		{
			if(a[l]<a[i] && col[l]!=col[i])
			{
				for(r=1;r<K-a[i];r++)
				{
					dp[i][r+a[i]]=min(dp[i][r+a[i]],dp[l][r]+abs(i-l));
				}
			}
		}
		dp[i][a[i]]=min(dp[i][a[i]],abs(i-s));
	}
	int sol=inf;
	for(i=1;i<=n;i++) for(j=k;j<K;j++) sol=min(sol,dp[i][j]);
	if(sol==inf) printf("-1\n");
	else printf("%i\n",sol);
	return 0;
}
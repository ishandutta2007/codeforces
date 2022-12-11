#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx1=1e5+5,mx=130+5;
ll a[mx1],dis[mx][mx],M[mx][mx];
const ll inf=1e17;
int main()
{
	int n,k=0;
	scanf("%d",&n);
	ll x,ans=inf;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		if(x) a[++k]=x;
	}
	if(k>=130)
	{
		printf("3");
		return 0;
	}
	n=k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			M[i][j]=inf;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i]&a[j]) M[i][j]=M[j][i]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=M[i][j];
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<k;i++)
			for(int j=1;j<i;j++)
				ans=min(ans,M[i][j]+dis[i][k]+dis[k][j]);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				M[i][j]=min(M[i][j],M[i][k]+M[k][j]);
	}
	if(ans<inf) printf("%lld",ans);
	else printf("-1");
	return 0;
}
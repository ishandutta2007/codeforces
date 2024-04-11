#include <bits/stdc++.h>
using namespace std;
const int Maxn=2004;
int ans,n,m,A[Maxn],B[Maxn],sumA[Maxn],sumB[Maxn],minA[Maxn],minB[Maxn];
long long x;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&A[i]);
		sumA[i]=sumA[i-1]+A[i];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&B[i]);
		sumB[i]=sumB[i-1]+B[i];
	}
	for(int i=1;i<=n;i++) minA[i]=0x7fffffff;
	for(int i=1;i<=m;i++) minB[i]=0x7fffffff;
	scanf("%d",&x);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			minA[j-i+1]=min(minA[j-i+1],sumA[j]-sumA[i-1]);
	for(int i=1;i<=m;i++)
		for(int j=i;j<=m;j++)
			minB[j-i+1]=min(minB[j-i+1],sumB[j]-sumB[i-1]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(minA[i]*(long long)minB[j]<=x)
				ans=max(ans,i*j);
	printf("%d",ans);
	return 0;
}
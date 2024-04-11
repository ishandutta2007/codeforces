#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[200005],num[200005],pa[200005];
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		num[x]++;
	}
	for(int i=0;i<n;i++)
	{
		pa[i]=i;
		if(num[i]==0)pa[i]=i+1;
	}
	for(int i=1;i<=n;i++)
	{
		int v=(n-a[i])%n;
		v=find(v);
		printf("%d ",(v+a[i])%n);
		num[v]--;
		if(num[v]==0)pa[v]=v+1;
	}
	printf("\n");
	return 0;
}
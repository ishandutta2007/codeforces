#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,maxc[500005],sa[500005];
bool cmp(int a,int b)
{
	return maxc[a]<maxc[b];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=i*2;j<=n;j+=i)
		  maxc[j]=max(maxc[j],i);
		sa[i]=i;
	}
	sort(sa+1,sa+n+1,cmp);
	for(int i=2;i<=n;i++)printf("%d ",maxc[sa[i]]);
	printf("\n");
	return 0;
}
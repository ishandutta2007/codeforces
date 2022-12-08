#include<bits/stdc++.h>
#define N 200010
using namespace std;
int n,b[N],dad[N],i,use[N];
long long a[N],ans[N];
int find(int x){return dad[x]!=x?dad[x]=find(dad[x]):x;}
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)dad[i]=i;
	for(i=1;i<=n;i++)scanf("%I64d",&a[i]);
	for(i=1;i<=n;i++)scanf("%d",&b[i]);
	for(i=n;i>1;i--)
	{
		use[b[i]]=1;
		if(use[b[i]-1]==1)
		{
			a[b[i]]+=a[find(b[i]-1)];
			dad[find(b[i]-1)]=b[i];
		}
		if(use[b[i]+1]==1)
		{
			a[b[i]]+=a[find(b[i]+1)];
			dad[find(b[i]+1)]=b[i];
		}
		ans[i]=max(ans[i+1],a[b[i]]);
	}
	for(i=2;i<=n+1;i++)printf("%I64d\n",ans[i]);
}
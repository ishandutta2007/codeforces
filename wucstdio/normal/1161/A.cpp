#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,last[100005],first[100005];
int main()
{
	scanf("%d%d",&n,&k);
	memset(first,0x3f,sizeof(first));
	for(int i=1;i<=k;i++)
	{
		int x;
		scanf("%d",&x);
		first[x]=min(first[x],i);
		last[x]=i;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(first[i]>1000000000)ans++;
		if(i==n)break;
		if(last[i]<first[i+1])ans++;
		if(last[i+1]<first[i])ans++;
	}
	printf("%d\n",ans);
	return 0;
}
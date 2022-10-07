#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,pa[200005];
int find(int x)
{
	return x==pa[x]?x:pa[x]=find(pa[x]);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)pa[i]=i;
	int ans=0;
	while(k--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x=find(x),y=find(y);
		if(x==y)ans++;
		else pa[y]=x;
	}
	printf("%d\n",ans);
	return 0;
}
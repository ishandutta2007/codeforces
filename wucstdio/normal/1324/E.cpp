#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,h,l,r,f[2005],g[2005];
int main()
{
	scanf("%d%d%d%d",&n,&h,&l,&r);
	for(int i=0;i<h;i++)g[i]=-2147483647;
	g[0]=0;
	while(n--)
	{
		int x;
		scanf("%d",&x);
		for(int i=0;i<h;i++)
		{
			f[i]=max(g[(i-x+h)%h],g[(i-x+1+h)%h]);
			if(i>=l&&i<=r)f[i]++;
		}
		for(int i=0;i<h;i++)g[i]=f[i];
	}
	int ans=0;
	for(int i=0;i<h;i++)ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}
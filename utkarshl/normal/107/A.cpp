#include"stdio.h"
#include"algorithm"
using namespace std;
#include"vector"
	int deg[1000],next[1000],cap[1000];
int main()
{
	int n,p;
	scanf("%d%d",&n,&p);
	for(int x=0;x<n;x++)next[x]=-1;
	while(p--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--,b--;
		deg[b]++;
		next[a]=b;
		cap[a]=c;
	}
	int ans=0;
	for(int tank=0;tank<n;tank++)
	{
		if(deg[tank]==0&&next[tank]>=0)ans++;
	}	
	printf("%d\n",ans);
	for(int tank=0;tank<n;tank++)
	{
		if(deg[tank]||next[tank]<0)continue;
		int n=tank,c=cap[tank];
		while(next[n]>=0)
		{
			c=min(c,cap[n]);
			n=next[n];
		}
		printf("%d %d %d\n",tank+1,n+1,c);
		
	}
}
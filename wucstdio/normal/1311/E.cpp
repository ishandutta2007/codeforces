#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,d,f[5005],dep[5005],node[5005],ans;
bool flag[5005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&d);
		int maxd=0;
		node[0]=1;
		for(int i=2;i<=n;i++)
		{
			f[i]=i/2;
			dep[i]=dep[f[i]]+1;
			d-=dep[i];
			maxd=max(maxd,dep[i]);
		}
		if(d<0)
		{
			puts("NO");
			continue;
		}
		for(int i=1;i<=n;i++)flag[i]=0;
		int now=n;
		while(now)
		{
			node[dep[now]]=now;
			flag[now]=1;
			now=f[now];
		}
		for(int i=n;i>=1;i--)
		{
			if(flag[i])continue;
			int pre=maxd;
			while(dep[f[i]]<pre&&d)
			{
				f[i]=node[dep[f[i]]+1];
				dep[i]=dep[f[i]]+1;
				if(dep[i]>maxd)
				{
					maxd++;
					node[maxd]=i;
					flag[i]=1;
				}
				d--;
			}
		}
		if(d)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for(int i=2;i<=n;i++)printf("%d ",f[i]);
		printf("\n");
	}
	return 0;
}
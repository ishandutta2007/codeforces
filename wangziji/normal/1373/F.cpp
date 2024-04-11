#include <iostream>
#include <queue>
#include <cstdio>
#define int long long
using namespace std;
struct edge
{
	int v,n,w;
}e[2000005];
int head[1000005],cnt,dis[1000005],CNT[1000005],vis[1000005],a[1000005],b[1000005];
inline void add(int u,int v,int w)
{
//	cout << u << " " << v << " " << w << "\n";
	e[++cnt]={v,head[u],w};
	head[u]=cnt;
}
queue <int> q;
signed main(int argc, char** argv) {
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		int s=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),s+=a[i];
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]),s-=b[i];
		if(s>0)
		{
			puts("NO");
			continue;
		}
		cnt=0;
		for(int i=1;i<=n+1;i++)
			head[i]=0,vis[i]=0,CNT[i]=0;
		for(int i=1;i<=n;i++)
		{
			int nxt=i-1;
			if(!nxt) nxt=n;
			add(nxt,i,-(a[i]-b[nxt]));
		}
		dis[n+1]=0,q.push(n+1),vis[n+1]=1;
		for(int i=n;i>=1;i--) dis[i]=1e18,add(n+1,i,0);
		while(!q.empty())
		{
			int x=q.front();
	//		cout << x << " " << dis[x] << "\n";
			q.pop(),vis[x]=0;
			
			for(int i=head[x];i;i=e[i].n)
			{
				if(dis[e[i].v]>dis[x]+e[i].w)
				{
					dis[e[i].v]=dis[x]+e[i].w;
					if(!vis[e[i].v]) q.push(e[i].v),++CNT[e[i].v];
					vis[e[i].v]=1;
					if(CNT[e[i].v]>=100)
					{
						puts("-1");
						return 1;
					}
				}
			}
		}
		int flag=0;
		for(int i=1;i<=n;i++)
			if(-dis[i]>b[i]) flag=1;
		if(flag) puts("NO");
		else puts("YES");
	}
	return 0;
}
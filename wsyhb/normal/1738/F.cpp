#include<bits/stdc++.h>
using namespace std;
const int max_n=1e3+5;
int d[max_n],used[max_n],id[max_n],pos[max_n];
inline bool cmp(int x,int y)
{
	return d[x]>d[y];
}
int fa[max_n];
int get_fa(int x)
{
	return fa[x]!=x?fa[x]=get_fa(fa[x]):x;
}
inline void merge(int x,int y)
{
	x=get_fa(x),y=get_fa(y);
	if(x!=y)
		fa[x]=y;
}
bool vis[max_n];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",d+i);
			id[i]=i;
		}
		sort(id+1,id+n+1,cmp);
		for(int i=1;i<=n;++i)
			pos[id[i]]=i,fa[i]=i;
		int tot=0;
		for(int i=1;i<=n;++i)
		{
			int x=id[i];
			if(vis[x])
				continue;
			vis[x]=true;
			for(int j=1;j<=d[x];++j)
			{
				++tot;
				++used[x];
				printf("? %d\n",x);
				fflush(stdout);
				int y;
				scanf("%d",&y);
				if(vis[y])
				{
					merge(x,y);
					break;
				}
				merge(x,y);
				vis[y]=true;
			}
		}
		shuffle(id+1,id+n+1,rng);
		for(int i=1;i<=n;++i)
		{
			int x=id[i];
			while(tot<n&&used[x]<d[x])
			{
				++tot;
				++used[x];
				printf("? %d\n",x);
				fflush(stdout);
				int y;
				scanf("%d",&y);
				merge(x,y);
			}
		}
		printf("!");
		for(int i=1;i<=n;++i)
			printf(" %d",get_fa(i));
		printf("\n");
		fflush(stdout);
		for(int i=1;i<=n;++i)
			used[i]=0,vis[i]=false;
	}
	return 0;
}
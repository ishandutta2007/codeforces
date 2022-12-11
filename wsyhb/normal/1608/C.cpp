#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n],id[max_n];
inline bool cmp(int x,int y)
{
	return a[x]>a[y];
}
vector<int> edge[max_n];
int dfn[max_n],low[max_n],Time,st[max_n],tp;
bool mark[max_n],ans[max_n];
void tarjan(int x)
{
	dfn[x]=low[x]=++Time;
	st[++tp]=x;
	mark[x]=true;
	for(int i=0;i<int(edge[x].size());++i)
	{
		int y=edge[x][i];
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(mark[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
//		fprintf(stderr,"++\n");
		while(mark[x])
		{
			int k=st[tp--];
			if(dfn[x]==1)
				ans[k]=true;
			mark[k]=false;
//			fprintf(stderr,"k=%d\n",k);
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
			edge[i].clear();
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			id[i]=i;
		}
		sort(id+1,id+n+1,cmp);
		for(int i=1;i<=n-1;++i)
			edge[id[i]].push_back(id[i+1]);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			id[i]=i;
		}
		sort(id+1,id+n+1,cmp);
		for(int i=1;i<=n-1;++i)
			edge[id[i]].push_back(id[i+1]);
		Time=0;
		for(int i=1;i<=n;++i)
			dfn[i]=low[i]=0,ans[i]=false;
		tarjan(id[1]);
		for(int i=1;i<=n;++i)
			putchar(ans[i]+'0');
		putchar('\n');
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int a[max_n];
vector<int> edge[max_n];
int sub_sum[max_n],sum,cnt[max_n];
void dfs(int x,int fa)
{
	sub_sum[x]=a[x];
	cnt[x]=0;
	for(int i=0;i<int(edge[x].size());++i)
	{
		int y=edge[x][i];
		if(y!=fa)
		{
			dfs(y,x);
			sub_sum[x]^=sub_sum[y];
			if(cnt[y]||sub_sum[y]==sum)
				++cnt[x];
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		sum=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			sum^=a[i];
			edge[i].clear();
		}
		for(int i=1;i<=n-1;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		if(!sum)
		{
			puts("YES");
			continue;
		}
		if(k==2)
		{
			puts("NO");
			continue;
		}
		dfs(1,0);
		bool ans=false;
		for(int i=1;i<=n;++i)
		{
			ans|=cnt[i]>=2;
			ans|=!sub_sum[i]&&cnt[i]>=1;
		}
		puts(ans?"YES":"NO");
	}
    return 0;
}
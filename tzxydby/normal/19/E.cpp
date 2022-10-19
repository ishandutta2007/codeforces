#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int from[N],to[N],vise[N],visp[N],dep[N],sum[N],fa[N],n,m,cnt,lst;
map<pair<int,int>,int>mp;
vector<int>e[N],ans;
void dfs(int u)
{
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(visp[v])
			continue;
		visp[v]=1;
		vise[mp[make_pair(u,v)]]=1;
		dep[v]=dep[u]+1;
		fa[v]=u;
		dfs(v);
	}
} 
void get_sum(int u)
{
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i];
		if(visp[v])
			continue;
		visp[v]=1;
		get_sum(v);
		sum[u]+=sum[v];
	}
}
int func()
{
	cout<<from[3312]<<' '<<to[3312]<<endl<<from[4209]<<' '<<to[4209]<<endl;
	return 0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		from[i]=u;
		to[i]=v;
		mp[make_pair(u,v)]=i;
		mp[make_pair(v,u)]=i;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(!visp[i])
		{
			dep[i]=1;
			visp[i]=1;
			fa[i]=0;
			dfs(i);
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(dep[from[i]]>dep[to[i]])
			swap(from[i],to[i]);
		if(vise[mp[make_pair(from[i],to[i])]])
			continue;
		if((dep[to[i]]-dep[from[i]])%2==0)
		{
			cnt++;
			sum[from[i]]--;
			sum[to[i]]++;
			lst=i;
		}
		else
		{
			sum[from[i]]++;
			sum[to[i]]--;
		}
	}
	memset(visp,0,sizeof(visp));
	for(int i=1;i<=n;i++)
	{
		if(!visp[i])
		{
			visp[i]=1;
			get_sum(i);
		}
	}
	if(!cnt)
	{
		printf("%d\n",m);
		for(int i=1;i<=m;i++)
			printf("%d ",i);
	}
	else
	{
		for(int i=2;i<=n;i++)
			if(sum[i]==cnt)
				ans.push_back(mp[make_pair(i,fa[i])]);
		if(cnt==1)
			ans.push_back(lst); 
		sort(ans.begin(),ans.end());
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)
			printf("%d ",ans[i]);
	}
	puts("");
	return 0;
}
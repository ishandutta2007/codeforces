#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,m,dep[N];
vector<int>e[N];
vector<pair<int,int>>a[N];
long long ans;
struct node
{
	set<pair<long long,int>>*s;
	long long b;
	node(){s=new set<pair<long long,int>>,b=0;}
	void merge(node t)
	{
		if(s->size()<t.s->size())
		{
			swap(s,t.s);
			swap(b,t.b);
		}
		for(auto it=t.s->begin();it!=t.s->end();it++)
			s->insert(make_pair(it->first+t.b-b,it->second));
		t.s->clear();
	}
	void cal(int t)
	{
		while(s->size()&&s->begin()->second>=t)
			s->erase(s->begin());
	}
};
node dfs(int u,int f)
{
	node t;
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		dep[v]=dep[u]+1;
		t.merge(dfs(v,u));
	}
	for(auto i:a[u])
		t.s->insert(make_pair(i.second-t.b,dep[i.first]));
	t.cal(dep[u]);
	if(u==1)
		return t;
	if(!t.s->size())
	{
		puts("-1");
		exit(0);
	}
	ans+=t.s->begin()->first+t.b;
	t.b=-t.s->begin()->first;
	return t;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		a[u].emplace_back(v,w);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
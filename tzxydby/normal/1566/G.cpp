#include<bits/stdc++.h>
using namespace std;
const int N=100005;
struct nd
{
	int u,v,w;
	friend bool operator<(const nd &x,const nd &y)
	{
		if(x.w!=y.w) 
			return x.w<y.w;
		if(x.u!=y.u)
			return x.u<y.u;
		return x.v<y.v;
	}
};
int n,m,q;
map<int,int>mp[N];
set<nd>e[N],g;
map<nd,int>c;
void add(int u)
{
	int t=0;
	for(auto i:e[u])
	{
		if(++t>3)
			break;
		if(c[i]++==1)
			g.insert(i);
	}
}
void del(int u)
{
	int t=0;
	for(auto i:e[u])
	{
		if(++t>3)
			break;
		if(--c[i]==1)
			g.erase(i);
	}
}
void add(int u,int v,int w)
{
	del(u),del(v);
	mp[u][v]=w;
	e[u].insert({u,v,w});
	e[v].insert({u,v,w});
	add(u),add(v);
}
void del(int u,int v,int w)
{
	del(u),del(v);
	mp[u][v]=0;
	e[u].erase({u,v,w});
	e[v].erase({u,v,w});
	add(u),add(v);
}
int chk(nd x,nd y){return x.u==y.u||x.u==y.v||x.v==y.u||x.v==y.v;}
int chk(nd x,nd y,nd z)
{
	set<int>s;
	s.insert(x.u);
	s.insert(x.v);
	s.insert(y.u);
	s.insert(y.v);
	s.insert(z.u);
	s.insert(z.v);
	return s.size()==3;
}
long long ask()
{
	vector<nd>t;
	for(int i=0;i<6&&g.size();i++)
		t.push_back(*g.begin()),g.erase(g.begin());
	long long ans;
	if(chk(t[0],t[1],t[2]))
		ans=1ll*t[0].w+t[1].w+t[3].w;
	else
		ans=1ll*t[0].w+t[1].w+t[2].w;
	for(int i=0;i<t.size();i++)
		for(int j=i+1;j<t.size();j++)
			if(!chk(t[i],t[j]))
				ans=min(ans,1ll*t[i].w+t[j].w);
	for(auto i:t)
		g.insert(i);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if(u>v)
			swap(u,v);
		add(u,v,w);
	}
	printf("%lld\n",ask());
	scanf("%d",&q);
	while(q--)
	{
		int op,u,v,w;
		scanf("%d%d%d",&op,&u,&v);
		if(u>v)
			swap(u,v);
		if(op==0)
			del(u,v,mp[u][v]);
		else
		{
			scanf("%d",&w);
			add(u,v,w);
		}
		printf("%lld\n",ask());
	}
	return 0;
}
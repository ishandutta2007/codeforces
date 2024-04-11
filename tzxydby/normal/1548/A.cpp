#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,q,s;
set<int>a[N];
inline int ok(int u){return (!a[u].size())||(*(--a[u].end())<u);}
void add(int u,int v)
{
	s-=ok(u),s-=ok(v);
	a[u].insert(v),a[v].insert(u);
	s+=ok(u),s+=ok(v);
}
void del(int u,int v)
{
	s-=ok(u),s-=ok(v);
	a[u].erase(v),a[v].erase(u);
	s+=ok(u),s+=ok(v);
}
int main()
{
	scanf("%d%d",&n,&m);
	s=n;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	scanf("%d",&q);
	while(q--)
	{
		int t,u,v;
		scanf("%d",&t);
		if(t==1)
		{
			scanf("%d%d",&u,&v);
			add(u,v);
		}
		if(t==2)
		{
			scanf("%d%d",&u,&v);
			del(u,v);
		}
		if(t==3)
			printf("%d\n",s);
	}
	return 0;
}
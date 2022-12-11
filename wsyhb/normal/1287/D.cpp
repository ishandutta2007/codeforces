#include<bits/stdc++.h>
using namespace std;
const int max_n=2e3+5;
int End[max_n],Last[max_n],Next[max_n],E;
inline void add_edge(int x,int y)
{
	End[++E]=y;
	Next[E]=Last[x];
	Last[x]=E;
}
int p[max_n],c[max_n];
vector<int> id[max_n]; 
void dfs(int x)
{
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		dfs(y);
		id[x].insert(id[x].end(),id[y].begin(),id[y].end());
	}
	if(c[x]>(int)id[x].size())
	{
		puts("NO");
		exit(0);
	}
	id[x].insert(id[x].begin()+c[x],x);
}
int a[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	int rt=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",p+i,c+i);
		if(p[i])
			add_edge(p[i],i);
		else
			rt=i;
	}
	dfs(rt);
	assert((int)id[rt].size()==n);
	for(int i=0;i<n;++i)
		a[id[rt][i]]=i+1;
	puts("YES");
	for(int i=1;i<=n;++i)
		printf("%d%c",a[i],i<n?' ':'\n');
	return 0;
}
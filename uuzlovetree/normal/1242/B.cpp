#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m;
set<int> g[maxn],lft;
void mst()
{
	int ans=0;
	queue<int> q;
	q.push(1);
	for(auto x:g[1])lft.insert(x);
	for(int i=2;i<=n;++i)if(!lft.count(i))q.push(i);
	while(lft.size()>0)
	{
		while(!q.empty())
		{
			int u=q.front();q.pop();
			set<int> tmp;
			tmp.clear();
			for(auto v:g[u])if(lft.count(v))tmp.insert(v);
			for(auto x:lft)if(!tmp.count(x))q.push(x);
			swap(lft,tmp);
		}
		if(lft.size()>0)
		{
			int x=*(lft.begin());
			lft.erase(x);
			q.push(x);
			ans++;
		}
	}
	printf("%d\n",ans);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].insert(v); 
		g[v].insert(u);
	}
	mst();
}
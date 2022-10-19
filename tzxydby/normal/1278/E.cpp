#include<bits/stdc++.h>
using namespace std;
const int N=500005;
vector<int>e[N];
int l[N],r[N],n,cnt;
void dfs(int u,int f)
{
	vector<int>a;
	a.clear();
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		l[v]=++cnt;
		a.push_back(v);
	}
	r[u]=++cnt;
	reverse(a.begin(),a.end());
	for(auto v:a)
		dfs(v,u);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	l[1]=++cnt;
	dfs(1,0);
	for(int i=1;i<=n;i++)
		printf("%d %d\n",l[i],r[i]);
	return 0;
}
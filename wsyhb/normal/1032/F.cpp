#include<bits/stdc++.h>
using namespace std;
const int max_n=3e5+5;
vector<int> edge[max_n];
inline void add_edge(int x,int y)
{
	edge[x].push_back(y);
	edge[y].push_back(x);
}
const int mod=998244353;
inline int get_sum(int a,int b)
{
	return a+b-(a+b>=mod?mod:0);
}
int f[max_n][3],pref[max_n];
void dfs(int x,int fa)
{
	f[x][0]=f[x][2]=1;
	int now=1;
	for(vector<int>::iterator it=edge[x].begin();it!=edge[x].end();++it)
	{
		int y=*it;
		if(y!=fa)
		{
			dfs(y,x);
			int v=get_sum(f[y][0],f[y][1]);
			f[x][0]=1ll*f[x][0]*v%mod;
			f[x][2]=1ll*f[x][2]*(f[y][1]+v)%mod;
			pref[y]=now;
			now=1ll*now*(f[y][1]+v)%mod;
		}
	}
	now=1;
	for(vector<int>::reverse_iterator it=edge[x].rbegin();it!=edge[x].rend();++it)
	{
		int y=*it;
		if(y!=fa)
		{
			f[x][1]=(f[x][1]+1ll*f[y][2]*pref[y]%mod*now)%mod;
			now=now*(f[y][0]+2ll*f[y][1])%mod;
		}
	}
	
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n-1;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	dfs(1,0);
	printf("%d\n",get_sum(f[1][0],f[1][1]));
	return 0;
}
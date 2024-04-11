#include <iostream>
#include <cstring>
using namespace std;
int c[100];
int ans,n;
struct edge
{
	int v,n;
}e[10005];
int head[100005],cnt,b[100];
inline void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].n=head[u];
	head[u]=cnt;
}
inline int pd()
{
	memset(b,0,sizeof b);
	int rtn=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=head[i];j;j=e[j].n)
		{
			if(!b[c[i]*10+c[e[j].v]]&&!b[c[i]+c[e[j].v]*10])
			{
				b[c[i]*10+c[e[j].v]]=1;
				b[c[i]+c[e[j].v]*10]=1;
				++rtn;
			}
		}
	}
	return rtn;
}
inline void dfs(int now)
{
	if(now>n)
		return ;
	for(int i=1;i<=6;i++)
	{
		c[now]=i;
		if(now==n)
			ans=max(ans,pd());
		dfs(now+1);
	}
}
int main(int argc, char** argv) {
	int m;
	cin >> n >> m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin >> u >> v;
		add(u,v);
	}
	dfs(1);
	cout << ans;
	return 0;
}
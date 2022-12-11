#include<bits/stdc++.h>
using namespace std;
const int max_n=5e5+5;
const int max_m=5e5+5;
int End[2][max_m],Last[2][max_n],Next[2][max_m],e[2];
inline void add_edge(int x,int y,int t)
{
	End[t][++e[t]]=y;
	Next[t][e[t]]=Last[t][x];
	Last[t][x]=e[t];
}
int w[max_n],b[max_n],dp[max_n];
queue<int> q;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int u,v,t;
		scanf("%d%d%d",&u,&v,&t);
		add_edge(v,u,t);
	}
	for(int i=1;i<=n;++i)
		w[i]=b[i]=dp[i]=n;
	w[n]=b[n]=dp[n]=0;
	q.push(n);
	while(q.size())
	{
		int x=q.front();
		q.pop();
		for(int i=Last[0][x];i;i=Next[0][i])
		{
			int y=End[0][i];
			if(b[y]==n)
			{
				b[y]=dp[x]+1;
				if(w[y]<n)
				{
					dp[y]=max(b[y],w[y]);
					q.push(y);
				}
			}
		}
		for(int i=Last[1][x];i;i=Next[1][i])
		{
			int y=End[1][i];
			if(w[y]==n)
			{
				w[y]=dp[x]+1;
				if(b[y]<n)
				{
					dp[y]=max(b[y],w[y]);
					q.push(y);
				}
			}
		}
	}
	printf("%d\n",dp[1]<n?dp[1]:-1);
	for(int i=1;i<=n;++i)
		printf("%d",b[i]>w[i]?0:1);
	return 0;
}
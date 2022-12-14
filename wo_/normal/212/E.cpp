#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

bool ans[5050];

int sz[5050];

int m=0,head[10100],next[10100],to[10100];

int par[5050];

int rec(int v,int p)
{
	if(sz[v]!=-1) return sz[v];
	par[v]=p;
	int res=1;
	for(int e=head[v];e!=-1;e=next[e])
	{
		if(to[e]==p) continue;
		res+=rec(to[e],v);
	}
	sz[v]=res;
	return res;
}

int main()
{
	int N;
	scanf("%d",&N);
	memset(head,-1,sizeof(head));
	for(int i=0;i<N-1;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		a--;b--;
		next[m]=head[a];head[a]=m;to[m]=b;m++;
		next[m]=head[b];head[b]=m;to[m]=a;m++;
	}
	memset(ans,false,sizeof(ans));
	memset(sz,-1,sizeof(sz));
	rec(0,-1);
	for(int i=0;i<N;i++)
	{
		bool can[5050];
		memset(can,false,sizeof(can));
		can[0]=true;
		int total=0;
		for(int e=head[i];e!=-1;e=next[e])
		{
			if(to[e]==par[i]) continue;
			int now=sz[to[e]];
			total+=now;
			for(int j=N;j>=0;j--)
			{
				if(j+now>N) continue;
				if(can[j]==true) can[j+now]=true;
			}
		}
		int last=N-1-total;
		for(int j=N;j>=0;j--)
		{
			if(j+last>N) continue;
			if(can[j]==true) can[j+last]=true;
		}
		for(int j=0;j<=N;j++)
		{
			ans[j]|=can[j];
		}
	}
	int cnt=0;
	for(int i=1;i<N-1;i++)
	{
		if(ans[i]==true) cnt++;
	}
	printf("%d\n",cnt);
	for(int i=1;i<N-1;i++)
	{
		if(ans[i]==true) printf("%d %d\n",i,N-1-i);
	}
	return 0;
}
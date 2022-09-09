#include <stdio.h>
#include <vector>
using namespace std;
const int Max_N=200050;
struct Edge
{
	int v,w;
	Edge (int a, int b)
	{
		v=a;
		w=b;
	}
};
struct Node
{
	vector<Edge> edges;
} Tree[Max_N];
int parent[Max_N],a[Max_N],b[Max_N],c[Max_N];
long long u1[Max_N],u2[Max_N],v1[Max_N],v2[Max_N],dp[Max_N];
bool OnCicle[Max_N];
int time,visited[Max_N],cnt;
void DFS1(int u)
{
	visited[u]=++time;
	int i;
	for(i=0;i<Tree[u].edges.size();i++)
	{
		int v=Tree[u].edges[i].v;
		int w=Tree[u].edges[i].w;
		if(v!=parent[u])
		{
			if(!visited[v])
			{
				parent[v]=u;
				c[v]=w;
				DFS1(v);
			}
			else if(visited[v]<visited[u])
			{
				int tmp=u;
				while(tmp!=v)
				{
					a[++cnt]=tmp;
					b[cnt]=c[tmp];
					OnCicle[tmp]=true;
					tmp=parent[tmp];
				}
				a[++cnt]=v;
				b[cnt]=w;
				OnCicle[v]=true;
			}
		}
	}
}
long long max(long long a, long long b)
{
	if(a>b) return a;
	else return b;
}
long long min(long long a, long long b)
{
	if(a>b) return b;
	else return a;
}
long long max(long long a, long long b, long long c)
{
	return max(a,max(b,c));	
}
long long ans;
void DFS2(int cur, int prev)
{
	int i;
	for(i=0;i<Tree[cur].edges.size();i++)
	{
		int v=Tree[cur].edges[i].v;
		int w=Tree[cur].edges[i].w;
		if(v!=prev && !OnCicle[v])
		{
			DFS2(v,cur);
			ans=max(ans,dp[cur]+dp[v]+w);
			dp[cur]=max(dp[cur],dp[v]+w);
		}
	}
}
int main()
{
	int n,i,u,v,w;
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		scanf("%i %i %i",&u,&v,&w);
		Tree[u].edges.push_back(Edge(v,w));
		Tree[v].edges.push_back(Edge(u,w));
	}
	DFS1(1);
	//printf("%i\n",cnt);
	for(i=1;i<=cnt;i++) DFS2(a[i],0);
	//for(i=1;i<=cnt;i++) printf("%i ",a[i]);
	//printf("\n");
	//for(i=1;i<=cnt;i++) printf("%i ",b[i]);
	//printf("\n");
	//for(i=1;i<=cnt;i++) printf("%i ",dp[a[i]]);
	//printf("\n");
	long long tmp=0;
	long long sum=0;
	for(i=1;i<=cnt;i++)
	{
		sum+=b[i-1];
		u1[i]=max(u1[i-1],dp[a[i]]+sum);
		v1[i]=max(v1[i-1],dp[a[i]]+sum+tmp);
		tmp=max(tmp,dp[a[i]]-sum);
	}
	int t=b[cnt];
	b[cnt]=0;
	tmp=0;
	sum=0;
	for(i=cnt;i>0;i--)
	{
		sum+=b[i];
		u2[i]=max(u2[i+1],dp[a[i]]+sum);
		v2[i]=max(v2[i+1],dp[a[i]]+sum+tmp);
		tmp=max(tmp,dp[a[i]]-sum);
	}
	long long sol=v1[cnt];
	for(i=1;i<cnt;i++)
	{
		sol=min(sol,max(u1[i]+u2[i+1]+t,v1[i],v2[i+1]));
	}
	//printf("%lld\n",ans);
	sol=max(sol,ans);
	printf("%lld\n",sol);
	return 0;
}
/*
3
1 2 4
2 3 5
1 3 1

5
2 3 7
3 1 9
4 1 8
3 5 4
4 5 5

7
4 2 4
2 3 5
2 1 4
1 5 7
1 6 5
1 7 3
7 6 2
*/
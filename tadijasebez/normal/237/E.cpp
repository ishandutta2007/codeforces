#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int N=250;
const int inf=1e9+69;
int s,t;
struct Edge
{
	int u,v,c,w;
	Edge(){}
	Edge(int h ,int a, int b, int e){ u=h,v=a,c=b,w=e;}
};
vector<Edge> edges;
vector<int> E[N];
void AddEdge(int u, int v, int c, int w)
{
	E[u].push_back(edges.size());
	edges.push_back(Edge(u,v,c,w));
	E[v].push_back(edges.size());
	edges.push_back(Edge(v,u,0,-w));
}
queue<int> q;
bool vis[N];
int Dist[N],par[N],n;
int MaxFlow(int n)
{
	int Cost=0;
	for(int i=0;i<n;i++)
	{
		int j;
		for(j=0;j<N;j++) Dist[j]=inf;
		vis[s]=1;
		Dist[s]=0;
		q.push(s);
		while(!q.empty())
		{
			int x=q.front();
			q.pop();
			vis[x]=0;
			for(j=0;j<E[x].size();j++)
			{
				int e=E[x][j];
				int v=edges[e].v;
				int w=edges[e].w;
				int c=edges[e].c;
				if(c && Dist[v]>Dist[x]+w)
				{
					par[v]=e;
					Dist[v]=Dist[x]+w;
					if(!vis[v]) q.push(v),vis[v]=1;
				}
			}
		}
		if(Dist[t]==inf) return -1;
		Cost+=Dist[t];
		//printf("%i ",Cost);
		//printf("%i ",edges[par[t]].u);
		for(int u=t;u!=s;u=edges[par[u]].u)
		{
			edges[par[u]  ].c--;
			edges[par[u]^1].c++;
		}
	}
	return Cost;
}
char word[N];
int cnt[26];
int main()
{
	int i,m,mm,j,a;
	s=168;t=169;
	scanf("%s",&word);
	scanf("%i",&n);
	mm=strlen(word);
	for(i=0;i<mm;i++) cnt[word[i]-'a']++;
	for(i=0;i<26;i++)
	{
		AddEdge(n+i+1,t,cnt[i],0);
		//if(cnt[i]) printf("%i %i\n",n+i+1,t);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%s %i",&word,&a);
		AddEdge(s,i,a,i);
		//printf("%i %i\n",s,i);
		m=strlen(word);
		for(j=0;j<26;j++) cnt[j]=0;
		for(j=0;j<m;j++) cnt[word[j]-'a']++;
		for(j=0;j<26;j++)
		{
			AddEdge(i,n+j+1,cnt[j],0);
			//if(cnt[j]) printf("%i %i\n",i,n+j+1);
		}
	}
	printf("%i\n",MaxFlow(mm));
	return 0;
}
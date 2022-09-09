#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const int N=100050;
const int M=N<<2;
const long long inf=1000000000ll*1000000ll;
int ls[M],rs[M],clock,Node[N];
vector< pair<int,int> > Graph[M];
long long Dist[M];
void FindNodes(int &c, int ss, int se)
{
	if(!c) c=++clock;
	Dist[c]=inf;
	if(ss==se)
	{
		Node[ss]=c;
		return;
	}
	int mid=ss+se>>1;
	FindNodes(ls[c],ss,mid);
	FindNodes(rs[c],mid+1,se);
	Graph[c].push_back(make_pair(ls[c],0));
	Graph[c].push_back(make_pair(rs[c],0));
}
void Make(int &c, int ss, int se)
{
	if(!c) c=++clock;
	Dist[c]=inf;
	if(ss==se)
	{
		c=Node[ss];
		return;
	}
	int mid=ss+se>>1;
	Make(ls[c],ss,mid);
	Make(rs[c],mid+1,se);
	Graph[ls[c]].push_back(make_pair(c,0));
	Graph[rs[c]].push_back(make_pair(c,0));
}
void Set1(int c, int ss, int se, int qs, int qe, int v, int w)
{
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		Graph[v].push_back(make_pair(c,w));
		return;
	}
	int mid=ss+se>>1;
	Set1(ls[c],ss,mid,qs,qe,v,w);
	Set1(rs[c],mid+1,se,qs,qe,v,w);
}
void Set2(int c, int ss, int se, int qs, int qe, int v, int w)
{
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se)
	{
		Graph[c].push_back(make_pair(v,w));
		return;
	}
	int mid=ss+se>>1;
	Set2(ls[c],ss,mid,qs,qe,v,w);
	Set2(rs[c],mid+1,se,qs,qe,v,w);
}
priority_queue< pair<long long,int> > pq;
void Dijkstra(int s)
{
	Dist[s]=0;
	pq.push(make_pair(0,s));
	int i;
	while(!pq.empty())
	{
		int x=pq.top().second;
		pq.pop();
		for(i=0;i<Graph[x].size();i++)
		{
			int v=Graph[x][i].first;
			int w=Graph[x][i].second;
			if(Dist[x]+w<Dist[v])
			{
				Dist[v]=Dist[x]+w;
				pq.push(make_pair(-Dist[v],v));
			}
		}
		
	}
}
int main()
{
	int n,q,i,u,v,l,r,s,root=0,t,w,root2=0;
	scanf("%i %i %i",&n,&q,&s);
	FindNodes(root,1,n);
	Make(root2,1,n);
	while(q--)
	{
		scanf("%i",&t);
		if(t==1)
		{
			scanf("%i %i %i",&u,&v,&w);
			Graph[Node[u]].push_back(make_pair(Node[v],w));
		}
		if(t==2)
		{
			scanf("%i %i %i %i",&u,&l,&r,&w);
			Set1(root,1,n,l,r,Node[u],w);
		}
		if(t==3)
		{
			scanf("%i %i %i %i",&u,&l,&r,&w);
			Set2(root2,1,n,l,r,Node[u],w);
			//if(l<=s && r>=s) Graph[Node[s]].push_back(make_pair(Node[u],w));
		}
	}
	Dijkstra(Node[s]);
	for(i=1;i<=n;i++) printf("%lld ",Dist[Node[i]]==inf?-1:Dist[Node[i]]);
	printf("\n");
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=100050;
const int inf=1e9+7;
struct Edge
{
	int u,v,c;
	Edge(){}
	Edge(int a, int b, int d):u(a),v(b),c(d){}
};
vector<Edge> edges;
vector<int> E[N];
int s,t;
void AddEdge(int u, int v, int c)
{
	//printf("(%i -> %i) %i\n",u,v,c);
	E[u].pb(edges.size());
	edges.pb(Edge(u,v,c));
	E[v].pb(edges.size());
	edges.pb(Edge(v,u,0));
}
int was[N],dist[N];
int Cut(int u, int flow)
{
	if(flow==0 || dist[u]>dist[t]) return 0;
	if(u==t) return flow;
	int ans=0;
	for(;was[u]<E[u].size();was[u]++)
	{
		int e=E[u][was[u]];
		int v=edges[e].v;
		int c=edges[e].c;
		if(c && dist[v]==dist[u]+1)
		{
			int cut=Cut(v,min(flow,c));
			ans+=cut;
			flow-=cut;
			edges[e].c-=cut;
			edges[e^1].c+=cut;
			if(!flow) return ans;
		}
	}
	return ans;
}
queue<int> q;
bool BFS()
{
	for(int i=s;i<=t;i++) was[i]=0,dist[i]=-1;
	dist[s]=0;
	q.push(s);
	while(q.size())
	{
        int u=q.front();
        q.pop();
        for(int e:E[u])
		{
			int v=edges[e].v;
			int c=edges[e].c;
			if(c && dist[v]==-1)
			{
				dist[v]=dist[u]+1;
				q.push(v);
			}
		}
	}
	return dist[t]!=-1;
}
int MaxFlow()
{
	int ans=0;
	while(BFS())
	{
		ans+=Cut(s,inf);
		//printf("%i\n",ans);
	}
	return ans;
}
const int M=55;
vector<int> X,Y;
int x1[M],y1[M],x2[M],y2[M];
bool mat[M*2][M*2];
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	X.pb(0);X.pb(n);
	Y.pb(0);Y.pb(n);
	for(int i=1;i<=m;i++)
	{
		scanf("%i %i %i %i",&x1[i],&y1[i],&x2[i],&y2[i]);
        x1[i]--;
        y1[i]--;
        X.pb(x1[i]);
        X.pb(x2[i]);
        Y.pb(y1[i]);
        Y.pb(y2[i]);
	}
	sort(X.begin(),X.end());
	X.resize(unique(X.begin(),X.end())-X.begin());
	sort(Y.begin(),Y.end());
	Y.resize(unique(Y.begin(),Y.end())-Y.begin());
	for(int i=1;i<=m;i++)
	{
		x1[i]=lower_bound(X.begin(),X.end(),x1[i])-X.begin()+1;
		x2[i]=lower_bound(X.begin(),X.end(),x2[i])-X.begin()+1;
		y1[i]=lower_bound(Y.begin(),Y.end(),y1[i])-Y.begin()+1;
		y2[i]=lower_bound(Y.begin(),Y.end(),y2[i])-Y.begin()+1;
		for(int x=x1[i]+1;x<=x2[i];x++)
			for(int y=y1[i]+1;y<=y2[i];y++)
				mat[x][y]=1;
	}
	s=0;
	t=X.size()+Y.size()+1;
	for(int i=2;i<=X.size();i++)
	{
		int sz=X[i-1]-X[i-2];
		AddEdge(s,i,sz);
	}
	for(int i=2;i<=Y.size();i++)
	{
		int sz=Y[i-1]-Y[i-2];
		AddEdge(i+X.size(),t,sz);
	}
	for(int i=2;i<=X.size();i++)
		for(int j=2;j<=Y.size();j++)
		{
            if(mat[i][j])
			{
				AddEdge(i,j+X.size(),inf);
			}
		}
	/*for(int i=2;i<=X.size();i++)
	{
		for(int j=2;j<=Y.size();j++) printf("%i ",mat[i][j]);
		printf("\n");
	}*/
	printf("%i\n",MaxFlow());
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int V,E=1,S,T;
const int max_V=(4e5+2)+5;
const int max_E=6e5+5;
int End[max_E<<1],Last[max_V],Next[max_E<<1],Cap[max_E<<1],id[max_E<<1];
inline void add_edge(int x,int y,int z,int k)
{
	End[++E]=y,Next[E]=Last[x],Last[x]=E,Cap[E]=z,id[E]=k;
	End[++E]=x,Next[E]=Last[y],Last[y]=E,Cap[E]=0,id[E]=k;
}
namespace Flow
{
	int dis[max_V],que[max_V],Last1[max_V];
	inline bool BFS()
	{
		for(int i=1;i<=V;++i)
		{
			dis[i]=V;
			Last1[i]=Last[i];
		}
		dis[S]=0,que[1]=S;
		int sz=1;
		for(int t=1;t<=sz;++t)
		{
			int x=que[t];
			for(int i=Last[x];i;i=Next[i])
			{
				int y=End[i];
				if(Cap[i]>0&&dis[y]==V)
				{
					dis[y]=dis[x]+1;
					que[++sz]=y;
				}
			}
		}
		return dis[T]<V;
	}
	int dinic(int x,int flow)
	{
		if(x==T)
			return flow;
		int flow_now=0;
		for(int &i=Last1[x];i;i=Next[i])
		{
			int y=End[i];
			if(Cap[i]>0&&dis[y]==dis[x]+1)
			{
				int f=dinic(y,min(flow,Cap[i]));
				Cap[i]-=f,Cap[i^1]+=f;
				flow-=f,flow_now+=f;
				if(!flow)
					return flow_now;
			}
		}
		return flow_now;
	}
	inline int max_flow()
	{
		int res=0;
		while(BFS())
			res+=dinic(S,1e9);
		return res;
	}
}
int n1,n2,m,q;
const int max_n=2e5+5;
int match_L[max_n],match_R[max_n];
bool vis_L[max_n];
void dfs(int x)
{
	vis_L[x]=true;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=S)
		{
			y-=n1;
			int nxt=match_R[y];
			assert(nxt);
			if(!vis_L[nxt])
				dfs(nxt);
		}
	}
}
const int max_m=2e5+5;
int x[max_m],y[max_m];
int main()
{
	scanf("%d%d%d%d",&n1,&n2,&m,&q);
	V=n1+n2+2,S=V-1,T=V;
	for(int i=1;i<=n1;++i)
		add_edge(S,i,1,0);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",x+i,y+i);
		add_edge(x[i],y[i]+n1,1,i);
	}
	for(int i=1;i<=n2;++i)
		add_edge(i+n1,T,1,0);
	int res=Flow::max_flow();
	vector<int> edge_match;
	long long sum=0;
	for(int x=1;x<=n1;++x)
		for(int i=Last[x];i;i=Next[i])
		{
			int y=End[i];
			if(y!=S&&Cap[i^1]>0)
			{
				edge_match.push_back(id[i]);
				sum+=id[i];
				match_L[x]=y-n1;
				match_R[y-n1]=x;
			}
		}
	assert((int)edge_match.size()==res);
	for(int i=1;i<=n1;++i)
	{
		if(!match_L[i])
		{
			assert(!vis_L[i]);
			dfs(i);
		}
	}
	while(q--)
	{
		int type;
		scanf("%d",&type);
		if(type==1)
		{
			assert(!edge_match.empty());
			int k=edge_match.back();
			edge_match.pop_back();
			sum-=k;
			int x=::x[k],y=::y[k];
			printf("1\n%d\n%lld\n",vis_L[x]?-y:x,sum);
		}
		else
		{
			assert(type==2);
			int sz=edge_match.size();
			printf("%d\n",sz);
			for(int i=0;i<sz;++i)
				printf("%d%c",edge_match[i]," \n"[i+1==sz]);
			if(!sz)
				puts("");
		}
		fflush(stdout);
	}
	return 0;
}
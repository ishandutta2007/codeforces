#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
#include<deque>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

int field[88][88];
int H,W;

struct edge{
	int to,cap,cost,rev;
	edge(){}
	edge(int a,int b,int c,int d):to(a),cap(b),cost(c),rev(d){}
};

vector<edge> G[88*88];
int h[88*88];
int dist[88*88];
int prevv[88*88],preve[88*88];
int V;

const int inf=1<<29;

void add_edge(int from,int to,int cap,int cost)
{
	G[from].push_back(edge(to,cap,cost,G[to].size()));
	G[to].push_back(edge(from,0,-cost,G[from].size()-1));
}

int min_cost_flow(int s,int t,int f)
{
	int res=0;
	for(int i=0;i<V;i++) h[i]=0;
	while(f>0)
	{
		//priority_queue<P,vector<P>,greater<P> > que;
		deque<P> deq;
		for(int i=0;i<V;i++) dist[i]=inf;
		dist[s]=0;
		//que.push(P(0,s));
		deq.push_front(P(0,s));
		//while(!que.empty())
		while(!deq.empty())
		{
			//P p=que.top();
			P p=deq.front();
			//que.pop();
			deq.pop_front();
			int v=p.second;
			if(dist[v]<p.first) continue;
			for(int i=0;i<G[v].size();i++)
			{
				edge &e=G[v][i];
				if(e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to])
				{
					dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
					prevv[e.to]=v;
					preve[e.to]=i;
					//que.push(P(dist[e.to],e.to));
					if(dist[e.to]==dist[v]) deq.push_front(P(dist[e.to],e.to));
					else deq.push_back(P(dist[e.to],e.to));
				}
			}
		}
		if(dist[t]==inf) return -1;
		for(int v=0;v<V;v++) h[v]+=dist[v];
		int d=f;
		for(int v=t;v!=s;v=prevv[v])
		{
			d=min(d,G[prevv[v]][preve[v]].cap);
		}
		f-=d;
		res+=d*h[t];
		for(int v=t;v!=s;v=prevv[v])
		{
			edge &e=G[prevv[v]][preve[v]];
			e.cap-=d;
			G[v][e.rev].cap+=d;
		}
	}
	return res;
}

int encode(int i,int j)
{
	return i*W+j;
}

const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

bool isin(int x,int y)
{
	return x>=0&&y>=0&&x<H&&y<W;
}

int main()
{
	scanf("%d%d",&H,&W);
	for(int i=0;i<H;i++)
	{
		for(int j=0;j<W;j++)
		{
			scanf("%d",&field[i][j]);
		}
	}
	V=W*H+2;
	int s=W*H,t=W*H+1;
	for(int i=0;i<H;i++) for(int j=0;j<W;j++)
	{
		if((i+j)%2==0)
		{
			int v=encode(i,j);
			add_edge(s,v,1,0);
			for(int k=0;k<4;k++)
			{
				int ni=i+dx[k],nj=j+dy[k];
				if(isin(ni,nj))
				{
					int nv=encode(ni,nj);
					int cost=(field[i][j]==field[ni][nj]?0:1);
					add_edge(v,nv,1,cost);
				}
			}
		}
		else
		{
			int v=encode(i,j);
			add_edge(v,t,1,0);
			/*for(int k=0;k<4;k++)
			{
				int ni=i+dx[k],nj=j+dy[k];
				if(isin(ni,nj))
				{
					int nv=encode(ni,nj);
					int cost=(field[i][j]==field[ni][nj]?0:1);
					add_edge(v,nv,1,cost);
				}
			}*/
		}
	}
	int cost=min_cost_flow(s,t,H*W/2);
	printf("%d\n",cost);
	return 0;
}
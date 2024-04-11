#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#define max_n 1200
#define max_m 120000
#define cs const
#define INF 9223372036854775807ll
#define int_INF 2147483647
#define flow_t long long
namespace flow_graph{
	using std::memset;
	typedef cs int& ci;
	typedef cs flow_t&cft;
	struct edge_node{
		int v;
		flow_t f;
		int nxt;
		edge_node(){}
		edge_node(ci _v,cft _f,ci _nxt):v(_v),f(_f),nxt(_nxt){}
	};
	struct graph{
		int head[max_n+1],cnt;
		edge_node edge[max_m<<1];
		void build(){
			memset(head,-1,sizeof(head)),cnt=-1;
		}
		void insert(ci u,ci v,cft f){
			push(u,v,f);
			push(v,u,0);
		}
		void push(ci u,ci v,cft f){
			edge[++cnt]=edge_node(v,f,head[u]);
			head[u]=cnt;
		}
	};
}
namespace graph_max_flow{
	using std::memcpy;
	using std::min;
	using flow_graph::edge_node;
	using flow_graph::graph;
	typedef cs int& ci;
	int dep[max_n+1],
		cur[max_n+1],
		gap[max_n+2];
	namespace ISAP{
		int enxt[max_m<<1],
			ehed[max_n+1],
			que[max_n+1];
		void bfs(graph&g,ci t){
			memset(dep,-1,sizeof(dep)),memset(gap,0,sizeof(gap));
			dep[t]=0,gap[1]=1;
			int u,*head=que-1,*tail=que;
			for(que[0]=t; ++head<=tail; ){
				for(int i=g.head[u=*head],v; ~i; i=g.edge[i].nxt)
					dep[v=g.edge[i].v]==-1&&v!=t&&(++gap[dep[v]=dep[u]+1],*++tail=v);
				for(int*i=&g.head[u]; ~*i; i=&g.edge[*i].nxt)
					while(!g.edge[*i].f)
						if((*i=g.edge[*i].nxt)==-1)
							goto break2;
				break2:;
			}
		}
		flow_t dfs(graph&g,ci u,cs flow_t flow,ci s,ci t,ci n){
			if(u==t)
				return flow;
			flow_t ret=0,nfl;
			for(int v; ~cur[u]; cur[u]=g.edge[cur[u]].nxt){
				edge_node&e=g.edge[cur[u]];
				if(e.f&&dep[u]==dep[v=e.v]+1&&(nfl=dfs(g,v,min(flow-ret,e.f),s,t,n))){
					e.f-=nfl,
					g.edge[cur[u]^1].f+=nfl;
					if((ret+=nfl)==flow)
						return ret;
				}
			}
			!--gap[dep[u]]&&(dep[s]=n+1);
			++gap[++dep[u]];
			return ret;
		}
		flow_t max_flow(graph&g,ci s,ci t,ci n){
			memcpy(ehed,g.head,sizeof(g.head));
			for(int i=-1; ++i<=g.cnt; enxt[i]=g.edge[i].nxt);
			flow_t ans=0,ret;
			while(1){
				for(bfs(g,t),ret=0; dep[s]<=n; ret+=dfs(g,s,INF,s,t,n))
					memcpy(cur,g.head,sizeof(cur));
				memcpy(g.head,ehed,sizeof(g.head));
				for(int i=-1; ++i<=g.cnt; g.edge[i].nxt=enxt[i]);
				if(!ret)
					return ans;
				ans+=ret;
				ret=0;
			}
		}
	}
}
typedef cs int& ci;
using flow_graph::graph;
using std::min;
int que[2][max_n];
int dis[max_n+1],pre[max_n+1];
bool vis[max_n+1];
long long tim[max_n+1];
void bfs(graph&g,ci s,ci t){
	int head[2]={0,0},tail[2]={0,-1},now=0,u;
	memset(dis,127,sizeof(dis)),memset(vis,0,sizeof(vis)),dis[s]=0,tim[s]=int_INF;
	for(que[0][0]=s; head[now]<=tail[now]; now^=1){
		do{
			for(; vis[u=que[now][head[now]]]; ++head[now]);
			++head[now],vis[u]=1;
			if(u==t)
				return;
			for(int i=g.head[u],v; ~i; i=g.edge[i].nxt){
				v=g.edge[i].v;
				if(g.edge[i].f){
					if(dis[v]>dis[u]){
						dis[v]=dis[u],pre[v]=i,tim[v]=min(tim[u],g.edge[i].f);
						que[now][++tail[now]]=v;
					}
				}
				else{
					if(!(i&1)&&dis[v]>dis[u]+1){
						dis[v]=dis[u]+1,pre[v]=i,tim[v]=tim[u];
						que[now^1][++tail[now^1]]=v;
					}
				}
			}
		}while(head[now]<=tail[now]);
		head[now]=0,tail[now]=-1;
	}
}
int answ(graph&g,ci s,ci t,int k){
	int ret=0;
	while(1){
		bfs(g,s,t);
		long long now=tim[t];
		if(now*dis[t]>=k)
			return ret+k/dis[t];
		ret+=now,k-=now*dis[t];
		for(int u=t; u!=s; u=g.edge[pre[u]^1].v)
			g.edge[pre[u]^1].f+=now,g.edge[pre[u]].f&&(g.edge[pre[u]].f-=now);
	}
}
namespace io{
	using std::isdigit;
	using std::getchar;
	template<typename T>void read(T&x){
		int ch;
		while(!isdigit(ch=getchar()));
		for(x=ch^'0'; isdigit(ch=getchar()); x=x*10+(ch^'0'));
	}
	template<typename T>void read(T&x1,T&x2){
		read(x1);
		read(x2);
	}
}
using std::printf;
using graph_max_flow::ISAP::max_flow;
using flow_graph::graph;
using io::read;
graph g;
int main(){
	int n,k;
	read(n,k),g.build();
	for(int i=0,j,x; ++i<=n; )
		for(j=0; ++j<=n; x>0&&(g.insert(i,j,x),1))
			read(x);
	int ans=max_flow(g,1,n,n);
	if(!ans){
		puts("0");
		return 0;
	}
	printf("%d\n",ans+answ(g,1,n,k));
	return 0;
}
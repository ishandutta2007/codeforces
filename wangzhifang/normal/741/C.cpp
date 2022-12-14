#include <cstdio>
#include <cstring>
#define cs const
#define max_n 200000
#define max_m 200000
using namespace std;
typedef cs int& ci;
int u[max_n+1],v[max_n+1],col[max_n+1];
bool flag=0;
struct node{
	int v,nxt;
	node(){}
	node(ci _v,ci _nxt):v(_v),nxt(_nxt){}
};
struct graph{
	int head[max_n+1],cnt;
	node edge[max_m<<1];
	void build(){
		memset(head,-1,sizeof(head)),cnt=-1;
	}
	void insert(ci u,ci v){
		push(u,v);
		push(v,u);
	}
	void push(ci u,ci v){
		edge[++cnt]=node(v,head[u]);
		head[u]=cnt;
	}
};
graph g;
void dfs(int u){
	if(flag)
		return;
	for(int i=g.head[u],v; ~i; i=g.edge[i].nxt){
		if(col[v=g.edge[i].v]==col[u]){
			flag=1;
			return;
		}
		if(!col[v]){
			col[v]=col[u]^3;
			dfs(v);
		}
	}
}
int main(){
	int n,m;
	scanf("%d",&n),m=n<<1,g.build();
	for(int i=0; ++i<=n; g.insert(u[i],v[i]),g.insert((i<<1)-1,i<<1))
		scanf("%d%d",u+i,v+i);
	for(int i=0; ++i<=m; )
		if(!col[i]){
			col[i]=1;
			dfs(i);
			if(flag){
				puts("-1");
				return 0;
			}
		}
	dfs(1);
	if(flag){
		puts("-1");
		return 0;
	}
	for(int i=0; ++i<=n; printf("%d %d\n",col[u[i]],col[v[i]]));
	return 0;
}
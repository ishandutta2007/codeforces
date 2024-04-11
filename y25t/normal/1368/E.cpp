#include<cstdio>
#include<queue>
#define N 200005

int T;

int n,m;

int hd[N],_hd;
struct edge{
	int v,nxt;
}e[N<<2];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

int deg[N];

std::queue<int> q;

int col[N];

int ans;

int main(){
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=n;i++)
			hd[i]=deg[i]=col[i]=0;
		_hd=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
			deg[v]++;
		}
		for(int i=1;i<=n;i++)
			if(!deg[i])
				q.push(i);
		while(q.size()){
			int u=q.front();
			q.pop();
			for(int i=hd[u];i;i=e[i].nxt){
				int v=e[i].v;
				if(col[u]==1)
					col[v]=2;
				if(col[v]!=2&&col[u]==0)
					col[v]=1;
				if(!--deg[v])
					q.push(v);
			}
		}
		ans=0;
		for(int i=1;i<=n;i++)
			if(col[i]==2)
				ans++;
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			if(col[i]==2)
				printf("%d ",i);
		puts("");
	}
}
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define mp std::make_pair
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 100005
#define W 1000005

int n,m,q,tot;

int hd[N],_hd;
struct edge{
	int v,w,nxt;
}e[N];
inline void addedge(int u,int v,int w){
	e[++_hd]=(edge){v,w,hd[u]};
	hd[u]=_hd;
}

std::vector<int> b[W];
std::priority_queue<std::pair<int,int> > h;
ll dis[N],d[N];
inline void dij(int tp){
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	if(!tp)
		h.push(mp(0,1));
	else
		b[0].push_back(1);
	int cur=0;
	while(1){
		int u;
		if(!tp){
			if(!h.size())
				break;
			u=h.top().second;
			h.pop();
		}
		else{
			while(cur<=tot&&!b[cur].size())
				cur++;
			if(cur>tot)
				break;
			u=b[cur].back();
			b[cur].pop_back();
			if(dis[u]<cur)
				continue;
		}
//		printf("*%d %d\n",u,dis[u]);
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].v,w=e[i].w;
			if(dis[u]+w<dis[v]){
				dis[v]=dis[u]+w;
				if(!tp)
					h.push(mp(-dis[v],v));
				else if(dis[v]<=tot)
					b[dis[v]].push_back(v);
			}
		}
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
	}
	dij(0);
	for(int u=1;u<=n;u++)
		for(int i=hd[u];i;i=e[i].nxt)
			e[i].w+=dis[u]-dis[e[i].v];
	for(int i=1;i<=n;i++)
		d[i]=dis[i];
	memset(dis,0,sizeof(dis));
//	for(int i=1;i<=n;i++)
//		printf("%d ",d[i]);
//	puts("");
	while(q--){
		int opt;
		scanf("%d",&opt);
		if(opt==1){
			int u;
			scanf("%d",&u);
			printf("%lld\n",dis[u]+d[u]<inf?dis[u]+d[u]:-1);
		}
		else{
			int k;
			scanf("%d",&k);
			tot+=k;
			while(k--){
				int l;
				scanf("%d",&l);
				e[l].w++;
			}
			dij(1);
		}
	}
}
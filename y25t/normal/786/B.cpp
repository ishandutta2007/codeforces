#include<cstdio>
#include<cstring>
#include<queue>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 1000005

inline void rd(int &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}

int n,m,s;

int hd[N],_hd;
struct edge{
	int v,w,nxt;
}e[N<<3];
inline void addedge(int u,int v,int w){
	e[++_hd]=(edge){v,w,hd[u]};
	hd[u]=_hd;
}

int pos[N],nn;
inline void build(int p,int L,int R,int opt){
	nn=std::max(nn,p);
	if(L==R){
		if(!opt)
			pos[L]=p;
		return;
	}
	if(!opt){
		addedge(p,p<<1,0);
		addedge(p,p<<1|1,0);
	}
	else{
		addedge((p<<1)+nn,p+nn,0);
		addedge((p<<1|1)+nn,p+nn,0);
	}
	int mid=(L+R)>>1;
	build(p<<1,L,mid,opt);
	build(p<<1|1,mid+1,R,opt);
}
inline void sch(int p,int L,int R,int l,int r,int u,int w,int opt){
	if(L>r||R<l)
		return;
	if(l<=L&&R<=r){
		if(!opt)
			addedge(pos[u]+nn,p,w);
		else
			addedge(p+nn,pos[u],w);
		return;
	}
	int mid=(L+R)>>1;
	sch(p<<1,L,mid,l,r,u,w,opt);
	sch(p<<1|1,mid+1,R,l,r,u,w,opt);
}

ll dis[N];
bool vis[N];
std::priority_queue<std::pair<ll,int> > q;
inline void dij(){
	memset(dis,0x3f,sizeof(dis));
	dis[pos[s]+nn]=0;
	q.push(std::make_pair(0,pos[s]+nn));
	while(!q.empty()){
		int u=q.top().second;
		q.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].v,w=e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v]=dis[u]+w;
				q.push(std::make_pair(-dis[v],v));
			}
		}
	}
}

int main(){
	rd(n),rd(m),rd(s);
	build(1,1,n,0);
	build(1,1,n,1);
	for(int i=1;i<=n;i++){
		addedge(pos[i],pos[i]+nn,0);
		addedge(pos[i]+nn,pos[i],0);
	}
	while(m--){
		int opt,u,l,r,w;
		rd(opt),rd(u);
		if(opt==1){
			rd(l),rd(w);
			addedge(pos[u]+nn,pos[l],w);
		}
		else{
			rd(l),rd(r),rd(w);
			sch(1,1,n,l,r,u,w,opt==3);
		}
	}
	dij();
	for(int i=1;i<=n;i++)
		printf("%lld ",dis[pos[i]]==inf?-1:dis[pos[i]]);
}
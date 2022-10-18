#include<cstdio>
#include<algorithm>
#define N 200005

int n;

int f[N],tot;

int hd[N],_hd=1;
struct edge{
	int v,nxt;
}e[N<<1];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

bool del[N];

int sz[N];
inline void dfs(int u,int fa,int k,int &id){
	sz[u]=1;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa||del[i>>1])
			continue;
		dfs(v,u,k,id);
		sz[u]+=sz[v];
		if(sz[v]==f[k-1]||sz[v]==f[k-2])
			id=(i>>1);
	}
}
inline bool chk(int u,int k){
	if(k<=1)
		return 1;
	int id=-1;
	dfs(u,0,k,id);
	if(id==-1)
		return 0;
	del[id]=1;
	int x=e[id<<1].v,y=e[id<<1|1].v;
	if(sz[x]>sz[y])
		std::swap(x,y);
	if(sz[x]==f[k-1])
		return chk(x,k-1)&&chk(y,k-2);
	else
		return chk(x,k-2)&&chk(y,k-1);
}

int main(){
	scanf("%d",&n);
	f[0]=f[1]=1;
	tot=1;
	while(f[tot]<n){
		tot++;
		f[tot]=f[tot-1]+f[tot-2];
	}
	if(f[tot]!=n){
		puts("NO");
		return 0;
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	puts(chk(1,tot)?"YES":"NO");
}
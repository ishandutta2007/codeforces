#include<cstdio>
#include<algorithm>
#define N 12505
#define M 1000005

int n,m;

int hd[N],_hd;
struct edge{
	int v,nxt;
}e[M];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

int E[M];

int a[N],b[N],c[M];

bool vis[M<<1];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		if(u<v)
			std::swap(u,v);
		addedge(u,v);
		E[i]=u;
		c[i]++;
		a[u]++,a[v]++;
	}
	for(int u=1;u<=n;u++){
		int l=a[u],r=a[u];
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(b[v])
				r++;
			else
				l--;
			vis[a[v]]=1;
		}
		int x=a[u];
		for(int i=l;i<=r;i++)
			if(!vis[i])
				x=i;
		for(int i=hd[u];i;i=e[i].nxt){
			int v=e[i].v;
			if(b[v]&&a[u]<x){
				b[v]--;
				c[i]++;
				a[u]++;
			}
			if(!b[v]&&a[u]>x){
				b[v]++;
				c[i]--;
				a[u]--;
			}
			vis[a[v]]=0;
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(b[i])
			cnt++;
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)
		if(b[i])
			printf("%d ",i);
	puts("");
	for(int i=1;i<=m;i++)
		printf("%d %d %d\n",E[i],e[i].v,c[i]);
}
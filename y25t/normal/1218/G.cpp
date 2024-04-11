#include<bits/stdc++.h>
#define N 100005

int n,m;
char s[N];

int hd[N],_hd=1;
struct edge{
	int v,nxt;
}e[N<<1];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

int a[N],b[N],c[N];

int ans[N];

int x,y,z,f[N];
bool vis[N];
inline void dfs1(int u){
	vis[u]=1;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(vis[v]){
			if(c[u]==c[v])
				x=u,y=v;
			continue;
		}
		c[v]=c[u]^1;
		dfs1(v);
		a[u]+=(ans[i>>1]=c[v]-a[v]);
		a[v]=c[v];
	}
}
bool flg[N];
inline void dfs2(int u){
	flg[u]=1;
	a[u]=0;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(u==x&&v==y){
			z=i;
			continue;
		}
		if(flg[v]){
			ans[i>>1]=0;
			continue;
		}
		f[v]=i^1;
		dfs2(v);
		a[u]+=(ans[i>>1]=b[v]-a[v]);
		a[v]=b[v];
	}
}

int main(){
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
		b[i]=s[i]-'X';
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(++u,++v);
		addedge(v,u);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			x=0;
			dfs1(i);
			if(x){
				dfs2(x);
				int tmp=(b[x]-a[x])<<1;
				ans[z>>1]+=tmp;
				for(;y!=x;y=e[f[y]].v)
					ans[f[y]>>1]+=(tmp=-tmp);
			}
			else if((a[i]%3+3)%3==1&&e[hd[i]].nxt)
				ans[hd[i]>>1]++,ans[e[hd[i]].nxt>>1]++;
		}
	for(int i=1;i<=m;i++){
		int tmp=(ans[i]%3+3)%3;
		printf("%d %d %d\n",e[i<<1].v-1,e[i<<1|1].v-1,tmp?tmp:3);
	}
}
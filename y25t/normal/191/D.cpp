#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define N 100005
#define M 300005

char buf[1<<25],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<25,stdin),p1==p2)?EOF:*p1++)
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

inline void chk(int &x,int y){
	x=std::min(x,y);
}

int n,m;

int Hd[N],_Hd=1,hd[N<<1],_hd;
struct edge{
	int v,nxt;
}E[M<<1],e[N<<1];
inline void addE(int u,int v){
	E[++_Hd]=(edge){v,Hd[u]};
	Hd[u]=_Hd;
}
inline void adde(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

int dfn[N],_dfn,low[N];
int st[N],top;
int tot;
inline void Dfs(int u,int pre){
	low[u]=dfn[u]=++_dfn;
	st[++top]=u;
	for(int o=Hd[u];o;o=E[o].nxt){
		int v=E[o].v;
		if(!dfn[v]){
			Dfs(v,o),low[u]=std::min(low[u],low[v]);
			if(low[v]>dfn[u])
				adde(u,v),top--;
			else if(low[v]==dfn[u]){
				adde(u,++tot);
				while(top){
					int w=st[top--];
					adde(tot,w);
					if(w==v)
						break;
				}
			}
		}
		else if(o!=(pre^1))
			low[u]=std::min(low[u],dfn[v]);
	}
}

int f[N<<1][3],g[3];
inline void dfs(int u){
	f[u][0]=0,f[u][1]=f[u][2]=inf;
	if(u<=n){
		for(int o=hd[u];o;o=e[o].nxt){
			int v=e[o].v;
			dfs(v);
			for(int i=0;i<3;i++)
				g[i]=inf;
			for(int i=0;i<3;i++) for(int j=(v<=n);j<3-(v<=n);j++)
				for(int k=0;k<=i&&k<=j;k++) if(i-k+j-k<3)
					chk(g[i-k+j-k],f[u][i]+f[v][j]+k);
			for(int i=0;i<3;i++)
				f[u][i]=g[i];
		}
	}
	else{
		for(int o=hd[u];o;o=e[o].nxt){
			int v=e[o].v;
			dfs(v);
			for(int i=0;i<3;i++)
				g[i]=inf;
			for(int i=0;i<3;i++) for(int j=0;j<2;j++)
				chk(g[std::min(2,i+j)],f[u][i]+f[v][j*2]+j);
			for(int i=0;i<3;i++)
				f[u][i]=g[i];
		}
		int x=std::min(std::min(f[u][0],f[u][1])+1,f[u][2]),y=std::min(f[u][1],f[u][2])-1;
		f[u][0]=x,f[u][1]=inf,f[u][2]=y;
	}
	for(int o=0;o<2;o++) for(int i=0;i<2;i++)
		chk(f[u][i],f[u][i+1]+1),chk(f[u][i+1],f[u][i]);
}

int main(){
	rd(n),rd(m);
	for(int i=1;i<=m;i++){
		int u,v;
		rd(u),rd(v);
		addE(u,v),addE(v,u);
	}
	tot=n,Dfs(1,0);
	dfs(1);
	printf("%d %d\n",f[1][0],m);
}
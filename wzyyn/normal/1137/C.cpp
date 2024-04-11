#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=100005,D=51;
struct edge{
	int to,next;
}e[N*D],E[N*D];
int head[N*D],Head[N*D],tot;
int n,m,d,cnt;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void Add(int x,int y){
	E[++tot]=(edge){y,Head[x]};
	Head[x]=tot;
}
int dfn[N*D],low[N*D];
int stk[N*D],co[N*D];
char ok[N*D];
int *q=stk,*deg=dfn;
int f[N*D],g[N*D],ans;
bool Vis[N],vis[N*D];
inline void tarjan(int x){
	dfn[x]=low[x]=++*dfn;
	vis[x]=1; stk[++*stk]=x;
	for (int i=head[x];i;i=e[i].next)
		if (!dfn[e[i].to]){
			tarjan(e[i].to);
			low[x]=min(low[x],low[e[i].to]);
		}
		else if (vis[e[i].to])
			low[x]=min(low[x],dfn[e[i].to]);
	if (low[x]==dfn[x]){
		++cnt;
		f[cnt]=-(1<<30); g[cnt]=0;
		int y=23333333,las=*stk;
		for (;y!=x;){
			y=stk[(*stk)--];
			if (!Vis[(y-1)/d]&&ok[y]=='1')
				Vis[(y-1)/d]=1,++g[cnt];
			vis[y]=0; co[y]=cnt;
		}
		For(j,(*stk)+1,las)
			Vis[(stk[j]-1)/d]=0;
	}
}
#define id(x,y) (((x)-1)*d+(y))
int main(){
	scanf("%d%d%d",&n,&m,&d);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		For(j,1,d) add(id(x,j),id(y,j%d+1));
	}
	For(i,1,n)
		scanf("%s",ok+(i-1)*d+1);
	For(i,1,n*d)
		if (!dfn[i])
			tarjan(i);
	f[co[1]]=tot=0;
	For(i,1,cnt) deg[i]=0;
	For(i,1,n*d)
		for (int j=head[i];j;j=e[j].next)
			if (co[i]!=co[e[j].to]){
				Add(co[i],co[e[j].to]);
				deg[co[e[j].to]]++;
			}
	int h=0,t=0;
	For(i,1,cnt) if (deg[i]==0) q[++t]=i;
	while (h!=t){
		int x=q[++h];
		ans=max(ans,f[x]+=g[x]);
		for (int i=Head[x];i;i=E[i].next){
			f[E[i].to]=max(f[E[i].to],f[x]);
			if (!--deg[E[i].to]) q[++t]=E[i].to;
		}
	}
	printf("%d\n",ans);
}
/*
4 5 3
3 1
1 2
2 4
4 1
2 3
011
110
111
001
*/
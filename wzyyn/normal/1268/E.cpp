#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=500005;
struct edge{
	int to,next,id;
}e[N*2];
int head[N],q[N],nx[N],tot,n,m;
int X[N],Y[N],f[N],del[N],to[N];
int dfn[N],low[N],fa[N],faid[N];
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
void tarjan(int x){
	dfn[x]=low[x]=++*dfn;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			if (!dfn[e[i].to]){
				fa[e[i].to]=x;
				faid[e[i].to]=e[i].id;
				tarjan(e[i].to);
				low[x]=min(low[x],low[e[i].to]);
			}
			else low[x]=min(low[e[i].to],low[x]); 
		}
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&fa[e[i].to]!=x&&dfn[e[i].to]>dfn[x]){
			*q=0; q[++*q]=e[i].id;
			//printf("%d %d %d\n",x,e[i].to,fa[x],fa[e[i].to]);
			for (int j=e[i].to;j!=x;j=fa[j])
				q[++*q]=faid[j];
			//printf("%d %d\n",x,e[i].to);
			int idd=1;
			For(j,1,*q) nx[j]=(j==*q?1:j+1);
			For(j,2,*q) if (q[j]<q[idd]) idd=j;
			int p1=idd;
			for (;nx[p1]!=idd&&q[nx[p1]]>q[p1];p1=nx[p1]);
			int p2=p1;
			for (;nx[p1]!=idd&&q[nx[p1]]<q[p1];p1=nx[p1]);
			//printf("INFO %d %d %d\n",p1,p2,idd);
			if (nx[p1]==idd) to[q[p2]]=q[idd];
		}
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		scanf("%d%d",&X[i],&Y[i]);
		add(X[i],Y[i],i);
		add(Y[i],X[i],i);
	}
	tarjan(1);
	For(i,1,n) f[i]=1;
	Rep(i,m,1){
		int v=f[X[i]]+f[Y[i]]-del[i];
		del[to[i]]=f[X[i]]=f[Y[i]]=v;
	}
	For(i,1,n)
		printf("%d ",f[i]-1);
}
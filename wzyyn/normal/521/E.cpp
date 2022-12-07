#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=200005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n,m,t;
int vis[N],dep[N],fa[N];
int q1[N],q2[N],q3[N],co[N];
pii q[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x){
	vis[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]){
			fa[e[i].to]=x;
			dep[e[i].to]=dep[x]+1;
			dfs(e[i].to);
		}
		else
			if (dep[e[i].to]<dep[x])
				if (e[i].to!=fa[x]){
					//printf("WZP %d %d\n",x,e[i].to);
					q[++t]=pii(x,e[i].to);
				}
}
void getpath(int x,int y,int *q1){
	for (;x!=y;x=fa[x]) q1[++*q1]=x;
	q1[++*q1]=y;
}
void output(int x,int y,int px){
	int py=(dep[q[x].se]<dep[q[y].se]?q[y].se:q[x].se);
	//printf("INF %d %d %d %d\n",x,y,px,py);
	puts("YES");
	getpath(px,py,q1);
	For(i,0,*q1) printf("%d ",q1[i]); puts("");
	*q1=0;
	getpath(q[x].fi,px,q2);
	for (;*q2;q1[++*q1]=q2[*q2],--*q2);
	getpath(py,q[x].se,q2);
	for (;*q2;q1[++*q1]=q2[*q2],--*q2);
	For(i,0,*q1) printf("%d ",q1[i]); puts("");
	*q1=0;
	getpath(q[y].fi,px,q2);
	for (;*q2;q1[++*q1]=q2[*q2],--*q2);
	getpath(py,q[y].se,q2);
	for (;*q2;q1[++*q1]=q2[*q2],--*q2);
	For(i,0,*q1) printf("%d ",q1[i]); puts("");
	*q1=0;
	exit(0);
}
void addpth(int id){
	int x=q[id].fi,y=q[id].se;
	for (;x!=y;x=fa[x])
		if (!co[x]) co[x]=id;
		else output(co[x],id,x);
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	For(i,1,n)
		if (!vis[i]){
			t=0; dfs(i);
			for (;t;addpth(t),--t);
		}
	puts("NO");
}
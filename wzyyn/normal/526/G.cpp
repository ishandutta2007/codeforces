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
const int N=100005;
struct edge{
	int to,next,v;
}e[N*2];
int head[N],tot;
int mxd,mx,n,Q,S,T;
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
}
void find(int x,int fa,int d){
	if (d>mxd) mxd=d,mx=x;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa)
			find(e[i].to,x,d+e[i].v);
}
struct node{
	int fa[N][20],d[N];
	int hson[N],v[N],ans[N];
	int top,co[N];
	pii q[N];
	void dfs(int x){
		hson[x]=x;
		for (int i=head[x];i;i=e[i].next)
			if (e[i].to!=fa[x][0]){
				fa[e[i].to][0]=x;
				d[e[i].to]=d[x]+e[i].v;
				dfs(e[i].to);
				int tmp=v[e[i].to]+e[i].v;
				if (tmp<=v[x])
					q[++top]=pii(tmp,hson[e[i].to]);
				else{
					if (hson[x]!=x) q[++top]=pii(v[x],hson[x]);
					hson[x]=hson[e[i].to];
					v[x]=tmp;
				}
			}
	}
	void build(int rt){
		dfs(rt);
		q[0]=pii(1<<30,0);
		q[++top]=pii(v[rt],hson[rt]);
		sort(q+1,q+top+1,greater<pii>());
		For(i,1,top){
			ans[i]=ans[i-1]+q[i].fi;
			int x=q[i].se;
			for (;x!=rt&&!co[x];)
				co[x]=i,x=fa[x][0];
		}
		For(i,1,16) For(j,1,n)
			fa[j][i]=fa[fa[j][i-1]][i-1];
	}
	int F(int x,int y){
		y=2*y-1;
		if (co[x]<=y) return ans[min(top,y)];
		int val=v[x]+d[x];
		Rep(i,16,0)	if (q[co[fa[x][i]]].fi<=q[y].fi) x=fa[x][i];
		return (val-d[fa[x][0]])+max(ans[y-1],ans[y]-v[fa[x][0]]);
	}
}A,B;
int main(){
	scanf("%d%d",&n,&Q);
	For(i,1,n-1){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v); add(y,x,v);
	}
	find(1,0,0); S=mx; mxd=0;
	find(S,0,0); T=mx; mxd=0;
	A.build(S); B.build(T);
	int las=0;
	while (Q--){
		int x,y;
		scanf("%d%d",&x,&y);
		x=(x+las+n-1)%n+1;
		y=(y+las+n-1)%n+1;
		las=max(A.F(x,y),B.F(x,y));
		printf("%d\n",las);
		las%=n;
	}
}
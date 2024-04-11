#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=300005;
struct edge{
	int to,next;
};
int n,m,Q;
namespace TR1{
	edge e[N*2];
	int head[N],tot,E_cnt;
	int sz[N],dfn[N],ed[N];
	int dep[N],top[N],S[N];
	int f[N],fa[N],co[N];
	int pos[N],hson[N];
	pii E[N];
	int get(int x){
		return x==f[x]?x:f[x]=get(f[x]);
	}
	void add(int x,int y){
		e[++tot]=(edge){y,head[x]};
		head[x]=tot;
		e[++tot]=(edge){x,head[y]};
		head[y]=tot;
	}
	void dfs1(int x){
		sz[x]=1;
		dfn[x]=++*dfn;
		pos[*dfn]=x;
		for (int i=head[x];i;i=e[i].next)
			if (e[i].to!=fa[x]){
				fa[e[i].to]=x;
				dep[e[i].to]=dep[x]+1;
				dfs1(e[i].to);
				sz[x]+=sz[e[i].to];
				if (sz[e[i].to]>sz[hson[x]])
					hson[x]=e[i].to;
			}
		ed[x]=*dfn;
	}
	void dfs2(int x){
		if (!top[x]) top[x]=x;
		if (hson[x]){
			top[hson[x]]=top[x];
			dfs2(hson[x]);
		}
		for (int i=head[x];i;i=e[i].next)
			if (e[i].to!=fa[x]&&e[i].to!=hson[x])
				dfs2(e[i].to);
	}
	int LCA(int x,int y){
		for (;top[x]!=top[y];x=fa[top[x]])
			if (dep[top[x]]<dep[top[y]]) swap(x,y);
		return dep[x]<dep[y]?x:y;
	}
	void add_edge(pii p){
		int x=p.fi,y=p.se;
		//printf("%d %d %d\n",x,y,LCA(x,y));
		S[x]++; S[y]++; S[LCA(x,y)]-=2;
	}
	void build(){
		For(i,1,n) f[i]=i;
		For(i,1,m){
			int x,y;
			scanf("%d%d",&x,&y);
			if (get(x)!=get(y))
				add(x,y),f[get(x)]=get(y);
			else E[++E_cnt]=pii(x,y);
		}
		For(i,1,n)
			if (get(i)==i)
				add(n+1,i);
		dfs1(n+1);
		dfs2(n+1);
		for (;E_cnt;--E_cnt)
			add_edge(E[E_cnt]);
		Rep(i,n+1,1) S[fa[pos[i]]]+=S[pos[i]];
		For(i,1,n+1) co[pos[i]]=(S[pos[i]]?co[fa[pos[i]]]:pos[i]);
		//For(i,1,n+1) printf("%d %d\n",S[i],co[i]);
		For(i,1,n) assert(co[i]!=n+1);
	}
	bool isfa(int x,int y){
		return dfn[x]<=dfn[y]&&ed[y]<=ed[x];
	}
}
int AXIBA;
int readInt(){
	int x;
	scanf("%d",&x);
	x=(x+AXIBA+n-1)%n+1;
	return TR1::co[x];
}
edge e[N*4];
int head[N],tot;
int a[N],x[N],y[N];
int co[N],vis[N],stk[N];
int dfn[N],low[N],q[N*3],qq[N];
bool cmp(int x,int y){
	return TR1::dfn[x]<TR1::dfn[y];
}
void add(int x,int y){
	//printf("add %d %d\n",x,y);
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
	e[++tot]=(edge){x,head[y]};
	head[y]=tot;
}
void tarjan(int x,int fae){
	dfn[x]=low[x]=++*dfn;
	stk[++*stk]=x; vis[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if ((i^fae)>1){
			if (!dfn[e[i].to]){
				int tmp=*stk;
				tarjan(e[i].to,i);
				low[x]=min(low[x],low[e[i].to]);
				if (low[e[i].to]==dfn[e[i].to]){
					++*co;
					for (;;){
						int y=stk[(*stk)--];
						vis[y]=0; co[y]=*co;
						if (y==e[i].to) break;
					}
				}
			}
			else if (vis[e[i].to])
				low[x]=min(low[x],dfn[e[i].to]);
		}
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d%d",&n,&m,&Q);
	TR1::build();
	For(id,1,Q){
		int n,m; *q=0; tot=1;
		scanf("%d%d",&n,&m);
		For(i,1,n) a[i]=q[++*q]=readInt();
		//For(i,1,n) printf("%d ",a[i]); puts("");
		For(i,1,m){
			x[i]=q[++*q]=readInt();
			y[i]=q[++*q]=readInt();
			add(x[i],y[i]);
		}
		sort(q+1,q+*q+1,cmp);
		int top=*q=unique(q+1,q+*q+1)-q-1;
		For(i,1,top-1) q[++*q]=TR1::co[TR1::LCA(q[i],q[i+1])];
		sort(q+1,q+*q+1,cmp);
		*q=unique(q+1,q+*q+1)-q-1;
		top=1; qq[1]=q[1];
		For(i,2,*q){
			for (;!TR1::isfa(qq[top],q[i]);top--);
			if (qq[top]!=::n+1) add(qq[top],q[i]);
			qq[++top]=q[i];
		}
		tarjan(a[1],0); ++*co;
		for (;*stk;co[stk[*stk]]=*co,--(*stk));
		bool flag=0;
		For(i,1,n)
			if (co[a[1]]!=co[a[i]]) flag=1;
		//For(i,1,n) printf("%d ",co[a[i]]); puts("");
		if (!flag){
			puts("YES");
			AXIBA=(AXIBA+id)%(::n);
		}
		else puts("NO");
		For(i,1,*q){
			co[q[i]]=dfn[q[i]]=low[q[i]]=0;
			stk[q[i]]=vis[q[i]]=head[q[i]]=0;
		}
	}
}
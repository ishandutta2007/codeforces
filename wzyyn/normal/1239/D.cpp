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
const int N=2000005;
struct edge{
	int to,next;
}e[N*2];
int head[N],tot,n,m;
int dfn[N],low[N],co[N];
int stk[N],vis[N],col;
int deg[N];
void add(int x,int y){
	//printf("ADD %d %d\n",x,y);
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void tarjan(int x){
	dfn[x]=low[x]=++*dfn;
	stk[++*stk]=x; vis[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (!dfn[e[i].to]){
			tarjan(e[i].to);
			low[x]=min(low[x],low[e[i].to]);
		}
		else if (vis[e[i].to])
			low[x]=min(low[x],dfn[e[i].to]);
	if (dfn[x]==low[x]){
		++col;
		for (int y=23333333;y!=x;){
			y=stk[(*stk)--];
			vis[y]=0;
			co[y]=col;
		}
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,2*n)
		head[i]=deg[i]=dfn[i]=0;
	tot=*dfn=col=0;
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		if (x==y) add(x+n,x);
		else add(x,y+n);
	}
	For(i,1,2*n)
		if (!dfn[i])
			tarjan(i);
	For(i,1,2*n)
		for (int j=head[i];j;j=e[j].next)
			if (co[i]!=co[e[j].to])
				++deg[co[i]];
	bool flag=0;
	For(i,1,n)
		if (co[i]!=co[1])
			flag=1;
	if (!flag) puts("No");
	else{
		puts("Yes");
		int pos=0;
		For(i,1,n)
			if (!deg[co[i]])
				pos=co[i];
		assert(pos!=0);
		int s1=0,s2=0;
		For(i,1,n)
			if (co[i]==pos) ++s1;
			else ++s2;
		printf("%d %d\n",s1,s2);
		For(i,1,n)
			if (co[i]==pos)
				printf("%d ",i);
		puts("");
		For(i,1,n)
			if (co[i]!=pos)
				printf("%d ",i);
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
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
int head[N],tot;
int n,m,S,v[N],co[N];
int dfn[N],low[N];
int stk[N],vis[N];
ll SZ[N],SV[N];
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void build(int ed){
	++*co;
	for (;*stk>ed;){
		int x=stk[*stk];
		--*stk;
		SZ[*co]++;
		SV[*co]+=v[x];
		co[x]=*co;
	}
}
void tarjan(int x,int fa){
	dfn[x]=low[x]=++*dfn;
	vis[x]=1; stk[++*stk]=x;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			if (!dfn[e[i].to]){
				int tmp=*stk;
				tarjan(e[i].to,x);
				low[x]=min(low[x],low[e[i].to]);
				if (low[e[i].to]>dfn[x])
					build(tmp);
			}
			else
				low[x]=min(low[x],dfn[e[i].to]);
		}
}
vector<int> E[N];
ll f[N][2];
void getans(int x,int fa){
	f[x][0]=SV[x];
	f[x][1]=SV[x];
	For(i,0,E[x].size()-1){
		int to=E[x][i];
		if (to==fa) continue;
		getans(to,x);
		SZ[x]=max(SZ[x],SZ[to]);
		f[x][1]=max(f[x][1]+f[to][0],f[x][0]+f[to][1]);
		f[x][0]+=f[to][0];
	}
	if (SZ[x]==1) f[x][0]=0;
	//printf("%d %lld %lld\n",x,f[x][0],f[x][1]);
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&v[i]);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	tarjan(1,0);
	build(0);
	//For(i,1,*co) printf("%lld %lld\n",SZ[i],SV[i]);
	For(i,1,n)
		for (int j=head[i];j;j=e[j].next)
			if (co[i]!=co[e[j].to]){
				//printf("edge %d %d\n",co[i],co[e[j].to]);
				E[co[i]].PB(co[e[j].to]);
			}
	scanf("%d",&S);
	getans(co[S],0);
	printf("%lld\n",f[co[S]][1]);
}
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
const int N=100005;
const int M=10000005;
const int mo=1000000007;
int pri[M/10],mn[M],id[M];
vector<int> e[N];
int n,T,Q,dfn[N],ed[N];
int fa[N][20],dep[N];
int qx[N],qy[N],qL[N],qv[N];
int t[N*2],vis[N],A[N],ans[N];
vector<int> vec[M/10];
pii q1[N],q2[N];
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void change(int x,int v){
	for (;x<=2*n;x+=x&(-x)) t[x]+=v;
}
int ask(int x){
	int ans=0;
	for (;x;x-=x&(-x)) ans+=t[x];
	return ans;
}
void init(){
	For(i,2,M-1){
		if (!mn[i]) mn[i]=i,pri[++*pri]=i;
		for (int j=1;j<=*pri&&i*pri[j]<M;++j){
			mn[i*pri[j]]=pri[j];
			if (i%pri[j]==0) break;
		}
	}
	For(i,1,*pri) id[pri[i]]=i;
}
void insert(int x,int id){
	for (;x!=1;){
		int v=mn[x];
		for (;x%v==0;x/=v);
		vec[::id[v]].PB(id);
	}
}
void dfs(int x){
	dfn[x]=++*dfn;
	for (auto i:e[x])
		if (i!=fa[x][0]){
			fa[i][0]=x;
			dep[i]=dep[x]+1;
			dfs(i);
		}
	ed[x]=++*dfn;
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int tmp=dep[x]-dep[y];
	For(i,0,18) if (tmp&(1<<i)) x=fa[x][i];
	Rep(i,18,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
void solve(int id){
	int top1=0,top2=0;
	for (auto i:vec[id])
		if (i<0) q2[++top2]=pii(-i,qv[-i]);
		else q1[++top1]=pii(i,A[i]);
	for (;top1&&top2;){
		//cout<<id<<' '<<top1<<' '<<top2<<endl;
		//For(i,1,Q) cout<<ans[i]<<endl;
		int tmp1=0,tmp2=0;
		For(i,1,top1){
			change(dfn[q1[i].fi],-1);
			change(ed[q1[i].fi],1);
		}
		For(i,1,top2){
			int at=q2[i].fi;
			int val1=ask(ed[qL[at]]-1)-ask(ed[qx[at]]-1);
			int val2=ask(ed[qL[at]])-ask(ed[qy[at]]-1);
			ans[at]=1ll*ans[at]*power(pri[id],val1+val2)%mo;
		}
		For(i,1,top1){
			change(dfn[q1[i].fi],1);
			change(ed[q1[i].fi],-1);
		}
		For(i,1,top1) q1[i].se/=pri[id];
		For(i,1,top2) q2[i].se/=pri[id];
		For(i,1,top1)
			if (q1[i].se%pri[id]==0)
				q1[++tmp1]=q1[i];
		For(i,1,top2)
			if (q2[i].se%pri[id]==0)
				q2[++tmp2]=q2[i];
		top1=tmp1; top2=tmp2;
	}
}
int main(){
	//freopen("1.in","r",stdin);
	init();
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1);
	For(i,1,18) For(j,1,n)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	For(i,1,n){
		scanf("%d",&A[i]);
		insert(A[i],i);
	}
	scanf("%d",&Q);
	For(i,1,Q){
		scanf("%d%d%d",&qx[i],&qy[i],&qv[i]);
		qL[i]=LCA(qx[i],qy[i]);
		insert(qv[i],-i);
		ans[i]=1;
	}
	For(i,1,*pri) solve(i);
	For(i,1,Q) printf("%d\n",ans[i]);
}
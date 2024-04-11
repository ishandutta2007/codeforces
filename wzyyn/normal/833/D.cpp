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
const int mo=1000000007;
const int N=100005;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
struct edge{
	int to,next,c;
}e[N*2];
struct node{
	int d0,d1,be,x;
}q[N];
int head[N],v[N],tot,n,top;
int sz[N],vis[N],mxv,rt;
ll sum[N*2],Sum[N],S[N*4];
void add(int x,int y,int c){
	e[++tot]=(edge){y,head[x],c}; 
	head[x]=tot;
}
void init(int x,int fa){
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			init(e[i].to,x);
			sum[i]+=1ll*(n-sz[e[i].to])*sz[e[i].to];
			sz[x]+=sz[e[i].to];
		}
}
void dfs(int x,int fa,int n){
	sz[x]=1; int mx=0;
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]&&e[i].to!=fa){
			dfs(e[i].to,x,n);
			sz[x]+=sz[e[i].to];
			mx=max(mx,sz[e[i].to]);
		}
	mx=max(mx,n-sz[x]);
	if (mx<mxv) mxv=mx,rt=x;
}
void getseq(int x,int fa,int be,int d0,int d1){
	q[++top]=(node){d0,d1,be,x};
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to])
			getseq(e[i].to,x,be,d0+(e[i].c?1:-2),d1+(e[i].c?-2:1));
}
void solve_que(int l,int r,int dv){
	int len=r-l+1;
	For(i,-2*len-1,2*len+1) S[N+N+i]=0;
	For(i,l,r) ++S[N+N+q[i].d0];
	Rep(i,2*len,-2*len-1) S[N+N+i]+=S[N+N+i+1];
	For(i,l,r) Sum[q[i].x]+=S[N+N-q[i].d0+1]*dv;
	
	For(i,-2*len-1,2*len+1) S[N+N+i]=0;
	For(i,l,r) ++S[N+N+q[i].d1];
	Rep(i,2*len,-2*len-1) S[N+N+i]+=S[N+N+i+1];
	For(i,l,r) Sum[q[i].x]+=S[N+N-q[i].d1+1]*dv;
}
void solve_que(){
	For(i,1,top) Sum[q[i].x]=0;
	solve_que(1,top,-1);
	int l=2;
	For(i,3,top+1)
		if (q[i].be!=q[i-1].be||i==top+1)
			solve_que(l,i-1,1),l=i;
}
void upd_sum(int x,int fa){
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].to]){
			upd_sum(e[i].to,x);
			sum[i]+=Sum[e[i].to];
			Sum[x]+=Sum[e[i].to];
		}
}
void solve(int x,int n){
	if (n==1) return;
	mxv=1<<30; dfs(x,0,n);
	vis[x=rt]=1; top=1;
	q[top]=(node){0,0,x,x};
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]) getseq(e[i].to,x,e[i].to,e[i].c?1:-2,e[i].c?-2:1);
	//For(i,1,top) cout<<q[i].d0<<' '<<q[i].d1<<' '<<q[i].be<<' '<<q[i].x<<endl;
	solve_que();
	upd_sum(x,0);
	for (int i=head[x];i;i=e[i].next)
		if (!vis[e[i].to]) solve(e[i].to,sz[e[i].to]>sz[x]?n-sz[x]:sz[e[i].to]);
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y,c;
		scanf("%d%d%d%d",&x,&y,&v[i],&c);
		add(x,y,c); add(y,x,c);
	}
	init(1,0);
	solve(1,n);
	int ans=1;
	For(i,1,n-1){
		//cout<<sum[i*2-1]+sum[i*2]<<endl;
		ans=1ll*ans*power(v[i],(sum[i*2-1]+sum[i*2])%(mo-1))%mo;
	}
	printf("%d\n",ans);
}
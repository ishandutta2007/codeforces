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
const int N=200005;
struct edge{
	int to,next;
}e[N*2];
int n,tot,a[N],head[N];
int func[N],p[N],fa[N];
int dep[N],dfn[N],ed[N];
int top[N],sz[N],q[N*2];
int f[N],phi[N],ans;
int power(int x,int y){
	int s=1;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
void init(){
	For(i,1,N-1) phi[i]=i;
	For(i,1,N-1) For(j,2,(N-1)/i) phi[i*j]-=phi[i];
	For(i,1,N-1) func[i]=1ll*i*power(phi[i],mo-2)%mo;
	For(i,1,N-1) For(j,2,(N-1)/i) func[i*j]=(func[i*j]+mo-func[i])%mo;
}
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
void dfs(int x){
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			fa[e[i].to]=x;
			dep[e[i].to]=dep[x]+1;
			dfs(e[i].to);
			sz[x]+=sz[e[i].to];
		}
}
void dfs2(int x,int tp){
	dfn[x]=++*dfn;
	top[x]=tp;
	int k=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&sz[e[i].to]>sz[k])
			k=e[i].to;
	if (k) dfs2(k,tp);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=k)
			dfs2(e[i].to,e[i].to);
	ed[x]=*dfn;
}
int LCA(int x,int y){
	for (;top[x]!=top[y];x=fa[top[x]])
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
	return dep[x]<dep[y]?x:y;
}
bool cmp(int x,int y){
	return dfn[x]<dfn[y];
}
bool isfa(int x,int y){
	return dfn[x]<=dfn[y]&&ed[y]<=ed[x];
}
void solve(int x){
	*q=0;
	int sum=0;
	For(i,1,n/x) q[++*q]=p[x*i];
	For(i,1,n/x) sum=(sum+phi[i*x])%mo;
	sort(q+1,q+*q+1,cmp);
	For(i,1,(*q)-1) q[i+(*q)]=LCA(q[i],q[i+1]);
	sort(q+1,q+2**q,cmp);
	*q=unique(q+1,q+2**q)-q-1;
	For(i,1,*q) f[q[i]]=(a[q[i]]%x==0?phi[a[q[i]]]:0);
	//For(i,1,*q) cout<<q[i]<<' '; cout<<endl;
	int top=1,s=0;
	For(i,2,*q){
		for (;!isfa(q[top],q[i]);--top){
			int x=q[top];
			s=(s+2ll*f[x]*(sum+mo-f[x])%mo*(dep[x]-dep[q[top-1]]))%mo;
			f[q[top-1]]=(f[q[top-1]]+f[x])%mo;
		}
		q[++top]=q[i];
	}
	for (;top>=2;--top){
		int x=q[top];
		s=(s+2ll*f[x]*(sum+mo-f[x])%mo*(dep[x]-dep[q[top-1]]))%mo;
		f[q[top-1]]=(f[q[top-1]]+f[x])%mo;
	}
	//cout<<s<<endl;
	ans=(ans+1ll*s*func[x])%mo;
}
int main(){
	init();
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]),p[a[i]]=i;
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1);
	dfs2(1,1);
	For(i,1,n) solve(i);
	//printf("%d\n",ans);
	ans=1ll*ans*power(n,mo-2)%mo;
	ans=1ll*ans*power(n-1,mo-2)%mo;
	printf("%d\n",ans);
}
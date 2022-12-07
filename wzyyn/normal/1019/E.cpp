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
#define Hull vector<pll>
const int N=200005;
struct edge{
	int to,next,a,b,id;
}e[N*2];
int head[N],mat[N],tot;
int deg[N],n,T,nd,ed,mxv;
int sz[N],vis[N],px,py,pid;
Hull ans;
bool cmp(pll x,pll y,pll z){
	y.fi-=x.fi; y.se-=x.se;
	z.fi-=x.fi; z.se-=x.se;
	return y.fi*z.se>=z.fi*y.se;
}
pll operator +(pll a,pll b){
	return pll(a.fi+b.fi,a.se+b.se);
}
Hull convex_hull(Hull v){
	static pll a[N*30];
	int sz=v.size();
	For(i,0,sz-1) a[i+1]=v[i];
	sort(a+1,a+sz+1);
	int tp=1;
	For(i,2,sz){
		for (;tp>=1&&a[tp].fi==a[i].fi&&a[tp].se<a[i].se;--tp);
		for (;tp>=2&&cmp(a[tp-1],a[tp],a[i]);--tp);
		a[++tp]=a[i];
	}
	vector<pll> res;
	For(i,1,tp) res.PB(a[i]);
	return res;
}
void merge(Hull va,Hull vb,int a,int b){
	int sza=va.size(),szb=vb.size();
	int pa=0,pb=0;
	for (;;){
		//cout<<pa<<' '<<pb<<endl;
		ans.PB(pll(va[pa].fi+vb[pb].fi+a,
				   va[pa].se+vb[pb].se+b));
		if (pa==sza-1) ++pb;
		else if (pb==szb-1) ++pa;
		else if (cmp(va[pa]+vb[pb],va[pa+1]+vb[pb],va[pa]+vb[pb+1])) ++pb;
		else ++pa;
		if (pa==sza||pb==szb) break;
	}
}

void add(int x,int y,int a,int b){
	++ed; ++deg[x]; ++deg[y];
	e[++tot]=(edge){y,head[x],a,b,ed};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],a,b,ed};
	head[y]=tot;
}
int getid(int x){
	if (deg[mat[x]]!=2) return mat[x];
	add(mat[x],++nd,0,0);
	return mat[x]=nd;
}
void dfs(int x,int fa,int faid,int n){
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].id]){
			dfs(e[i].to,x,e[i].id,n);
			sz[x]+=sz[e[i].to];
		}
	if (abs(n-2*sz[x])<mxv)
		mxv=abs(n-2*sz[x]),px=x,py=fa,pid=faid;
}
void dfs2(int x,int fa,ll a,ll b,vector<pll> &v){
	v.PB(pll(a,b));
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa&&!vis[e[i].id])
			dfs2(e[i].to,x,a+e[i].a,b+e[i].b,v);
}
void convex(int x,Hull &y){
	y.resize(0);
	dfs2(x,0,0,0,y);
	y=convex_hull(y);
}
void solve(int x,int n){
	//cout<<x<<' '<<n<<endl;
	if (n==1) return;
	mxv=1<<30; dfs(x,0,0,n); vis[pid]=1;
	//cout<<x<<' '<<px<<' '<<py<<' '<<pid<<' '<<sz[px]<<' '<<n<<endl;
	Hull v1,v2;
	convex(px,v1); convex(py,v2);
	merge(v1,v2,e[pid*2].a,e[pid*2].b);
	int pp=px; solve(py,n-sz[pp]); solve(pp,sz[pp]);
}
int main(){
	#ifdef zyy
		freopen("1.in","r",stdin);
	#endif
	scanf("%d%d",&n,&T);
	nd=n; ed=0;
	For(i,1,n) mat[i]=i;
	For(i,1,n-1){
		int x,y,a,b;
		scanf("%d%d%d%d",&x,&y,&a,&b);
		int p=getid(x),q=getid(y);
		add(p,q,a,b);
	}
	solve(1,nd);
	//for (auto i:ans) cout<<i.fi<<' '<<i.se<<endl;
	ans=convex_hull(ans);
	//for (auto i:ans) cout<<i.fi<<' '<<i.se<<endl;
	int sz=ans.size(),p=0;
	For(i,0,T-1){
		for (;p!=sz-1;){
			ll v1=1ll*i*ans[p].fi+ans[p].se;
			ll v2=1ll*i*ans[p+1].fi+ans[p+1].se;
			if (v1<=v2) ++p;
			else break;
		}
		printf("%lld ",1ll*i*ans[p].fi+ans[p].se);
	}
}
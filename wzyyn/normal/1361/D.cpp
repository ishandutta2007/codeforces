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
const int N=1000005;
struct P{
	int x,y;
	bool op(){
		return x==0?y<0:x<0;
	}
	ll operator *(const P &a)const{
		return 1ll*x*a.y-1ll*y*a.x;
	}
	ll d(){
		return 1ll*x*x+1ll*y*y;
	}
}p[N];
bool cmp(P x,P y){
	if (x.op()!=y.op()) return x.op();
	if (x*y) return x*y<0;
	return x.d()<y.d();
}
double d[N];
int n,k,fa[N];
struct edge{
	int to,next;
	double v;
}e[N*2];
int head[N],tot,rt;
int sz[N],id[N],be[N],v[N];
double key[N],dep[N];
void add(int x,int y,double v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],v};
	head[y]=tot;
}
void dfs(int x,int fa,int n){
	sz[x]=1; int mx=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dfs(e[i].to,x,n);
			mx=max(mx,sz[e[i].to]);
			sz[x]+=sz[e[i].to];
		}
	if (sz[x]*2>=n&&mx*2<n) rt=x;
}
void dfs2(int x,int fa){
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			dep[e[i].to]=dep[x]+e[i].v;
			dfs2(e[i].to,x);
			sz[x]+=sz[e[i].to];
		}
	key[x]=(k+1-2*sz[x])*dep[x];
}
bool cmppp(int x,int y){
	return key[x]>key[y];
}
int main(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d%d",&p[i].x,&p[i].y);
	For(i,1,n) if (!p[i].x&&!p[i].y) swap(p[i],p[1]);
	sort(p+2,p+n+1,cmp);
	For(i,2,n) d[i]=sqrt(p[i].d());
	For(i,2,n) fa[i]=(i==2||p[i]*p[i-1]||p[i].op()!=p[i-1].op()?1:i-1);
	For(i,2,n) be[i]=(fa[i]==1?i:be[fa[i]]);
	For(i,2,n) add(i,fa[i],d[i]-d[fa[i]]);
	dfs(1,0,n); dfs2(rt,0);
	//cout<<rt<<endl;
	//For(i,1,n) cout<<key[i]<<' '<<dep[i]<<' '<<fa[i]<<endl;
	For(i,1,n) id[i]=i;
	sort(id+1,id+n+1,cmppp);
	double ans=0,s=0;
	For(i,1,k) ans+=key[id[i]];
	For(i,1,k) if (be[id[i]]!=be[rt]&&id[i]!=1)
		ans+=2*dep[1]*v[be[id[i]]],++v[be[id[i]]],++s;
	ans-=s*(s-1)*dep[1];
	dep[1]=0; dfs2(1,0);
	double ans2=0;
	sort(id+1,id+n+1,cmppp);
	For(i,1,k) ans2+=key[id[i]];
	//cout<<s<<endl;
	printf("%.15lf\n",max(ans,ans2));
}
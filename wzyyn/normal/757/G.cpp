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
const int N=400005;
struct edge{
	int to,next,v;
};
int n,Q;
namespace TR{
	edge e[N*3];
	int head[N],Head[N];
	int nd,tot=1,rt;
	void add(int x,int y,int v){
		e[++tot]=(edge){y,head[x],v};
		head[x]=tot;
	}
	void Add(int x,int y,int v){
		//cout<<"Add "<<x<<' '<<y<<' '<<v<<endl;
		e[++tot]=(edge){y,Head[x],v};
		Head[x]=tot;
		e[++tot]=(edge){x,Head[y],v};
		Head[y]=tot;
	}
	void dfs1(int x,int fa){
		int p=x;
		for (int i=head[x];i;i=e[i].next)
			if (e[i].to!=fa){
				Add(p,e[i].to,e[i].v);
				Add(p,++nd,0); p=nd;
				dfs1(e[i].to,x);
			}
	}
	int vis[N*3],sz[N];
	ll dis[30][N];
	int co[30][N];
	int mx,eid,ex,ey,ch[2*N][2];
	int dep[N*2],key[N*2];
	void dfs(int x,int fa,int n){
		sz[x]=1;
		for (int i=Head[x];i;i=e[i].next)
			if (!vis[i]&&e[i].to!=fa){
				dfs(e[i].to,x,n);
				sz[x]+=sz[e[i].to];
				int val=abs(n-2*sz[e[i].to]);
				if (val<mx) mx=val,eid=i,ex=x,ey=e[i].to;
			}
			//if (abs(2*sz[e[i].to]))
	}
	void color(int x,int fa,ll *d,int *co){
		for (int i=Head[x];i;i=e[i].next)
			if (!vis[i]&&e[i].to!=fa){
				d[e[i].to]=d[x]+e[i].v;
				co[e[i].to]=co[x];
				color(e[i].to,x,d,co);
			}
	}
	int divide(int k,int n,int d){
		//cout<<"divide "<<k<<' '<<n<<' '<<d<<endl;
		if (n==1) return k;
		mx=1e9; dfs(k,0,n);
		vis[eid]=vis[eid^1]=1;
		int p=++nd; dep[p]=d; co[d][ey]=1;
		int p1=ex,p2=ey; key[p]=e[eid].v;
		color(p1,0,dis[d],co[d]);
		color(p2,0,dis[d],co[d]);
		ch[p][0]=divide(p1,n-sz[p2],d+1);
		ch[p][1]=divide(p2,sz[p2],d+1);
		return p;
	}
	void init(){
		For(i,1,n-1){
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			add(x,y,v); add(y,x,v);
		}
		nd=n;
		dfs1(1,0);
		rt=divide(1,nd,0);
	}
}
const int M=8000005;
struct Treenode{
	int s1[2],ch[2];
	ll s2[2];
}t[M];
int ls[M],rs[M],nd;
int rt[N],a[N];
void insert(int &nk,int k,int p,int v){
	assert(p!=0);
	if (p<=n) return;
	nk=++nd; t[nk]=t[k];
	int d=TR::dep[p],c=TR::co[d][v];
	t[nk].s1[c]++; t[nk].s2[c]+=TR::dis[d][v];
	insert(t[nk].ch[c],t[k].ch[c],TR::ch[p][c],v);
}
void insert(int x,int v){
	insert(rt[x],rt[x-1],TR::rt,v);
	//cout<<x<<' '<<rt[x]<<endl;
}
ll query(int k,int p,int v){
	//cout<<"query "<<k<<' '<<p<<' '<<v<<endl;
	assert(p!=0);
	if (p<=n) return 0;
	int d=TR::dep[p],c=TR::co[d][v];
	ll ans=query(t[k].ch[c],TR::ch[p][c],v);
	ans+=t[k].s2[c^1]+1ll*t[k].s1[c^1]*(TR::dis[d][v]+TR::key[p]);
	return ans;
}
ll query(int x,int v){
	return query(rt[x],TR::rt,v);
} 
int main(){
	#ifdef zyy	
		freopen("1.in","r",stdin);
	#endif
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]); 
	int nn=n;
	TR::init();
	For(i,1,nn) insert(i,a[i]);
	int lastans=0;
	while (Q--){
		int tp;
		scanf("%d",&tp);
		if (tp==1){
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			l^=lastans;
			r^=lastans;
			x^=lastans;
			ll res=query(r,x)-query(l-1,x);
			//printf("%lld %lld\n",query(r,x),query(l-1,x));
			printf("%lld\n",res);
			lastans=res&((1<<30)-1);
		}
		else{
			int x;
			scanf("%d",&x);
			x^=lastans;
			swap(a[x],a[x+1]);
			insert(x,a[x]);
		}
	}
}
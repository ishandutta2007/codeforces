#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
template<typename T> void read(T &x){
	x=0;char c=getchar();T neg=1;
	while(!isdigit(c)){if(c=='-') neg=-1;c=getchar();}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x*=neg;
}
const int MAXN=1e5;
const int LOG_N=18;
const int BLOCK_SZ=632;
const int BLOCK_CNT=MAXN*2/BLOCK_SZ;
int n,qu,a[MAXN+5],c[MAXN+5],key[MAXN+5],hs[MAXN+5],num=0;
int hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int fa[MAXN+5][LOG_N+2],st[MAXN+5],ed[MAXN+5],dep[MAXN+5],seq[MAXN*2+5],tim=0;
int blk,L[BLOCK_CNT+3],R[BLOCK_CNT+3],bel[MAXN*2+5];
void dfs0(int x,int f){
	fa[x][0]=f;st[x]=++tim;seq[tim]=x;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dep[y]=dep[x]+1;dfs0(y,x);
	} ed[x]=++tim;seq[tim]=x;
}
int getlca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=LOG_N;~i;i--) if(dep[x]-(1<<i)>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=LOG_N;~i;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
struct query{
	int l,r,t,id;
	bool operator <(const query &rhs){
		if(bel[l]!=bel[rhs.l]) return bel[l]<bel[rhs.l];
		return r<rhs.r;
	}
} q[MAXN+5];
ll ans=0,res[MAXN+5];int cnt[MAXN+5][2],flg[MAXN+5];
void ins(int x,int y){ans+=cnt[x][y^1];cnt[x][y]++;}
void del(int x,int y){ans-=cnt[x][y^1];cnt[x][y]--;}
void oper(int x){
	flg[seq[x]]^=1;
	if(flg[seq[x]]) ins(c[seq[x]],a[seq[x]]);
	else del(c[seq[x]],a[seq[x]]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]),key[i]=c[i];
	sort(key+1,key+n+1);
	for(int i=1;i<=n;i++) if(key[i]!=key[i-1]) hs[++num]=key[i];
	for(int i=1;i<=n;i++) c[i]=lower_bound(hs+1,hs+num+1,c[i])-hs;
	for(int i=1;i<n;i++){int u,v;scanf("%d%d",&u,&v);adde(u,v);adde(v,u);}
	dfs0(1,0);for(int i=1;i<=LOG_N;i++) for(int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
	blk=(2*n-1)/BLOCK_SZ+1;
	for(int i=1;i<=blk;i++){
		L[i]=(i-1)*BLOCK_SZ+1;
		R[i]=min(i*BLOCK_SZ,2*n);
		for(int j=L[i];j<=R[i];j++) bel[j]=i;
	}
	scanf("%d",&qu);
	for(int i=1;i<=qu;i++){
		int x,y;scanf("%d%d",&x,&y);
		if(st[x]<st[y]) swap(x,y);
		int lca=getlca(x,y);
		if(x==lca){q[i].l=st[x];q[i].r=st[y];q[i].id=i;}
		else{q[i].l=ed[x];q[i].r=st[y];q[i].t=lca;q[i].id=i;}
	} sort(q+1,q+qu+1);int cl=1,cr=0;
	for(int i=1;i<=qu;i++){
		while(cr<q[i].r) oper(++cr);
		while(cl>q[i].l) oper(--cl);
		while(cl<q[i].l) oper(cl++);
		while(cr>q[i].r) oper(cr--);
		if(q[i].t) ans+=cnt[c[q[i].t]][a[q[i].t]^1];
		res[q[i].id]=ans;
		if(q[i].t) ans-=cnt[c[q[i].t]][a[q[i].t]^1];
	}
	for(int i=1;i<=qu;i++) printf("%lld\n",res[i]);
	return 0;
}
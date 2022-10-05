#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
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
typedef unsigned int u32;
typedef unsigned long long u64;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=3e5;
const int LOG_N=19;
const int MOD1=998244353;
const int MOD2=1004535809;
int qpow(int x,int e,int mod){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%mod) if(e&1) ret=1ll*ret*x%mod;
	return ret;
}
int hsbase1,hsbase2;
bool ispri(int x){
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
int pw1[MAXN+5],pw2[MAXN+5],ipw1[MAXN+5],ipw2[MAXN+5];
int n,qu;char s[MAXN+5];
int hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dep[MAXN+5],mxdep[MAXN+5],wson[MAXN+5];
int fa[MAXN+5][LOG_N+2],top[MAXN+5];
int a1[MAXN+5],a2[MAXN+5],b1[MAXN+5],b2[MAXN+5];
void dfs1(int x=1,int f=0){
	fa[x][0]=f;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		a1[y]=(1ll*a1[x]*hsbase1+s[y])%MOD1;
		a2[y]=(1ll*a2[x]*hsbase2+s[y])%MOD2;
		b1[y]=(1ll*s[y]*pw1[dep[x]]+b1[x])%MOD1;
		b2[y]=(1ll*s[y]*pw2[dep[x]]+b2[x])%MOD2;
		dep[y]=mxdep[y]=dep[x]+1;dfs1(y,x);
		if(mxdep[y]>mxdep[x]) mxdep[x]=mxdep[y],wson[x]=y;
	}
}
vector<int> up[MAXN+5],dw[MAXN+5];
void dfs2(int x=1,int tp=1){
	top[x]=tp;
	if(x==tp){
		for(int i=0,cur=x;i<=mxdep[x]-dep[x];i++,cur=fa[cur][0]) up[x].pb(cur);
		for(int i=0,cur=x;i<=mxdep[x]-dep[x];i++,cur=wson[cur]) dw[x].pb(cur);
	} if(wson[x]) dfs2(wson[x],tp);
	for(int e=hd[x];e;e=nxt[e]) if(to[e]!=fa[x][0]&&to[e]!=wson[x]) dfs2(to[e],to[e]);
}
int getlca(int x,int y){
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=LOG_N;~i;i--) if(dep[x]-(1<<i)>=dep[y]) x=fa[x][i];
	if(x==y) return x;
	for(int i=LOG_N;~i;i--) if(fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int get_kanc(int x,int k){
	if(!k) return x;int lg=31-__builtin_clz(k);
	x=fa[x][lg];k-=1<<lg;k-=dep[x]-dep[top[x]];x=top[x];
	return (k>=0)?up[x][k]:dw[x][-k];
}
pii gethash1(int x,int y){
	return mp(
	1ll*(b1[x]-b1[fa[y][0]]+MOD1)*ipw1[dep[fa[y][0]]]%MOD1,
	1ll*(b2[x]-b2[fa[y][0]]+MOD2)*ipw2[dep[fa[y][0]]]%MOD2);
}
pii gethash2(int x,int y,int lca){
	return mp(
	(1ll*(b1[x]-b1[lca]+MOD1)*ipw1[dep[lca]]%MOD1*pw1[dep[y]-dep[lca]+1]%MOD1+
	(a1[y]-1ll*a1[fa[lca][0]]*pw1[dep[y]-dep[fa[lca][0]]]%MOD1+MOD1))%MOD1,
	(1ll*(b2[x]-b2[lca]+MOD2)*ipw2[dep[lca]]%MOD2*pw2[dep[y]-dep[lca]+1]%MOD2+
	(a2[y]-1ll*a2[fa[lca][0]]*pw2[dep[y]-dep[fa[lca][0]]]%MOD2+MOD2))%MOD2);
}
int main(){
	scanf("%d%s",&n,s+1);srand(time(0));
	hsbase1=rand()%100+200;while(!ispri(hsbase1)) ++hsbase1;
	hsbase2=rand()%100+300;while(!ispri(hsbase2)) ++hsbase2;
	pw1[0]=1;for(int i=1;i<=n;i++) pw1[i]=1ll*pw1[i-1]*hsbase1%MOD1;
	pw2[0]=1;for(int i=1;i<=n;i++) pw2[i]=1ll*pw2[i-1]*hsbase2%MOD2;
	ipw1[n]=qpow(pw1[n],MOD1-2,MOD1);ipw2[n]=qpow(pw2[n],MOD2-2,MOD2);
	for(int i=n-1;~i;i--) ipw1[i]=1ll*ipw1[i+1]*hsbase1%MOD1;
	for(int i=n-1;~i;i--) ipw2[i]=1ll*ipw2[i+1]*hsbase2%MOD2;
	for(int i=1,u,v;i<n;i++){scanf("%d%d",&u,&v);adde(u,v);adde(v,u);}
	a1[1]=a2[1]=b1[1]=b2[1]=s[1];dep[1]=1;dfs1();dfs2();
	for(int i=1;i<=LOG_N;i++) for(int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
	scanf("%d",&qu);
//	printf("%d %d\n",hsbase1,hsbase2);
//	printf("%d %d\n",gethash1(2,1).fi,gethash1(2,1).se);
//	printf("%d %d\n",gethash2(3,5,2).fi,gethash2(3,5,2).se);
//	for(int i=1;i<=n;i++) printf("%d %d %d %d\n",pw1[i],pw2[i],ipw1[i],ipw2[i]);
//	for(int i=1;i<=n;i++) printf("%d %d %d %d\n",a1[i],a2[i],b1[i],b2[i]);
	while(qu--){
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
		int lca_ab=getlca(a,b),lca_cd=getlca(c,d);
		int len1=dep[a]+dep[b]-dep[lca_ab]-dep[fa[lca_ab][0]];
		int len2=dep[c]+dep[d]-dep[lca_cd]-dep[fa[lca_cd][0]];
//		printf("%d %d\n",len1,len2);
		int l=1,r=min(len1,len2),x=0;
		while(l<=r){
			int mid=l+r>>1;
			pii hs1=(mid<=dep[a]-dep[lca_ab]+1)?
			gethash1(a,get_kanc(a,mid-1)):gethash2(a,get_kanc(b,len1-mid),lca_ab);
			pii hs2=(mid<=dep[c]-dep[lca_cd]+1)?
			gethash1(c,get_kanc(c,mid-1)):gethash2(c,get_kanc(d,len2-mid),lca_cd);
			if(hs1==hs2) x=mid,l=mid+1;else r=mid-1;
		} printf("%d\n",x);
	}
	return 0;
}
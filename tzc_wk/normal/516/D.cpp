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
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
inline void debug(int x){fprintf(stderr,"ycx has aked ioi %d times\n",x);}
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
	template<typename T> void print(T x,char c){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
int n,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],val[MAXN*2+5],ec=0;
void adde(int u,int v,int w){to[++ec]=v;val[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
ll dis[MAXN+5],d[MAXN+5];
void dfs(int x,int f){
	chkmax(d[x],dis[x]);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=val[e];if(y==f) continue;
		dis[y]=dis[x]+z;dfs(y,x);
	}
} int ord[MAXN+5],fa[MAXN+5];
void getfa(int x,int f){
	fa[x]=f;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		getfa(y,x);
	}
}
bool cmp(int x,int y){return d[x]<d[y];}
int f[MAXN+5],siz[MAXN+5];
int find(int x){return (!f[x])?x:f[x]=find(f[x]);}
void merge(int x,int y){x=find(x);y=find(y);if(x^y) f[x]=y,siz[y]+=siz[x];}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v,w;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		adde(u,v,w);adde(v,u,w);
	} dfs(1,0);int rt=0;
	for(int i=1;i<=n;i++) if(dis[i]>dis[rt]) rt=i;
	dis[rt]=0;dfs(rt,0);rt=0;
	for(int i=1;i<=n;i++) if(dis[i]>dis[rt]) rt=i;
	dis[rt]=0;dfs(rt,0);for(int i=1;i<=n;i++) ord[i]=i;
	sort(ord+1,ord+n+1,cmp);getfa(ord[1],0);
//	for(int i=1;i<=n;i++) printf("%lld%c",d[i],(i==n)?'\n':' ');
//	for(int i=1;i<=n;i++) printf("%d%c",ord[i],(i==n)?'\n':' ');
//	for(int i=1;i<=n;i++) printf("%d%c",fa[i],(i==n)?'\n':' ');
	int qu;scanf("%d",&qu);
	while(qu--){
		ll l;int ans=0;scanf("%lld",&l);
		for(int i=1;i<=n;i++) f[i]=0,siz[i]=1;
		for(int i=n,j=n;i;i--){
			while(d[ord[j]]>d[ord[i]]+l) siz[find(ord[j])]--,j--;
//			printf("%d %d %d\n",i,j,siz[find(ord[i])]);
			chkmax(ans,siz[find(ord[i])]);if(fa[ord[i]]) merge(ord[i],fa[ord[i]]);
		} printf("%d\n",ans);
	}
	return 0;
}
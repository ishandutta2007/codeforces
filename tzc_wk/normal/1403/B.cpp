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
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
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
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=2e5;
const int INF=0x3f3f3f3f;
int n,a[MAXN+5],hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int siz[MAXN+5],cent,mx[MAXN+5];bool vis[MAXN+5];
void findcent(int x,int f,int tot){
	mx[x]=0;siz[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||vis[y]) continue;
		findcent(y,x,tot);siz[x]+=siz[y];
		chkmax(mx[x],siz[y]);
	} chkmax(mx[x],tot-siz[x]);
	if(mx[x]<mx[cent]) cent=x;
}
int g[MAXN+5];
void getgcd(int x,int f){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||vis[y]) continue;
		g[y]=__gcd(g[x],a[y]);getgcd(y,x);
	}
}
vector<int> pt;
void getpts(int x,int f){
	pt.pb(x);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||vis[y]) continue;
		getpts(y,x);
	}
}
int cnt[MAXN+5];ll res[MAXN+5];
void divcent(int x){
//	printf("divcent %d\n",x);
	vis[x]=1;g[x]=a[x];vector<int> fac;
	for(int i=1;i*i<=a[x];i++) if(a[x]%i==0){
		fac.pb(i);
		if(a[x]/i!=i) fac.pb(a[x]/i);
	}
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(vis[y]) continue;
		g[y]=__gcd(a[x],a[y]);getgcd(y,x);
	} cnt[a[x]]++;res[a[x]]++;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(vis[y]) continue;
		pt.clear();getpts(y,x);
		for(int z:pt) for(int f:fac) if(cnt[f])
			res[__gcd(f,g[z])]+=cnt[f];
		for(int z:pt) cnt[g[z]]++/*,printf("%d\n",z)*/;
	} for(int f:fac) cnt[f]=0;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(vis[y]) continue;
		cent=0;findcent(y,x,siz[y]);divcent(cent);
	}
}
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	mx[0]=INF;findcent(1,0,n);divcent(cent);
	for(int i=1;i<=MAXN;i++) if(res[i]) printf("%d %lld\n",i,res[i]);
	return 0;
}
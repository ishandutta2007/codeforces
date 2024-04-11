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
const int MAXN=1e5;
const int INF=0x3f3f3f3f;
int n,X,Y,k,a[MAXN+5];
int hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%Y) if(e&1) ret=1ll*ret*x%Y;
	return ret;
}
int pw[MAXN+5],ipw[MAXN+5];
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int siz[MAXN+5],cent=0,mx[MAXN+5];bool vis[MAXN+5];
void findcent(int x,int f,int tot){
	siz[x]=1;mx[x]=0;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||vis[y]) continue;
		findcent(y,x,tot);siz[x]+=siz[y];
		chkmax(mx[x],siz[y]);
	} chkmax(mx[x],tot-siz[x]);
	if(mx[x]<mx[cent]) cent=x;
}
int dep[MAXN+5],f1[MAXN+5],f2[MAXN+5];
void getdep(int x,int f){
//	printf("%d %d %d %d\n",x,dep[x],f1[x],f2[x]);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||vis[y]) continue;
		dep[y]=dep[x]+1;f1[y]=(1ll*f1[x]*k+a[y])%Y;
		f2[y]=(f2[x]+1ll*a[y]*pw[dep[y]])%Y;
		getdep(y,x);
	}
}
vector<int> pt;
int res1[MAXN+5],res2[MAXN+5];
void getpts(int x,int f){
	pt.pb(x);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||vis[y]) continue;
		getpts(y,x);
	}
}
void divcent(int x){
//	printf("divcent %d\n",x);
	vis[x]=1;f1[x]=0;f2[x]=a[x];dep[x]=0;
	map<int,int> cnt1,cnt2;
	#define insert1(x) cnt1[1ll*(X-f1[x]+Y)*ipw[dep[x]]%Y]++
	#define insert2(x) cnt2[f2[x]]++
	#define calc(x) (res1[x]+=cnt1[f2[x]],res2[x]+=cnt2[1ll*(X-f1[x]+Y)*ipw[dep[x]]%Y])
	insert1(x);insert2(x);stack<int> stk;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(vis[y]) continue;
		f1[y]=a[y];f2[y]=(1ll*a[y]*k+a[x])%Y;
		dep[y]=1;getdep(y,x);
	}
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(vis[y]) continue;
//		printf("y=%d\n",y);
		pt.clear();getpts(y,x);stk.push(y);
		for(int z:pt) calc(z);
		for(int z:pt) insert1(z),insert2(z);
	} cnt1.clear();cnt2.clear();
	while(!stk.empty()){
		int y=stk.top();stk.pop();
//		printf("y=%d\n",y);
		pt.clear();getpts(y,x);
		for(int z:pt) calc(z);
		for(int z:pt) insert1(z),insert2(z);
	} calc(x);
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(vis[y]) continue;
		cent=0;findcent(y,x,siz[y]);divcent(cent);
	}
}
int main(){
	scanf("%d%d%d%d",&n,&Y,&k,&X);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	pw[0]=ipw[0]=1;pw[1]=k;ipw[1]=qpow(k,Y-2);
	for(int i=2;i<=n;i++){
		pw[i]=1ll*pw[i-1]*pw[1]%Y;
		ipw[i]=1ll*ipw[i-1]*ipw[1]%Y;
	} mx[0]=INF;findcent(1,0,n);divcent(cent);
	for(int i=1;i<=n;i++) if(a[i]==X) res1[i]++,res2[i]++;
//	for(int i=1;i<=n;i++) printf("%d %d\n",res1[i],res2[i]);
	ll res=0;
	for(int i=1;i<=n;i++){
		int rst1=n-res1[i],rst2=n-res2[i];
		res+=2ll*rst1*res1[i];res+=1ll*rst1*res2[i];
		res+=1ll*rst2*res1[i];res+=2ll*rst2*res2[i];
	} printf("%lld\n",1ll*n*n*n-(res>>1));
	return 0;
}
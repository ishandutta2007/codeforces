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
const int MAXN=2e5;
const int INF=0x3f3f3f3f;
int n,a[MAXN+5],hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],val[MAXN*2+5],ec=0;
void adde(int u,int v,int w){to[++ec]=v;val[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
bool vis[MAXN+5];int siz[MAXN+5],mx[MAXN+5],cent=0;
int ans=0;double mn=1e25,sum[MAXN+5],sum1=0,sum2=0;
void findcent(int x,int f,int totsiz){
	mx[x]=0;siz[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f||vis[y]) continue;
		findcent(y,x,totsiz);siz[x]+=siz[y];
		chkmax(mx[x],siz[y]);
	} chkmax(mx[x],totsiz-siz[x]);
	if(mx[x]<mx[cent]) cent=x;
}
void calc(int x,int f,int rt,int dep){
	sum1+=1.0*a[x]*dep*sqrt(dep);
	sum2+=1.0*a[x]*sqrt(dep)*3/2;
	sum[rt]+=1.0*a[x]*sqrt(dep)*3/2;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=val[e];if(y==f) continue;
		calc(y,x,rt,dep+z);
	}
}
void divcent(int x){
	if(vis[x]) return;vis[x]=1;sum1=sum2=0;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=val[e];sum[y]=0;calc(y,x,y,z);
	}
	if(sum1<mn) mn=sum1,ans=x;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e],z=val[e];
		if(sum2-sum[y]*2.0<0){
			cent=0;findcent(y,x,siz[y]);divcent(cent);
			return;
		}
	}
}
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1,u,v,w;i<n;i++) scanf("%d%d%d",&u,&v,&w),adde(u,v,w),adde(v,u,w);
	mx[0]=INF;cent=0;findcent(1,0,n);divcent(cent);
	printf("%d %.15lf\n",ans,mn);
	return 0;
}
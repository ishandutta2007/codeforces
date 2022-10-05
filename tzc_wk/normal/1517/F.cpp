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
const int MAXN=300;
const int MOD=998244353;
const int INV2=MOD+1>>1;
void add(int &x,int v){((x+=v)>=MOD)&&(x-=MOD);}
int n,hd[MAXN+5],to[MAXN*2+10],nxt[MAXN*2+10],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int siz[MAXN+5],dp[MAXN+5][MAXN*2+10],tmp[MAXN*2+10];
void dfs(int x,int f,int k){
	dp[x][MAXN-1]=dp[x][MAXN+k]=INV2;siz[x]=1;
	for(int e=hd[x];e;e=nxt[e]) if(to[e]^f){
		int y=to[e];dfs(y,x,k);memset(tmp,0,sizeof(tmp));
		vector<int> has_x,has_y;
		for(int u=-n;u<=n;u++) if(dp[x][MAXN+u]) has_x.pb(u);
		for(int u=-n;u<=n;u++) if(dp[y][MAXN+u]) has_y.pb(u);
		for(int u:has_x) for(int v:has_y) add(tmp[((u+v>=0)?max(u,v-1):min(u,v-1))+MAXN],1ll*dp[x][MAXN+u]*dp[y][MAXN+v]%MOD);
		siz[x]+=siz[y];for(int u=-n;u<=n;u++) dp[x][u+MAXN]=tmp[u+MAXN];
	}
}
int f[MAXN+5];
int solve(int k){
	memset(dp,0,sizeof(dp));dfs(1,0,k);
	int ret=0;for(int i=0;i<=n;i++) add(ret,dp[1][MAXN+i]);
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	for(int i=0;i<=n;i++) f[i]=solve(i);int ans=0;
	for(int i=1;i<=n;i++) ans=(ans+1ll*(f[i]-f[i-1]+MOD)*(i-1))%MOD;
	ans=(ans-f[0]+MOD)%MOD;ans=(ans+1ll*n*(1-f[n]+MOD))%MOD;printf("%d\n",ans);
	return 0;
}
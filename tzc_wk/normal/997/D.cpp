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
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=4000;
const int MAXK=75;
const int MOD=998244353;
int k,fac[MAXK+5],ifac[MAXK+5];
void init_fac(int n){
	for(int i=(fac[0]=ifac[0]=ifac[1]=1)+1;i<=n;i++) ifac[i]=1ll*ifac[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD,ifac[i]=1ll*ifac[i-1]*ifac[i]%MOD;
}
struct tree_solver{
	int n,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0,sum[MAXK+5];
	void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
	void read(){for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);}
	int f[MAXN+5][MAXK+5],dp[MAXN+5][MAXK+5],out[MAXN+5][MAXK+5],dep[MAXN+5];
	void dfs0(int x,int fa){
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==fa) continue;
			dep[y]=dep[x]+1;dfs0(y,x);
		}
	}
	void dfs1(int x,int fa,int t){
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==fa) continue;dfs1(y,x,t);
			for(int i=0;i<t;i+=2) f[x][t]=(f[x][t]+1ll*f[x][i]*f[y][t-i-2])%MOD;
		}
	}
	void dfs2(int x,int fa,int t){
		vector<int> s(t+1);
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];
			if(y==fa) for(int i=0;i<t;i+=2) s[i]=(s[i]+out[x][t-i-2])%MOD;
			else for(int i=0;i<t;i+=2) s[i]=(s[i]+f[y][t-i-2])%MOD;
		}
		for(int e=hd[x];e;e=nxt[e]){
			int y=to[e];if(y==fa) continue;
			for(int i=0;i<t;i+=2) s[i]=(s[i]-f[y][t-i-2]+MOD)%MOD;
			for(int i=0;i<t;i+=2) out[y][t]=(out[y][t]+1ll*s[i]*out[y][i])%MOD;
			for(int i=0;i<t;i+=2) s[i]=(s[i]+f[y][t-i-2])%MOD;
			dfs2(y,x,t);
		}
	}
	void solve(){
		dfs0(1,0);
		for(int i=1;i<=n;i++) dp[i][0]=f[i][0]=out[i][0]=1;
		for(int i=2;i<=k;i+=2){
			dfs1(1,0,i);dfs2(1,0,i);
//			for(int j=1;j<=n;j++) printf("%d %d %d %d\n",j,i,f[j][i],out[j][i]);
		}
		for(int i=2;i<=k;i+=2) for(int x=1;x<=n;x++){
			for(int e=hd[x];e;e=nxt[e]){
				int y=to[e];
				if(dep[y]>dep[x]){
					for(int j=0;j<i;j+=2) dp[x][i]=(dp[x][i]+1ll*dp[x][i-j-2]*f[y][j])%MOD;
				} else {
					for(int j=0;j<i;j+=2) dp[x][i]=(dp[x][i]+1ll*dp[x][i-j-2]*out[x][j])%MOD;
				}
			} //printf("%d %d %d\n",x,i,dp[x][i]);
		}
		for(int i=0;i<=k;i+=2) for(int x=1;x<=n;x++)
			sum[i]=(sum[i]+1ll*ifac[i]*dp[x][i])%MOD;
//		for(int i=0;i<=k;i+=2) printf("%d\n",sum[i]);
	}
} t1,t2;
int main(){
	scanf("%d%d%d",&t1.n,&t2.n,&k);if(k&1) return puts("0"),0;
	t1.read();t2.read();init_fac(k);t1.solve();t2.solve();
	int ans=0;for(int i=0;i<=k;i+=2) ans=(ans+1ll*t1.sum[i]*t2.sum[k-i])%MOD;
	printf("%d\n",1ll*ans*fac[k]%MOD);
	return 0;
}
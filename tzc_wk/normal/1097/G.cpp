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
const int MAXN=1e5;
const int MAXK=200;
const int MOD=1e9+7;
int n,k,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dp[MAXN+5][MAXK+5],siz[MAXN+5],tmp[MAXK+5],ans[MAXN+5];
int s[MAXK+5][MAXK+5],fac[MAXK+5];
void prework(int k){
	fac[0]=s[0][0]=1;for(int i=1;i<=k;i++) fac[i]=1ll*fac[i-1]*i%MOD;
	for(int i=1;i<=k;i++) for(int j=1;j<=i;j++) s[i][j]=(s[i-1][j-1]+1ll*j*s[i-1][j])%MOD;
}
void dfs(int x,int f){
	siz[x]=1;dp[x][0]=2;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dfs(y,x);memset(tmp,0,sizeof(tmp));
		for(int i=0;i<=min(siz[y],k);i++) for(int j=0;j<=min(k-i,siz[x]);j++)
			tmp[i+j]=(tmp[i+j]+1ll*dp[y][i]*dp[x][j])%MOD;
		siz[x]+=siz[y];for(int i=0;i<=min(siz[x],k);i++) dp[x][i]=tmp[i];
		for(int i=0;i<=min(siz[y],k);i++) ans[i]=(ans[i]-dp[y][i]+MOD)%MOD;
	}
	for(int i=0;i<=min(siz[x],k);i++) ans[i]=(ans[i]+dp[x][i])%MOD;
	for(int i=min(siz[x],k);i;i--) dp[x][i]=(dp[x][i]+dp[x][i-1])%MOD;
	dp[x][1]--;if(dp[x][1]<0) dp[x][1]+=MOD;
}
int main(){
	scanf("%d%d",&n,&k);prework(k);int sum=0;
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);dfs(1,0);
	for(int i=0;i<=k;i++) sum=(sum+1ll*fac[i]*s[k][i]%MOD*ans[i])%MOD;
	printf("%d\n",sum);
	return 0;
}
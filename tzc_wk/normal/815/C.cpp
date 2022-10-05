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
const int MAXN=5000;
const ll INF=0x3f3f3f3f3f3f3f3fll;
int n,b,c[MAXN+5],d[MAXN+5],hd[MAXN+5],to[MAXN+5],nxt[MAXN+5],ec=0;
ll dp[MAXN+5][MAXN+5][2],tmp[MAXN+5][2];int siz[MAXN+5];
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
void dfs(int x){
	dp[x][0][0]=0;dp[x][1][0]=c[x];dp[x][1][1]=c[x]-d[x];siz[x]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];dfs(y);
		for(int i=0;i<=siz[x]+siz[y];i++) tmp[i][0]=tmp[i][1]=INF;
		for(int i=0;i<=siz[x];i++) for(int j=0;j<=siz[y];j++){
			chkmin(tmp[i+j][0],dp[x][i][0]+dp[y][j][0]);
			chkmin(tmp[i+j][1],dp[x][i][1]+min(dp[y][j][0],dp[y][j][1]));
		}
		for(int i=0;i<=siz[x]+siz[y];i++){
			dp[x][i][0]=tmp[i][0];dp[x][i][1]=tmp[i][1];
		} siz[x]+=siz[y];
	}
//	for(int i=0;i<=siz[x];i++) printf("%d %d %lld %lld\n",x,i,dp[x][i][0],dp[x][i][1]);
}
int main(){
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&d[i]);
		if(i^1){int fa;scanf("%d",&fa);adde(fa,i);}
	}
	memset(dp,63,sizeof(dp));dfs(1);int ans=0;
	for(int i=0;i<=n;i++) if(min(dp[1][i][0],dp[1][i][1])<=b) chkmax(ans,i);
	printf("%d\n",ans);
	return 0;
}
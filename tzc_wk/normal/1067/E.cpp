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
const int MAXN=5e5;
const int MOD=998244353;
int n,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=0;
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dp[MAXN+5][2],way[MAXN+5][2];
void dfs(int x,int f){
	way[x][0]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;dfs(y,x);
		static int tmp_dp[2]={0},tmp_way[2]={0};
		memset(tmp_dp,0,sizeof(tmp_dp));
		memset(tmp_way,0,sizeof(tmp_way));
		tmp_way[0]=(1ll*way[x][0]*(way[y][0]+way[y][1]))%MOD;
		tmp_dp[0]=(1ll*dp[x][0]*(way[y][0]+way[y][1])+1ll*(dp[y][0]+dp[y][1])*way[x][0])%MOD;
		tmp_way[1]=(1ll*way[x][1]*(way[y][0]+way[y][1])*2)%MOD;
		tmp_dp[1]=2ll*(1ll*dp[x][1]*(way[y][0]+way[y][1])+1ll*(dp[y][0]+dp[y][1])*way[x][1])%MOD;
		tmp_way[0]=(tmp_way[0]+1ll*way[x][0]*way[y][1])%MOD;
		tmp_dp[0]=(tmp_dp[0]+1ll*dp[x][0]*way[y][1]+1ll*dp[y][1]*way[x][0])%MOD;
		tmp_way[1]=(tmp_way[1]+1ll*way[x][0]*way[y][0])%MOD;
		tmp_dp[1]=(tmp_dp[1]+1ll*dp[x][0]*way[y][0]+1ll*dp[y][0]*way[x][0]+1ll*way[x][0]*way[y][0])%MOD;
		for(int i=0;i<2;i++) dp[x][i]=tmp_dp[i],way[x][i]=tmp_way[i];
	}
//	printf("%d %d %d %d %d\n",x,dp[x][0],dp[x][1],way[x][0],way[x][1]);
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	dfs(1,0);printf("%d\n",2ll*(dp[1][0]+dp[1][1])%MOD);
	return 0;
}
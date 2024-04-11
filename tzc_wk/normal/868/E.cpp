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
const int MAXN=50;
const int INF=0x3f3f3f3f;
int n,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],cst[MAXN*2+5],ec=1;
int rt,siz[MAXN+5],deg[MAXN+5];
void adde(int u,int v,int w){to[++ec]=v;cst[ec]=w;nxt[ec]=hd[u];hd[u]=ec;}
void dfs0(int x,int f){
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;
		dfs0(y,x);siz[x]+=siz[y];
	}
}
int dp[MAXN*2+5][MAXN+5][MAXN+5];
int dfs(int ed,int x,int y){
	/*printf("%d %d %d\n",ed,x,y);*/if(!x&&!y) return 0;
	if(~dp[ed][x][y]) return dp[ed][x][y];
	if(deg[to[ed]]==1){
		if(!y) return 0;
		return dp[ed][x][y]=dfs(ed^1,y,0)+cst[ed];
	} int tmp[MAXN+5]={0};memset(tmp,0,sizeof(tmp));tmp[0]=INF;
	for(int e=hd[to[ed]];e;e=nxt[e]) if(e^ed^1){
		for(int j=x;j;j--) for(int k=j;k;k--)
			chkmax(tmp[j],min(tmp[j-k],dfs(e,k,x+y-k)+cst[e]));
	} return dp[ed][x][y]=tmp[x];
}
int main(){
	scanf("%d",&n);
	for(int i=1,u,v,w;i<n;i++){
		scanf("%d%d%d",&u,&v,&w);
		adde(u,v,w);adde(v,u,w);
		++deg[u];++deg[v];
	} int T_T;scanf("%d%d",&rt,&T_T);
	for(int qwq=1,x;qwq<=T_T;qwq++) scanf("%d",&x),siz[x]++;
	dfs0(rt,0);memset(dp,-1,sizeof(dp));
	int ans=INF;for(int e=hd[rt];e;e=nxt[e])
		chkmin(ans,dfs(e,siz[to[e]],T_T-siz[to[e]])+cst[e]);
	printf("%d\n",ans);
	return 0;
}
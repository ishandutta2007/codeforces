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
const int MOD=998244353;
int n,hd[MAXN+5],to[MAXN*2+5],nxt[MAXN*2+5],ec=1,bot[MAXN+5];
void adde(int u,int v){to[++ec]=v;nxt[ec]=hd[u];hd[u]=ec;}
int dp[MAXN+5][5],mul[MAXN+5];
void dfs(int x,int f){
	dp[x][1]=dp[x][3]=1;
	for(int e=hd[x];e;e=nxt[e]){
		int y=to[e];if(y==f) continue;bot[y]=e>>1;dfs(y,x);
		if(bot[y]<bot[x]) dp[x][3]=1ll*dp[x][3]*(dp[y][0]+dp[y][3])%MOD;
		else dp[x][3]=1ll*dp[x][3]*(dp[y][1]+dp[y][2])%MOD;
		dp[x][1]=1ll*dp[x][1]*(dp[y][0]+dp[y][3])%MOD;
	} vector<int> vec,pre_mul,suf_mul;
	for(int e=hd[x];e;e=nxt[e]){int y=to[e];if(y==f) continue;vec.pb(y);}
	reverse(vec.begin(),vec.end());pre_mul.resize(vec.size());suf_mul.resize(vec.size());
	for(int i=0;i<vec.size();i++){
		int y=vec[i];
		pre_mul[i]=1ll*((!i)?1:pre_mul[i-1])*(dp[y][0]+dp[y][3])%MOD;
	} for(int i=(int)(vec.size())-1;~i;i--){
		int y=vec[i];
		suf_mul[i]=1ll*((i+1==vec.size())?1:suf_mul[i+1])*(dp[y][1]+dp[y][2])%MOD;
	} for(int i=0;i<vec.size();i++){
		int y=vec[i];
		int mul=dp[y][4];if(i) mul=1ll*mul*pre_mul[i-1]%MOD;
		if(i+1<vec.size()) mul=1ll*mul*suf_mul[i+1]%MOD;
		if(bot[y]<bot[x]) dp[x][0]=(dp[x][0]+mul)%MOD;
		else dp[x][1]=(dp[x][1]+mul)%MOD;
	} dp[x][4]=dp[x][1];dp[x][2]=dp[x][0];
}
int main(){
	scanf("%d",&n);bot[1]=n;
	for(int i=1,u,v;i<n;i++) scanf("%d%d",&u,&v),adde(u,v),adde(v,u);
	dfs(1,0);printf("%d\n",(dp[1][1]+dp[1][2])%MOD);
	return 0;
}
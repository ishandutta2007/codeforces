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
const int MAXN=6;
const int MAXP=15625;
int n,m,a[MAXN+3],b[MAXN+3],c[MAXN+3][MAXN+3];
ll dp[MAXN+3][MAXP+5];
int rid[MAXP+5],id[1<<18];
int idnum=0;
void dfs(int x,int cur){
	if(x==n+1){rid[++idnum]=cur;id[cur]=idnum;return;}
	for(int i=0;i<=a[x];i++) dfs(x+1,cur+(i<<(3*(x-1))));
}
void dfs2(int x,int t,int msk,int lft,ll val){
	if(!lft||x==n+1){chkmin(dp[t][id[msk]],val);return;}
	for(int i=0;i<=min(a[x]-(msk>>(3*(x-1))&7),lft);i++){
		dfs2(x+1,t,msk+(i<<(3*(x-1))),lft-i,val+(i>0)*c[x][t]);
	}
}
int main(){
	scanf("%d%d",&n,&m);int sa=0,sb=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),sa+=a[i];
	for(int i=1;i<=m;i++) scanf("%d",&b[i]),sb+=b[i];
	if(sa>sb) return puts("-1"),0;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&c[i][j]);
	dfs(1,0);memset(dp,63,sizeof(dp));dp[0][id[0]]=0;
	for(int i=0;i<m;i++){
		vector<int> pos;
		for(int l=1;l<=idnum;l++){
			if(dp[i][l]>=0x3f3f3f3f3f3f3f3fll) continue;
			dfs2(1,i+1,rid[l],b[i+1],dp[i][l]);
		}
	} int lst=0;for(int i=1;i<=n;i++) lst|=(a[i]<<(3*(i-1)));
	if(dp[m][id[lst]]<0x3f3f3f3f3f3f3f3fll) printf("%lld\n",dp[m][id[lst]]);
	else puts("-1");
	return 0;
}
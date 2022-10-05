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
template<typename T1,typename T2> bool chkmin(T1 &x,T2 y){if(x>y) return x=y,1;return 0;}
template<typename T1,typename T2> bool chkmax(T1 &x,T2 y){if(x<y) return x=y,1;return 0;}
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
const int MAXN=500;
const int MAXK=10;
const int INF=0x3f3f3f3f;
int n,m,k,dp[MAXN+5][MAXN+5][MAXK+2];
int a[MAXN+5][MAXN+5],b[MAXN+5][MAXN+5];
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) for(int j=1;j<m;j++) scanf("%d",&a[i][j]);
	for(int i=1;i<n;i++) for(int j=1;j<=m;j++) scanf("%d",&b[i][j]);
	if(k&1){
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
			printf("%d%c",-1,(j==m)?'\n':' ');
		return 0;
	} k>>=1;
	memset(dp,63,sizeof(dp));
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dp[i][j][0]=0;
	for(int t=1;t<=k;t++) for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		if(i!=1) chkmin(dp[i][j][t],dp[i-1][j][t-1]+b[i-1][j]);
		if(i!=n) chkmin(dp[i][j][t],dp[i+1][j][t-1]+b[i][j]);
		if(j!=1) chkmin(dp[i][j][t],dp[i][j-1][t-1]+a[i][j-1]);
		if(j!=m) chkmin(dp[i][j][t],dp[i][j+1][t-1]+a[i][j]);
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) printf("%d%c",dp[i][j][k]<<1,(j==m)?'\n':' ');
	return 0;
}
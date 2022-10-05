//#pragma comment(linker,"/stack:200000000")
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
int n,m;char L[MAXN+5],R[MAXN+5],U[MAXN+5],D[MAXN+5];
int dp[MAXN+5][2],ans=0x3f3f3f3f;
int main(){
	scanf("%d%d%*d%s%s%s%s",&n,&m,L+1,R+1,U+1,D+1);
	memset(dp,63,sizeof(dp));dp[0][0]=dp[0][1]=0;
	for(int i=1;i<=m;i++) dp[0][0]+=(U[i]=='B'),dp[0][1]+=(U[i]=='R');
	for(int i=1;i<=n;i++){
		dp[i][0]=min(dp[i-1][0],dp[i-1][1]+m)+(L[i]=='B')+(R[i]=='B');
		dp[i][1]=min(dp[i-1][1],dp[i-1][0]+m)+(L[i]=='R')+(R[i]=='R');
	}
	for(int i=1;i<=m;i++) dp[n][0]+=(D[i]=='B'),dp[n][1]+=(D[i]=='R');
	chkmin(ans,dp[n][0]);chkmin(ans,dp[n][1]);
	memset(dp,63,sizeof(dp));dp[0][0]=dp[0][1]=0;
	for(int i=1;i<=n;i++) dp[0][0]+=(L[i]=='B'),dp[0][1]+=(L[i]=='R');
	for(int i=1;i<=m;i++){
		dp[i][0]=min(dp[i-1][0],dp[i-1][1]+n)+(U[i]=='B')+(D[i]=='B');
		dp[i][1]=min(dp[i-1][1],dp[i-1][0]+n)+(U[i]=='R')+(D[i]=='R');
	}
	for(int i=1;i<=n;i++) dp[m][0]+=(R[i]=='B'),dp[m][1]+=(R[i]=='R');
	chkmin(ans,dp[m][0]);chkmin(ans,dp[m][1]);
	printf("%d\n",ans);
	return 0;
}
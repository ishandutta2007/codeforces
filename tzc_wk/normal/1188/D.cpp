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
const int MAXB=60;
const int MAXN=1e5;
int n,ord[MAXN+5];ll a[MAXN+5],b[MAXN+5];
int dp[MAXB+5][MAXN+5],sum[MAXN+5][2];
int main(){
	scanf("%d",&n);for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);for(int i=1;i<=n;i++) a[i]=a[n]-a[i];
	memset(dp,63,sizeof(dp));dp[0][0]=0;
	for(int i=0;i<=MAXB;i++){
		memset(sum,0,sizeof(sum));
		for(int j=1;j<=n;j++) b[j]=a[j]&((1ll<<i)-1);
		for(int j=1;j<=n;j++) ord[j]=j;
		sort(ord+1,ord+n+1,[](int x,int y){return b[x]<b[y];});
		for(int j=1;j<=n;j++){
			sum[j][0]=sum[j-1][0];sum[j][1]=sum[j-1][1];
			sum[j][a[ord[j]]>>i&1]++;
		}
		for(int j=0;j<=n;j++){
			int cst=sum[n-j][1]+sum[n][0]-sum[n-j][0],carry=sum[n][1]-sum[n-j][1];
			chkmin(dp[i+1][carry],dp[i][j]+cst);
			cst=sum[n-j][0]+sum[n][1]-sum[n-j][1],carry=n-sum[n-j][0];
			chkmin(dp[i+1][carry],dp[i][j]+cst);
		}
	} printf("%d\n",dp[MAXB+1][0]);
	return 0;
}
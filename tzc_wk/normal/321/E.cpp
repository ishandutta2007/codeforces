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
using namespace fastio;
const int MAXN=4000;
const int MAXK=800;
int n,k,a[MAXN+5][MAXN+5],s[MAXN+5][MAXN+5];
int dp[MAXN+5][MAXK+5],from[MAXN+5][MAXK+5];
int sum(int l1,int r1,int l2,int r2){
	return s[r1][r2]-s[l1-1][r2]-s[r1][l2-1]+s[l1-1][l2-1];
}
int main(){
	read(n);read(k);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++){
		read(a[i][j]);s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+a[i][j];
	} memset(dp,63,sizeof(dp));dp[0][0]=0;
	for(int i=1;i<=k;i++) for(int j=n;j;j--)
		for(int l=from[j][i-1];l<=((j==n)?n:from[j+1][i]);l++)
			if(l<j&&dp[j][i]>dp[l][i-1]+sum(l+1,j,l+1,j))
				dp[j][i]=dp[l][i-1]+sum(l+1,j,l+1,j),from[j][i]=l;
	printf("%d\n",dp[n][k]>>1);
	return 0;
}
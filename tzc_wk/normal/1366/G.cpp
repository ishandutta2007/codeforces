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
const int MAXN=1e4;
int n,m,nxt[MAXN+5];
short dp[MAXN+5][MAXN+5];
char s[MAXN+5],t[MAXN+5];
int main(){
	scanf("%s%s",s+1,t+1);n=strlen(s+1);m=strlen(t+1);
	for(int i=1;i<=n;i++){
		int cur=0;
		for(int j=i;j<=n;j++){
			cur+=(1-2*(!!(s[j]^'.')));
			if(!cur){nxt[i]=j;break;}
		}
	} memset(dp,63,sizeof(dp));dp[0][0]=0;
	for(int i=0;i<n;i++) for(int j=0;j<=m;j++){
		chkmin(dp[i+1][j],dp[i][j]+1);
//		printf("%d %d %d\n",i,j,dp[i][j]);
		if(j<=m&&s[i+1]==t[j+1]) chkmin(dp[i+1][j+1],dp[i][j]);
		if(s[i+1]!='.'&&nxt[i+1]) chkmin(dp[nxt[i+1]][j],dp[i][j]); 
	} printf("%d\n",dp[n][m]);
	return 0;
}
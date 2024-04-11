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
const int MAXN=5e3; 
int n,T,t[MAXN+5];
double dp[MAXN+5][MAXN+5],p[MAXN+5],ret=0;
int main(){
	scanf("%d%d",&n,&T);
	for(int i=1,x;i<=n;i++) scanf("%d%d",&x,&t[i]),p[i]=x/100.0;
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		double sum=0,pw=pow(1-p[i],t[i]);
		for(int j=1;j<=T;j++){
			sum*=(1-p[i]);sum+=dp[i-1][j-1];
			if(j-t[i]-1>=0) sum-=dp[i-1][j-t[i]-1]*pw;
			dp[i][j]=sum*p[i];
			if(j-t[i]>=0) dp[i][j]+=dp[i-1][j-t[i]]*pw;
			ret+=dp[i][j];
//			printf("%d %d %.10lf\n",i,j,dp[i][j]);
		}
	} printf("%.10lf\n",ret);
	return 0;
}
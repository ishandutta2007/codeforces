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
	template<typename T> void print(T x,char c){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=128;
const int MOD=1e9+7;
int w[9];
struct mat{
	int n,m,a[MAXN+5][MAXN+5];
	mat(){memset(a,0,sizeof(a));}
	mat operator *(const mat &rhs){
		mat res;res.n=n;res.m=rhs.m;
		for(int i=0;i<res.n;i++) for(int j=0;j<res.m;j++) for(int k=0;k<m;k++)
			res.a[i][j]=(res.a[i][j]+1ll*a[i][k]*rhs.a[k][j])%MOD;
		return res;
	}
} trs[9],cur;
int dp[9][2];
int main(){
	for(int i=1;i<=7;i++) scanf("%d",&w[i]);
	for(int i=1;i<=7;i++){
		for(int x=0;x<(1<<i);x++) for(int y=0;y<(1<<i);y++){
			memset(dp,0,sizeof(dp));dp[0][1]=1;
			for(int j=1;j<=i;j++){
				dp[j][0]=(dp[j-1][0]+dp[j-1][1])%MOD;
				dp[j][1]=dp[j-1][0];
				if((~x>>(j-1)&1)||(~y>>(j-1)&1)) (dp[j][1]+=dp[j-1][1])%=MOD;
			} trs[i].a[x][y]=dp[i][1];
		} trs[i].n=trs[i].m=1<<i;
	} cur.n=1;cur.m=1;cur.a[0][0]=1;
	for(int i=1;i<=7;i++){
		cur.m<<=1;
		for(int j=0;j<(1<<i-1);j++) swap(cur.a[0][j],cur.a[0][j+(1<<i-1)]);
		mat pw;pw.n=pw.m=1<<i;
		for(int j=0;j<(1<<i);j++) pw.a[j][j]=1;
		for(int e=w[i];e;e>>=1,trs[i]=trs[i]*trs[i])
			if(e&1) pw=pw*trs[i];
		cur=cur*pw;
	} printf("%d\n",cur.a[0][127]);
	return 0;
}
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
const int MAXN=50;
const int MOD=1e9+7;
int n,m,f[MAXN+5][MAXN+5],sf[MAXN+5][MAXN+5],g[MAXN+5][MAXN+5],sg[MAXN+5][MAXN+5];
int inv[MAXN+5];
int main(){
	scanf("%d%d",&n,&m);f[0][1]=sf[0][1]=1;
	for(int i=(inv[0]=inv[1]=1)+1;i<=MAXN;i++) inv[i]=1ll*inv[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1;j++) for(int k=0;k<=i-1;k++)
			sg[i][j]=(sg[i][j]+1ll*sf[k][j]*sf[i-1-k][j])%MOD;
		for(int j=1;j<=n+1;j++) g[i][j]=(sg[i][j]-sg[i][j+1]+MOD)%MOD;
//		for(int j=1;j<=n+1;j++) printf("g %d %d %d\n",i,j,g[i][j]);
		for(int j=1;j<=n+1;j++){
			for(int k=n+1;k;k--) for(int l=n+1;l;l--){
				int mul=1;
				for(int t=1;t*i<=k&&t*j<=l;t++){
					mul=1ll*mul*(g[i][j]+t-1)%MOD*inv[t]%MOD;
					f[k][l]=(f[k][l]+1ll*f[k-t*i][l-t*j]*mul)%MOD;
				}
			}
		}
		for(int j=n+1;j;j--) sf[i][j]=(sf[i][j+1]+f[i][j])%MOD;
	} printf("%d\n",f[n][m]);
	return 0;
}
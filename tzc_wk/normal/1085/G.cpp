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
const int MAXN=2000;
const int MOD=998244353;
int n,a[MAXN+5][MAXN+5],d[MAXN+5],dp[MAXN+5][MAXN+5];
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
struct fenwick_tree{
	int t[MAXN+5];
	void clear(){memset(t,0,sizeof(t));}
	void add(int x,int v){for(int i=x;i<=n;i+=(i&(-i))) t[i]+=v;}
	int query(int x){int ret=0;for(int i=x;i;i&=(i-1)) ret+=t[i];return ret;}
} t0,t1;
int vis1[MAXN+5],vis2[MAXN+5],pw[MAXN+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	d[0]=1;for(int i=2;i<=n;i++) d[i]=1ll*(i-1)*(d[i-1]+d[i-2])%MOD;
	for(int i=(pw[0]=1);i<=n;i++) pw[i]=1ll*pw[i-1]*d[n]%MOD;
	for(int i=0;i<=n;i++) dp[i][0]=d[i];
	for(int i=0;i<=n;i++) for(int j=1;j<=n;j++){
		if(!i&&!j) continue;
		dp[i][j]=1ll*j*dp[i][j-1]%MOD;
		if(i) dp[i][j]=(dp[i][j]+1ll*i*dp[i-1][j])%MOD;
	} int res=0;
	for(int i=1;i<=n;i++){
		t0.clear();t1.clear();int c00=n,c01=0;
		memset(vis1,0,sizeof(vis1));memset(vis2,0,sizeof(vis2));
		for(int j=1;j<=n;j++) t0.add(j,1);
		for(int j=1;j<=n;j++){
			if(i==1){
				res=(res+1ll*t0.query(a[i][j]-1)*dp[0][n-j]%MOD*pw[n-i])%MOD;
				t0.add(a[i][j],-1);
			} else {
				if(!vis2[a[i-1][j]]){
					t0.add(a[i-1][j],-1);
					t1.add(a[i-1][j],1);
					c00--;
				} else c01--;vis1[a[i-1][j]]=1;
				int a0=t0.query(a[i][j]-1),a1=t1.query(a[i][j]-1);
				if(!vis2[a[i-1][j]]&&a[i-1][j]<a[i][j]) a1--;
//				printf("%d %d %d %d %d %d\n",i,j,a0,a1,c00,c01);
				res=(res+(1ll*a0*dp[c00-1][c01+1]+1ll*a1*dp[c00][c01])%MOD*pw[n-i])%MOD;
				if(!vis1[a[i][j]]) c00--,c01++,t0.add(a[i][j],-1);
				else t1.add(a[i][j],-1);vis2[a[i][j]]=1;
			}
		}
	} printf("%d\n",res);
	return 0;
}
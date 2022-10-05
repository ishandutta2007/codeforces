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
const int MAXN=3e3;
const int MOD=998244353;
int n,c,a[MAXN+5];
int qpow(int x,int e=MOD-2){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret; 
}
namespace sub1{//subtask solving c>log2(n)
	int f[MAXN+5][MAXN+5],sum[MAXN+5][MAXN+5];ll dp[MAXN+5][MAXN+5];
	int pw2_1[MAXN+5],inv2_1[MAXN+5],cnt[MAXN+5];
	void solve(){
		for(int i=1;i<=n;i++) pw2_1[i]=(2*pw2_1[i-1]+1)%MOD;inv2_1[0]=1;
		for(int i=1;i<=n;i++) inv2_1[i]=qpow(pw2_1[i]);
		for(int l=1;l<=n;l++){
			int mul=1,col=1;memset(cnt,0,sizeof(cnt));
			cnt[a[l]]++;
			for(int r=l+1;r<=n;r++){
				if(a[r]==a[l]) mul=2ll*mul%MOD;
				else{
					mul=1ll*mul*inv2_1[cnt[a[r]]]%MOD;
					cnt[a[r]]++;if(cnt[a[r]]==1) col++;
					mul=1ll*mul*pw2_1[cnt[a[r]]]%MOD;
				}
				if(col==c&&(a[l]^a[r])) f[l][r]=1ll*mul*inv2_1[cnt[a[r]]]%MOD;
			}
		}
		for(int i=n+1;i;i--) dp[i][0]=pw2_1[n-i]+1;
		for(int i=n+1;i;i--) sum[i][0]=(sum[i+1][0]+dp[i][0])%MOD;
		for(int j=1;j<=n/c;j++){
			int cnt=0;
			for(int i=n;i;i--) for(int k=i+1;k<=n;k++,cnt++){
				dp[i][j]+=1ll*f[i][k]*sum[k+1][j-1];
				if(cnt>>3) dp[i][j]%=MOD,cnt=0;
			}
			for(int i=n;i;i--) sum[i][j]=(sum[i+1][j]+dp[i][j]%MOD)%MOD; 
		}
		for(int i=0;i<=n;i++){
			if(!i) printf("%d ",(sum[1][i]-sum[1][i+1]+MOD-1)%MOD);
			else printf("%d ",(sum[1][i]-sum[1][i+1]+MOD)%MOD);
		}
	}
}
namespace sub2{//subtask solving c<=log2(n)
	const int MAXP=1<<11;
	int dp[2][MAXN+5][MAXP+5];
	void solve(){
		int pre=0,cur=1;dp[0][0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n/c;j++)
				for(int k=0;k<(1<<c)-1;k++) dp[cur][j][k]=0;
			for(int j=0;j<=n/c;j++){
				for(int k=0;k<(1<<c)-1;k++){
					dp[cur][j][k]=(dp[cur][j][k]+dp[pre][j][k])%MOD;
					if((k|(1<<a[i]-1))==(1<<c)-1) dp[cur][j+1][0]=(dp[cur][j+1][0]+dp[pre][j][k])%MOD;
					else dp[cur][j][k|(1<<a[i]-1)]=(dp[cur][j][k|(1<<a[i]-1)]+dp[pre][j][k])%MOD;
				}
			} pre^=cur^=pre^=cur;
		}
		for(int j=0;j<=n;j++){
			int ret=0;
			for(int k=0;k<(1<<c)-1;k++) ret=(ret+dp[pre][j][k])%MOD;
			if(!j) ret=(ret-1+MOD)%MOD;printf("%d ",ret);
		}
	}
}
namespace sub3{//subtask solving c=1
	int fac[MAXN+5],ifac[MAXN+5];
	void init_fac(int n){
		fac[0]=ifac[0]=ifac[1]=1;
		for(int i=2;i<=n;i++) ifac[i]=1ll*ifac[MOD%i]*(MOD-MOD/i)%MOD;
		for(int i=1;i<=n;i++) fac[i]=1ll*fac[i-1]*i%MOD,ifac[i]=1ll*ifac[i-1]*ifac[i]%MOD;
	}
	int binom(int x,int y){return 1ll*fac[x]*ifac[y]%MOD*ifac[x-y]%MOD;}
	void solve(){
		init_fac(n);printf("0 ");
		for(int i=1;i<=n;i++) printf("%d ",binom(n,i));
	}
}
int main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(c>11) sub1::solve();
	else if(c>1) sub2::solve();
	else sub3::solve();
	return 0;
}
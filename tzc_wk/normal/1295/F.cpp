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
const int MAXN=50;
const int MOD=998244353;
int n,a[MAXN+5],b[MAXN+5],key[MAXN*2+5],cnt=0,uni[MAXN*2+5],num=0;
int dp[MAXN+5],inv[MAXN+5];
int qpow(int x,int e){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int main(){
	scanf("%d",&n);int mul=1;
	for(int i=(inv[0]=inv[1]=1)+1;i<=n;i++) inv[i]=1ll*inv[MOD%i]*(MOD-MOD/i)%MOD;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&a[i],&b[i]);
		mul=1ll*mul*qpow(b[i]-a[i]+1,MOD-2)%MOD;
		key[++cnt]=a[i];key[++cnt]=++b[i];
	} sort(key+1,key+cnt+1);key[0]=-1;
	for(int i=1;i<=cnt;i++) if(key[i]^key[i-1]) uni[++num]=key[i];
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(uni+1,uni+num+1,a[i])-uni;
		b[i]=lower_bound(uni+1,uni+num+1,b[i])-uni;
	} dp[0]=1;
	for(int i=num-1;i;i--){
		int len=uni[i+1]-uni[i];
		for(int j=n;j;j--) if(a[j]<=i&&i<b[j]){
			for(int k=j-1,cur=len,cnt=1;~k;k--){
				dp[j]=(dp[j]+1ll*dp[k]*cur)%MOD;
				cnt++;cur=1ll*cur*(len+cnt-1)%MOD*inv[cnt]%MOD;
				if(i<a[k]||i>=b[k]) break;
			}
		}
//		for(int j=1;j<=n;j++) printf("%d%c",dp[j]," \n"[j==n]);
	} printf("%d\n",1ll*dp[n]*mul%MOD);
	return 0;
}
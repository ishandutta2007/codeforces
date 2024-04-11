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
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int pr=3;
const int MAXN=5e4;
const int MAXP=1<<17;
const int MOD=998244353;
const int ipr=(MOD+1)/3;
int qpow(int x,int e=MOD-2){
	int ret=1;
	for(;e;e>>=1,x=1ll*x*x%MOD) if(e&1) ret=1ll*ret*x%MOD;
	return ret;
}
int n,rev[MAXP+5];
int g[MAXN+5],G[MAXN+5][3],dp[MAXN+5][3];
void NTT(vector<int> &a,int len,int type){
	int lg=31-__builtin_clz(len);
	for(int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(lg-1));
	for(int i=0;i<len;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
	for(int i=2;i<=len;i<<=1){
		int W=qpow((type<0)?ipr:pr,(MOD-1)/i);
		for(int j=0;j<len;j+=i){
			int w=1;
			for(int k=0;k<(i>>1);k++,w=1ll*w*W%MOD){
				int X=a[j+k],Y=1ll*w*a[(i>>1)+j+k]%MOD;
				a[j+k]=(X+Y)%MOD;a[(i>>1)+j+k]=(X-Y+MOD)%MOD;
			}
		}
	}
	if(type==-1){
		int ivn=qpow(len);
		for(int i=0;i<len;i++) a[i]=1ll*a[i]*ivn%MOD;
	}
}
vector<int> conv(vector<int> a,vector<int> b){
	int len=1;while(len<a.size()+b.size()) len<<=1;
	a.resize(len,0);b.resize(len,0);NTT(a,len,1);NTT(b,len,1);
	for(int i=0;i<len;i++) a[i]=1ll*a[i]*b[i]%MOD;
	NTT(a,len,-1);return a;
}
void cdq_FFT(int l,int r){
	if(l==r){
		dp[l][0]=(dp[l][0]+G[l][0])%MOD;
		dp[l][1]=(dp[l][1]+G[l][1])%MOD;
		dp[l][2]=(dp[l][2]+G[l][2])%MOD;
		return;
	} int mid=l+r>>1;cdq_FFT(l,mid);
	vector<int> a,b,c;
	for(int i=l;i<=mid;i++) a.pb(dp[i][0]);
	for(int i=0;i<=r-l+1;i++) b.pb(G[i][0]);c=conv(a,b);
	for(int i=mid+1;i<=r;i++) dp[i][0]=(dp[i][0]+c[i-l])%MOD;
	a.clear();b.clear();
	for(int i=l;i<=mid;i++) a.pb(dp[i][1]);
	for(int i=0;i<=r-l+1;i++) b.pb(G[i][1]);c=conv(a,b);
	for(int i=mid+1;i<=r;i++) dp[i][0]=(dp[i][0]+c[i-l])%MOD;
	for(int i=mid+1;i<=r;i++) dp[i][2]=(dp[i][2]+c[i-l])%MOD;
	a.clear();b.clear();
	for(int i=l;i<=mid;i++) a.pb(dp[i][0]);
	for(int i=0;i<=r-l+1;i++) b.pb(G[i][1]);c=conv(a,b);
	for(int i=mid+1;i<=r;i++) dp[i][1]=(dp[i][1]+c[i-l])%MOD;
	a.clear();b.clear();
	for(int i=l;i<=mid;i++) a.pb(dp[i][1]);
	for(int i=0;i<=r-l+1;i++) b.pb(G[i][2]);c=conv(a,b);
	for(int i=mid+1;i<=r;i++) dp[i][1]=(dp[i][1]+c[i-l])%MOD;
	a.clear();b.clear();
	for(int i=l;i<=mid;i++) a.pb(dp[i][2]);
	for(int i=0;i<=r-l+1;i++) b.pb(G[i][2]);c=conv(a,b);
	for(int i=mid+1;i<=r;i++) dp[i][2]=(dp[i][2]+c[i-l])%MOD;
	a.clear();b.clear();
	cdq_FFT(mid+1,r);
}
int main(){
	scanf("%d",&n);g[0]=g[2]=1;
	for(int i=4;i<=n;i+=2) g[i]=(g[i-2]+g[i-4])%MOD;
	for(int i=1;i<=n;i++){
		G[i][0]=1ll*g[i-1]*(i-1)%MOD*(i-1)%MOD;
		G[i][1]=1ll*g[i-2]*(i-1)%MOD*(i-1)%MOD;
		G[i][2]=1ll*g[i-3]*(i-1)%MOD*(i-1)%MOD;
	} cdq_FFT(1,n);int ans=1ll*n*(G[n][0]+G[n][2])%MOD;
	for(int i=2;i<=n-2;i++){
		ans=(ans+1ll*(1ll*G[i][0]*dp[n-i][0]+2ll*G[i][1]*dp[n-i][1]+
		1ll*G[i][2]*dp[n-i][2])%MOD*i%MOD)%MOD;
	} printf("%d\n",ans);
	return 0;
}
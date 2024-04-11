//Coded by tzc_wk
/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
const int MOD=998244353;
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),k=read(),l=read();
int dp[4005][2005],f[4005];
signed main(){
	f[0]=1;
	fz(i,1,n<<1)	f[i]=f[i-1]*i%MOD;
	dp[0][0]=1;
	for(int i=1;i<=(n*2);i++){
		for(int j=0;j<=min(n,i);j++){
			if(j)	dp[i][j]=dp[i-1][j-1];
			dp[i][j]=(dp[i][j]+dp[i-1][j+1]*(j+1)%MOD)%MOD;
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	int ans=0;
	for(int i=1;i<=n<<1;++i)
		for(int j=k;j<=n;++j)
			ans=(ans+1ll*dp[i][j]*dp[(n<<1)-i][j]%MOD*f[j])%MOD;
	ans=ans*qpow(dp[n<<1][0],MOD-2,MOD)%MOD*qpow(2*n+1,MOD-2,MOD)%MOD*l%MOD;
	cout<<ans<<endl;
	return 0;
}
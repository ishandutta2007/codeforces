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
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),m=read(),k=read(),a[55][20005],sum[55][20005],dp[55][20005],mxp[55][20005],mxs[55][20005];
signed main(){
	fz(i,1,n)	fz(j,1,m)	a[i][j]=read(),sum[i][j]=sum[i][j-1]+a[i][j];
	fz(i,1,m)	dp[1][i]=sum[1][min(i+k-1,m)]-sum[1][i-1];
	fz(i,1,m)	mxp[1][i]=max(mxp[1][i-1],dp[1][i]+sum[2][min(i+k-1,m)]-sum[2][i-1]);
	fd(i,m,1)	mxs[1][i]=max(mxs[1][i+1],dp[1][i]+sum[2][min(i+k-1,m)]-sum[2][i-1]);
	fz(i,2,n){
		fz(j,1,m){
			if(j+k<=m)	dp[i][j]=max(dp[i][j],mxs[i-1][j+k]+sum[i][j+k-1]-sum[i][j-1]);
			if(j-k>=1)	dp[i][j]=max(dp[i][j],mxp[i-1][j-k]+sum[i][j+k-1]-sum[i][j-1]);
			fz(l,max(j-k+1,1ll),min(j+k-1,m)){
				dp[i][j]=max(dp[i][j],dp[i-1][l]+sum[i][min(max(j+k-1,l+k-1),m)]-sum[i][min(j,l)-1]);
			}
//			cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
		fz(j,1,m)	mxp[i][j]=max(mxp[i][j-1],dp[i][j]+sum[i+1][min(j+k-1,m)]-sum[i+1][j-1]);
		fd(j,m,1)	mxs[i][j]=max(mxs[i][j+1],dp[i][j]+sum[i+1][min(j+k-1,m)]-sum[i+1][j-1]);
	}
	int ans=0;
	fz(i,1,m) ans=max(ans,dp[n][i]);
	cout<<ans<<endl;
	return 0;
}
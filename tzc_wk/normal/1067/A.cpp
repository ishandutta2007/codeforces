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
const int MOD=998244353;
int n,a[100005],dp[100005][205][2],ans,pre[205][2],suf[205][2];
signed main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	if(a[1]==-1)	for(int i=1;i<=200;i++) dp[1][i][0]=1;
	else			dp[1][a[1]][0]=1;
	fz(j,1,200){
		pre[j][0]=(pre[j-1][0]+dp[1][j][0])%MOD;
		pre[j][1]=(pre[j-1][1]+dp[1][j][1])%MOD;
	}
	fd(j,200,1){
		suf[j][0]=(suf[j+1][0]+dp[1][j][0])%MOD;
		suf[j][1]=(suf[j+1][1]+dp[1][j][1])%MOD;
	}
	for(int i=2;i<=n;i++){
		if(~a[i]){
			dp[i][a[i]][0]=(dp[i][a[i]][0]+pre[a[i]-1][0]+pre[a[i]-1][1])%MOD;
			dp[i][a[i]][1]=(dp[i][a[i]][1]+dp[i-1][a[i]][0]+dp[i-1][a[i]][1])%MOD;
			dp[i][a[i]][1]=(dp[i][a[i]][1]+suf[a[i]+1][1])%MOD;
		}
		else{
			for(int j=1;j<=200;j++){
				dp[i][j][0]=(dp[i][j][0]+pre[j-1][0]+pre[j-1][1])%MOD;
				dp[i][j][1]=(dp[i][j][1]+dp[i-1][j][0]+dp[i-1][j][1])%MOD;
				dp[i][j][1]=(dp[i][j][1]+suf[j+1][1])%MOD;
			}
		}
		fz(j,1,200){
			pre[j][0]=(pre[j-1][0]+dp[i][j][0])%MOD;
			pre[j][1]=(pre[j-1][1]+dp[i][j][1])%MOD;
		}
		fd(j,200,1){
			suf[j][0]=(suf[j+1][0]+dp[i][j][0])%MOD;
			suf[j][1]=(suf[j+1][1]+dp[i][j][1])%MOD;
		}
	}
	for(int i=1;i<=200;i++)	ans=(ans+dp[n][i][1])%MOD;
	cout<<ans<<endl;
    return 0;
}
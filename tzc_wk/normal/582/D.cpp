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
const int MAXL=4000;
const int MOD=1e9+7;
int n,alpha,len,m=0,a[MAXL+5],x[MAXL+5];
char A[MAXL+5];int dp[2][MAXL+5][2][2];
int main(){
	scanf("%d%d%s",&n,&alpha,A+1);len=strlen(A+1);
	if(alpha>MAXL) return puts("0"),0;
	for(int i=1;i<=len;i++) a[len-i+1]=A[i]-'0';
	while(len){
		ll cur=0;
		for(int i=len;i;i--){
			cur=cur*10+a[i];a[i]=cur/n;cur%=n;
		} x[++m]=cur;if(!a[len]) len--;
	} int cur=1,pre=0;
//	for(int i=1;i<=m;i++) printf("%d\n",x[i]);
	dp[cur][0][0][1]=1;
	for(int i=m;i;i--){
		cur^=pre^=cur^=pre;
		memset(dp[cur],0,sizeof(dp[cur]));
		int c1=1ll*(n+1)*n/2%MOD;
		int c2=1ll*(x[i]+1)*x[i]/2%MOD;
		int c3=1ll*(n-1)*n/2%MOD;
		int c4=1ll*x[i]*(n*2-x[i]-1)/2%MOD;
		int c5=1ll*(x[i]-1)*x[i]/2%MOD;
		int c6=1ll*x[i]*(n*2-x[i]+1)/2%MOD;
//		printf("%d %d %d %d %d %d\n",c1,c2,c3,c4,c5,c6);
		for(int j=0;j<=m-i+1;j++){
			int f0=dp[pre][j][0][0],f1=dp[pre][j][0][1];
			int f2=dp[pre][j][1][0],f3=dp[pre][j][1][1];
			dp[cur][j][0][0]=(1ll*f0*c1+1ll*f1*c2+1ll*f2*c3+1ll*f3*c4)%MOD;
			dp[cur][j][0][1]=(1ll*(x[i]+1)*f1+1ll*(n-x[i]-1)*f3)%MOD;
			dp[cur][j+1][1][0]=(1ll*f0*c3+1ll*f1*c5+1ll*f2*c1+1ll*f3*c6)%MOD;
			dp[cur][j+1][1][1]=(1ll*x[i]*f1+1ll*(n-x[i])*f3)%MOD;
		}
	} int ans=0;
	for(int i=alpha;i<=m;i++){
		ans=(ans+dp[cur][i][0][0])%MOD;
		ans=(ans+dp[cur][i][0][1])%MOD;
	} printf("%d\n",ans);
	return 0;
}
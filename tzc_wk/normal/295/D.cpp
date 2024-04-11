#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
const ll MOD=1e9+7;
ll n,m,dp[2005][2005],s1[2005][2005],s2[2005][2005],s[2005][2005],_s[2005][2005],__s[2005][2005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=2;i<=m;i++) dp[1][i]=1;
	for(int j=2;j<=m;j++){
		s1[1][j]=(s1[1][j-1]+dp[1][j])%MOD;
		s2[1][j]=(s2[1][j-1]+dp[1][j]*j%MOD)%MOD;
	}
	for(int i=2;i<=n;i++){
		for(int j=2;j<=m;j++){
			dp[i][j]=(-s2[i-1][j]+s1[i-1][j]*(j+1)%MOD+MOD)%MOD;
//			printf("%d %d %lld\n",i,j,dp[i][j]);
		}
		for(int j=2;j<=m;j++){
			s1[i][j]=(s1[i][j-1]+dp[i][j])%MOD;
			s2[i][j]=(s2[i][j-1]+dp[i][j]*j%MOD)%MOD;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++) for(int j=2;j<=m;j++) s[i][j]=(s[i-1][j]+dp[i][j])%MOD;
	for(int i=1;i<=n;i++) for(int j=2;j<=m;j++) _s[i][j]=(_s[i][j-1]+s[i][j])%MOD;
	for(int i=1;i<=n;i++) for(int j=2;j<=m;j++) __s[i][j]=(__s[i][j-1]+s[i][j]*j%MOD)%MOD;
	for(int i=1;i<=n;i++) for(int j=2;j<=m;j++){
		ans=(ans+s[i][j]*(_s[n-i][j-1]*(j+1)%MOD-__s[n-i][j-1]+MOD+1)%MOD*(m-j+1)%MOD)%MOD;
//		printf("%d %d %lld\n",i,j,s[i][j]*(_s[n-i][j-1]*(j+1)%MOD-__s[n-i][j-1]+MOD+1)%MOD*(m-j+1)%MOD);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
dp[i][j]=\sum dp[i-1][k]*(j-k+1)
\sum s[x][k]*(j-k+1)
*/
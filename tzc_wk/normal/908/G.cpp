#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
const int MOD=1e9+7;
const int MAXN=700+5;
const int MAXD=10+2;
char s[MAXN];int n;
ll dp[MAXN][MAXN][MAXD][2];
ll one[MAXN];
void add(ll &x,ll y){x+=y;if(x>=MOD) x-=MOD;}
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++) one[i]=(1ll*one[i-1]*10+1)%MOD;
	for(int i=1;i<=9;i++) dp[0][0][i][0]=1;
	for(int i=0;i<n;i++) for(int up=0;up<2;up++){
		int to=((up)?(9):(s[i+1]-48));
		for(int j=0;j<=i;j++) for(int k=1;k<=9;k++) for(int d=0;d<=to;d++)
			add(dp[i+1][j+(d>=k)][k][up|(d<to)],dp[i][j][k][up]);
	}
	ll ans=0;
	for(int i=1;i<=9;i++) for(int j=1;j<=n;j++){
//		printf("%d %d %d\n",i,j,dp[n][j][i][0]+dp[n][j][i][1]);
		add(ans,(dp[n][j][i][0]+dp[n][j][i][1])%MOD*one[j]%MOD);
	}
	printf("%lld\n",ans);
	return 0;
}
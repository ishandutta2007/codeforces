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
typedef long long ll;
typedef pair<int,int> pii;
const int MOD=1e9+7;
inline void inc(int &x,int y){x+=y;if(x>=MOD) x-=MOD;}
int n,p,a[55],dp[55][2][2][2],pw2[55];
int main(){
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	pw2[0]=1;
	for(int i=1;i<=n;i++) pw2[i]=pw2[i-1]*2%MOD;
	if(a[1]!=1) dp[1][1][1][0]=1;
	if(a[1]!=0) dp[1][1][0][1]=1;
	for(int i=1;i<n;i++) for(int j=0;j<2;j++)
		for(int b=0;b<2;b++) for(int w=0;w<2;w++){
			if(a[i+1]!=1){
				if(w){
					inc(dp[i+1][j^1][1][1],1ll*dp[i][j][b][w]*pw2[i-1]%MOD);
					inc(dp[i+1][j][b][1],1ll*dp[i][j][b][w]*pw2[i-1]%MOD);
				}
				else inc(dp[i+1][j^1][1][0],1ll*dp[i][j][b][w]*pw2[i]%MOD);
			}
			if(a[i+1]!=0){
				if(b){
					inc(dp[i+1][j^1][1][1],1ll*dp[i][j][b][w]*pw2[i-1]%MOD);
					inc(dp[i+1][j][1][w],1ll*dp[i][j][b][w]*pw2[i-1]%MOD);
				}
				else inc(dp[i+1][j^1][0][1],1ll*dp[i][j][b][w]*pw2[i]%MOD);
			}
		}
//	for(int i=1;i<=n;i++) for(int j=0;j<2;j++)
//		for(int b=0;b<2;b++) for(int w=0;w<2;w++)
//			printf("%d %d %d %d %d\n",i,j,b,w,dp[i][j][b][w]);
	int ans=0;
	for(int b=0;b<2;b++) for(int w=0;w<2;w++)
		inc(ans,dp[n][p][b][w]);
	printf("%d\n",ans);
	return 0;
}
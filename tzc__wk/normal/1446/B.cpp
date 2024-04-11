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
int n,m,dp[5005][5005],ans=0;
char s[5005],t[5005];
int main(){
	scanf("%d%d%s%s",&n,&m,s+1,t+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
		if(s[i]==t[j]) dp[i][j]=dp[i-1][j-1]+2;
		else dp[i][j]=max(dp[i][j-1],dp[i-1][j])-1;
		dp[i][j]=max(dp[i][j],0);
		ans=max(ans,dp[i][j]);
//		printf("%d %d %d\n",i,j,dp[i][j]);
	}
	printf("%d\n",ans);
	return 0;
}
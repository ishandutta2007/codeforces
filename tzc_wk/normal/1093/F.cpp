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
const int MOD=998244353; 
int n,k,l,a[100005],dp[100005][105],pre[105],sum[100005][105],s[100005];
int main(){
	scanf("%d%d%d",&n,&k,&l);
	if(l==1) return puts("0"),0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(a[1]==-1){
		for(int i=1;i<=k;i++) dp[1][i]=sum[1][i]=1;
		s[1]=k;
	} else {
		for(int i=1;i<=k;i++) if(i!=a[1]) pre[i]=1;
		s[1]=1;dp[1][a[1]]=1;sum[1][a[1]]=1;
	}
	for(int i=2;i<=n;i++){
//		for(int j=1;j<=k;j++) printf("%d ",pre[j]);
//		printf("\n");
		if(a[i]==-1){
			for(int j=1;j<=k;j++){
				dp[i][j]=s[i-1];
				dp[i][j]=(dp[i][j]-s[max(i-l,max(pre[j]-1,0))]+MOD)%MOD;
				dp[i][j]=(dp[i][j]-sum[i-1][j]+MOD)%MOD;
				dp[i][j]=(dp[i][j]+sum[max(i-l,max(pre[j]-1,0))][j])%MOD;
				if(i<l&&pre[j]==0) dp[i][j]=(dp[i][j]+1)%MOD;
			}
		} else {
			dp[i][a[i]]=s[i-1];
			dp[i][a[i]]=(dp[i][a[i]]-s[max(i-l,max(pre[a[i]]-1,0))]+MOD)%MOD;
			dp[i][a[i]]=(dp[i][a[i]]-sum[i-1][a[i]]+MOD)%MOD;
			dp[i][a[i]]=(dp[i][a[i]]+sum[max(i-l,max(pre[a[i]]-1,0))][a[i]])%MOD;
			if(i<l&&pre[a[i]]==0) dp[i][a[i]]=(dp[i][a[i]]+1)%MOD;
		}
		if(a[i]!=-1) for(int j=1;j<=k;j++)
			if(j!=a[i]) pre[j]=i;
		s[i]=s[i-1];
		for(int j=1;j<=k;j++){
			s[i]=(s[i]+dp[i][j])%MOD;
			sum[i][j]=(sum[i-1][j]+dp[i][j])%MOD;
//			printf("%d %d %d %d\n",i,j,dp[i][j],sum[i][j]);
		}
	}
//	for(int i=1;i<=n;i++) printf("%d\n",s[i]);
	int ans=0;
	for(int i=1;i<=k;i++) ans=(ans+dp[n][i])%MOD;
	printf("%d\n",ans);
	return 0;
}
/*1
5 2 3
1 -1 1 -1 2
*/
/*2
6 3 2
1 1 -1 -1 -1 -1
*/
/*3
10 42 7
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
*/
/*4
7 3 3
1 2 -1 2 3 -1 -1
*/
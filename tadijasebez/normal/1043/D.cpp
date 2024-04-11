#include <bits/stdc++.h>
using namespace std;
const int N=100050;
const int M=12;
int per[N][M],f[N],mn[N],dp[N];
void ckmn(int &a, int b){ a=min(a,b);}
int main()
{
	int n,m,i,j;long long ans=0;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++) for(j=1;j<=n;j++) scanf("%i",&per[j][i]),f[per[j][i]]=j,mn[j]=N;
	for(i=1;i<=m;i++) for(j=1;j<=n;j++) per[j][i]=f[per[j][i]];
	for(i=1;i<=m;i++) for(j=n;j>=1;j--) dp[j]=per[j+1][i]==per[j][i]+1?dp[j+1]+1:1,ckmn(mn[per[j][i]],dp[j]);
	for(j=1;j<=n;j++) ans+=mn[j];
	printf("%lld\n",ans);
	return 0;
}
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=1050;
bool dp[2][N];
int cnt[N];
int x[N*N];
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&x[i]),x[i]%=m;
	if(n<=m)
	{
		int now=1,pre=0;
		for(i=1;i<=n;i++){
			for(j=0;j<m;j++) dp[now][(j+x[i])%m]|=dp[pre][j] || dp[pre][(j+x[i])%m];
			dp[now][x[i]]=1;
			now^=1,pre^=1;
		}
		if(dp[pre][0]) printf("YES\n");
		else printf("NO\n");
	}
	else printf("YES\n");
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fi first
#define se second
const int N=2000050;
int n,a[N];
pii dp[N];
pii comb(pii x,pii y){
	pii ret={0,0};
	if(x.fi==y.fi)ret={x.fi,max(x.se,y.se)};
	else if(x.fi>y.fi)ret={x.fi,max(x.se,y.fi)};
	else ret={y.fi,max(x.fi,y.se)};
	return ret;
}
int main(){
	scanf("%i",&n);
	for(int i=1;i<=n;i++)scanf("%i",&a[i]),dp[a[i]]=comb(dp[a[i]],{i,0});
	for(int i=N-1;i>0;i--)for(int j=0;j<=22;j++)if(i>>j&1)dp[i^(1<<j)]=comb(dp[i^(1<<j)],dp[i]);
	int ans=0;
	for(int i=1;i<=n-2;i++){
		int mx=0;
		for(int j=22;j>=0;j--)if(!(a[i]>>j&1)){
			if(mx+(1<<j)<N&&dp[mx+(1<<j)].se>i)mx+=(1<<j);
		}
		assert(mx==0||dp[mx].se>i);
		ans=max(ans,mx+a[i]);
	}
	printf("%i",ans);
	return 0;
}
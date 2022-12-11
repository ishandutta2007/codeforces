# include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N],dp[N],pd[N],len[N];
long long ans;
void upd(int x){
	if(n<x)return;
	int ddp=0,dpd=n+1;
	if(pd[x-1]<a[x])ddp=max(ddp,a[x-1]);
	if(a[x-1]<a[x])ddp=max(ddp,dp[x-1]);
	if(a[x]<dp[x-1])dpd=min(dpd,a[x-1]);
	if(a[x]<a[x-1])dpd=min(dpd,pd[x-1]);
	if(ddp==dp[x]&&dpd==pd[x])return;
	dp[x]=ddp,pd[x]=dpd;
	len[x]=0;
	if(dpd<=n||ddp){
		upd(x+1);
		len[x]=len[x+1]+1;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=n;i>=1;i--){
		dp[i]=n+1;
		pd[i]=0;
		upd(i+1);
		len[i]=len[i+1]+1;
		ans+=len[i];
	}
	printf("%lld",ans);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const long long inf=1e9+7,N=1e6+10;
long long n,a[N],dp1[N],dp2[N],dp3[N][2];
long long solve(){
	long long now=max_element(a,a+n)-a;
	for(long long i=0;i<N;i++){
		dp1[i]=dp2[i]=dp3[i][0]=1e9;
		dp3[i][1]=-1e9;
	}
	dp1[0]=-1;
	for(long long i=1;i<=now;++i){
		if(a[i]>dp1[i-1])dp1[i]=min(dp1[i],a[i-1]);
		if(a[i]>a[i-1])dp1[i]=min(dp1[i],dp1[i-1]);
	}
	dp2[n-1]=-1;
	for(long long i=n-2;i>=now;--i){
		if(a[i]>dp2[i+1])dp2[i]=min(dp2[i],a[i+1]);
		if(a[i]>a[i+1])dp2[i]=min(dp2[i],dp2[i+1]);
	}
	dp3[now][0]=dp1[now];
	long long ans=0;
	for(long long i=now+1;i<n;++i){
		if(a[i-1]>a[i])dp3[i][0]=min(dp3[i][0],dp3[i-1][0]);
		if(dp3[i-1][1]>a[i])dp3[i][0]=min(dp3[i][0],a[i-1]);
		if(a[i-1]<a[i])dp3[i][1]=max(dp3[i][1],dp3[i-1][1]);
		if(dp3[i-1][0]<a[i])dp3[i][1]=max(dp3[i][1],a[i-1]);
		if(dp3[i][1]>dp2[i])ans++;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(long long i=0;i<n;++i)scanf("%d",&a[i]);
	long long ans=0;
	ans+=solve();
	reverse(a,a+n);
	ans+=solve();
	printf("%lld\n",ans);
}
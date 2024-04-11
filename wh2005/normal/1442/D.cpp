#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 3009;
int n,m;ll a[N][N],ans;
vector<ll > dp;
void solve(int l,int r){
	if(l>r) return ;
	if(l==r){
		int p=min(m,(int)a[l][0]);
		for(int j=1;j<=p;j++)
			dp[m]=max(dp[m],dp[m-j]+a[l][j]);
		ans=max(ans,dp[m]);
		return ;
	}
	vector<ll > tmp;tmp=dp;
	int mid=(l+r)>>1;
	for(int i=l;i<=mid;i++)
		for(int j=m;j>=a[i][0];j--)
			dp[j]=max(dp[j],dp[j-a[i][0]]+a[i][a[i][0]]);
	solve(mid+1,r);
	dp=tmp;
	for(int i=mid+1;i<=r;i++)
		for(int j=m;j>=a[i][0];j--)
			dp[j]=max(dp[j],dp[j-a[i][0]]+a[i][a[i][0]]);
	solve(l,mid);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i][0]);
		for(int j=1;j<=a[i][0];j++) scanf("%lld",&a[i][j]);
		for(int j=2;j<=a[i][0];j++) a[i][j]+=a[i][j-1];
 	}
	ans=0;dp.resize(m+10);
	solve(1,n);
	printf("%lld\n",ans);
	return 0;
}
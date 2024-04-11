//CF1442D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 3333;
const LL inf = 1e15;
void cmax(LL&x,LL y){
	if(x<y)
		x=y;
}
int n,k,sz[N];
LL a[N],ans,dp[22][N];
vector<LL> v[N];
void solve(int l,int r,int d){
	if(l==r){
		int i;
		for(i=1;i<=sz[l]&&i<=k;i=i+1)
			cmax(ans,v[l][i-1]+dp[d][k-i]);
		return;
	}
	int h=l+r>>1,i,j;
	for(i=0;i<=k;i=i+1)
		dp[d+1][i]=dp[d][i];
	for(j=h+1;j<=r;j=j+1)
		for(i=k;i>=sz[j];i=i-1)
			cmax(dp[d+1][i],dp[d+1][i-sz[j]]+a[j]);
	solve(l,h,d+1);
	for(i=0;i<=k;i=i+1)
		dp[d+1][i]=dp[d][i];
	for(j=l;j<=h;j=j+1)
		for(i=k;i>=sz[j];i=i-1)
			cmax(dp[d+1][i],dp[d+1][i-sz[j]]+a[j]);
	solve(h+1,r,d+1);
}
int main()
{
	int i,j,x;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i=i+1){
		scanf("%d",sz+i);
		a[i]=0;
		for(j=0;j<sz[i];j=j+1){
			scanf("%d",&x);
			a[i]+=x;
			v[i].push_back(a[i]);
		}
	}
	dp[0][0]=inf;
	solve(1,n,0);
	cout<<ans-inf;
	return 0;
}
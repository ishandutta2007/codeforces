#include <bits/stdc++.h>
using namespace std;
const int N=100050;
const int inf=1e9;
int dp[N],tmp[N],n,m;
void Upd(int x,int s){
	for(int i=0;i<=m;i++)tmp[i]=inf;
	for(int i=0;i<=m;i++){
		int r=min(m,x+s+i);
		int l=max(0,x-s-i-1);
		tmp[r]=min(tmp[r],dp[l]+i);
	}
	for(int i=m;i>0;i--)dp[i]=min(dp[i],tmp[i]),dp[i-1]=min(dp[i-1],dp[i]);
}
pair<int,int> a[N];
int main(){
	scanf("%i %i",&n,&m);
	for(int i=1;i<=n;i++)scanf("%i %i",&a[i].first,&a[i].second);
	sort(a+1,a+1+n);
	dp[0]=0;
	for(int i=1;i<=m;i++)dp[i]=inf;
	for(int i=1;i<=n;i++)Upd(a[i].first,a[i].second);
	printf("%i\n",dp[m]);
	return 0;
}
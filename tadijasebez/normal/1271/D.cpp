#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
void ckmx(int &x,int y){x=max(x,y);}
const int N=5050;
const int inf=1e9+7;
int a[N],b[N],c[N];
vector<int> cst,my[N],E[N];
int dp[N][N],mx[N];
int main(){
	int n,m,k;
	scanf("%i %i %i",&n,&m,&k);
	for(int i=1;i<=n;i++)scanf("%i %i %i",&a[i],&b[i],&c[i]),mx[i]=i;
	for(int i=1,u,v;i<=m;i++)scanf("%i %i",&u,&v),ckmx(mx[v],u);
	for(int i=1;i<=n;i++)E[mx[i]].pb(i);
	for(int i=n;i>=1;i--){
		cst.clear();
		for(int j:E[i])cst.pb(c[j]);
		sort(cst.rbegin(),cst.rend());
		my[i].pb(0);
		for(int j=1;j<=cst.size();j++)my[i].pb(my[i][j-1]+cst[j-1]);
	}
	for(int i=0;i<N;i++)for(int j=0;j<N;j++)dp[i][j]=-inf;
	dp[0][k]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<my[i].size();j++)
			for(int p=0;p<N;p++)
				if(p>=a[i] && p+b[i]-j<N && p+b[i]-j>=0)
					ckmx(dp[i][p+b[i]-j],dp[i-1][p]+my[i][j]);
	}
	int ans=-inf;
	for(int i=0;i<N;i++)ckmx(ans,dp[n][i]);
	if(ans>=0)printf("%i\n",ans);
	else printf("-1\n");
	return 0;
}
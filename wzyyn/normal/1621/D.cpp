#include<bits/stdc++.h>

using namespace std;

const int N=505;
int n,c[N][N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=2*n;i++)
		for (int j=1;j<=2*n;j++)
			scanf("%d",&c[i][j]);
	long long ans=1<<30;
	ans=min(ans,1ll*min(c[1][n+1],c[1][2*n]));
	ans=min(ans,1ll*min(c[n][n+1],c[n][2*n]));
	ans=min(ans,1ll*min(c[n+1][1],c[n+1][n]));
	ans=min(ans,1ll*min(c[2*n][1],c[2*n][n]));
	for (int i=n+1;i<=2*n;i++)
		for (int j=n+1;j<=2*n;j++)
			ans+=c[i][j];
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
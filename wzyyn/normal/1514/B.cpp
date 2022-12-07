#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	int ans=1;
	for (int i=1;i<=k;i++)
		ans=1ll*ans*n%1000000007;
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
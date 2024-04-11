#include<bits/stdc++.h>
using namespace std;

int n,d[100005];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&d[i]);
	sort(d+1,d+n+1);
	long long ans=d[n];
	for (int i=1;i<=n;i++)
		ans+=(n-i-(i-1))*1ll*d[i];
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
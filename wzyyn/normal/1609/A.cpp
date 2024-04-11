#include<bits/stdc++.h>

using namespace std;

void solve(){
	int mx=0,s=0,x,n;
	long long sum=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		for (;x%2==0;x/=2,++s);
		sum+=x; mx=max(mx,x);
	}
	sum=sum-mx+((1ll*mx)<<s);
	cout<<sum<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
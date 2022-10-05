#include<bits/stdc++.h>
using namespace std;
long long a[210000];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		long long ans=0;
		for(int i=1;i<=n-1;i++)
		ans+=max(0ll,a[i]-a[i+1]);
		cout<<ans<<endl;
	}
	return 0;
}
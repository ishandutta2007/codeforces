#include<bits/stdc++.h>
using namespace std;
int t,n,a[200005];
int main(){
	cin>>t;
	while(t--){
		scanf("%d",&n);
		long long ave=0;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]),ave+=a[i];
		int kk=__gcd(1ll*n,ave);
		if(n/kk==1)ave=ave*2/kk;
		else if(n/kk==2)ave=ave/kk;
		else{
			puts("0");
			continue;
		}
		sort(a+1,a+n+1);
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans+=upper_bound(a+i+1,a+n+1,ave-a[i])-lower_bound(a+i+1,a+n+1,ave-a[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}
using namespace std;
#include<bits/stdc++.h>
long long n,a[2001],k;
int main() {
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	int p=0,ans=0;
	while(1)
	{
		while(p<n&&k*2>=a[p+1]) {
			k=max(k,a[p+1]);p++;
		}	
		if(p==n) {
			cout<<ans<<endl;
			return 0;
		}
		while(k*2<a[p+1]) {
			ans++;k*=2;
		}
		k=a[++p];
		if(p==n) {
			cout<<ans<<endl;break;
		}
	}

}
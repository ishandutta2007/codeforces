#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
int a[210000];
long long b[210000];
int main(){
	int _;
	cin>>_;
	while(_--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		b[1]=a[1];
		for(int i=2;i<=n;i++)b[i]=b[i-1]+a[i];
		long long ans=1e18;
		for(int i=0;i<n;i++){
			long long anss=i;
			long long o=k-b[n-i]+b[1];
			o=1ll*(i+1)*a[1]-o;
			if(o<=0)ans=min(ans,anss);
			else ans=min(ans,anss+(o+i)/(i+1));
		}
		cout<<ans<<endl;
	}
	return 0;
}
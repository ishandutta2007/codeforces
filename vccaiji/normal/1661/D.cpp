#include<bits/stdc++.h>
using namespace std;
int n,k;
long long b[310000];
long long a[310000];
long long c[310000];
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>b[i];
	long long ans=0;
	long long now=0;
	for(int i=n;i>k;i--){
		a[i]=max(0ll,b[i]-now+k-1)/k;
		c[i]=c[i+1]+a[i];
		now+=(k-1)*a[i]-c[i+1]+c[i+k];
		ans+=a[i];
	}
	long long maxx=0;
	for(int i=k;i>=1;i--){
		maxx=max(maxx,max(0ll,b[i]-now+i-1)/i);
		c[i]=c[i+1];
		now+=(k-1)*a[i]-c[i+1]+c[i+k];
	}
	cout<<ans+maxx;
	return 0;
}
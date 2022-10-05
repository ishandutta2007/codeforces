#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int x[210000];
long long u[210000];
int main(){
	int _;
	cin>>_;
	while(_--){
		cin>>n>>a>>b;
		for(int i=1;i<=n;i++)cin>>x[i];
		u[0]=0;
		for(int i=1;i<=n;i++)u[i]=u[i-1]+x[i];
		long long ans=b*u[n];
		for(int i=1;i<=n;i++)ans=min(ans,1ll*a*x[i]+1ll*b*x[i]+b*(u[n]-u[i]-1ll*x[i]*(n-i)));
		cout<<ans<<endl;
	}
	return 0;
}
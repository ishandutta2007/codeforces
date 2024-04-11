#include<bits/stdc++.h>
using namespace std;
int n,x;
long long a[210000];
int t[210000];
int main(){
	int _;
	cin>>_;
	while(_--){
		cin>>n>>x;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++)a[i]+=a[i-1];
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(x>=a[i])ans+=(x-a[i])/i+1;
		}
		cout<<ans<<endl;
	} 
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int a[210000];
int b[210000];
int main(){
	int _;
	cin>>_;
	while(_--){
		int n;
		cin>>n;
		if(n<100){
			cout<<n%10<<"\n";
			continue;
		}
		int ans=10;
		for(;n;n/=10)ans=min(ans,n%10);
		cout<<ans<<"\n";
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		int n;
		scanf("%d",&n);
		if(n&1){
			cout<<0<<endl;
			continue;
		}
		int ans=1;
		for(int i=1;i<=n/2;i++) ans=1ll*ans*i%p;
		cout<<1ll*ans*ans%p<<endl;
	}
	return 0;
}
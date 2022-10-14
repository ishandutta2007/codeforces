#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main(){
	int tt;
	scanf("%i",&tt);
	while(tt--){
		int n,m;
		scanf("%i%i",&n,&m);
		long long ans=0;
		for(int i=0;i<m;i++){
			int l,r,x;
			scanf("%i%i%i",&l,&r,&x);
			ans|=x;
		}
		ans%=mod;
		long long pw=1;
		for(int i=1;i<n;i++)pw=(pw*2)%mod;
		printf("%lld\n",(ans*pw)%mod);
	}
	return 0;
}
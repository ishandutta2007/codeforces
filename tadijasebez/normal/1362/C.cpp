#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;scanf("%i",&t);
	while(t--){
		long long n;scanf("%lld",&n);
		long long ans=0;
		for(long long pw=1;pw<=n;pw*=2){
			long long blocks=(n+pw)/pw;
			ans+=blocks-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
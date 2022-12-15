#include <bits/stdc++.h>
using namespace std;

long long n, k, x, i, ans=1LL<<60, ans2, ans3;

int main(){
	for(scanf("%lld%lld",&n,&k);i<k;i++){
		scanf("%lld",&x);
		if(n%x<ans){
			ans = n%x;
			ans2 = i+1;
			ans3 = x;
		}
	}
	printf("%lld %lld\n",ans2,n/ans3);
	return 0;
}
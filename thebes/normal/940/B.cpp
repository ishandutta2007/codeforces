#include <bits/stdc++.h>
using namespace std;

long long n, k, A, B, x, j, ans;

int main(){
	scanf("%lld%lld%lld%lld",&n,&k,&A,&B);
	if(k==1){
		printf("%lld\n",(n-1)*A);
		return 0;
	}
	while(n!=1){
		if(n%k==0){
			ans += min((n-n/k)*A,B);
			n /= k;
		}
		else{
			x = n/k*k; x=max(1LL,x);
			ans += A*(n-x); n=x;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
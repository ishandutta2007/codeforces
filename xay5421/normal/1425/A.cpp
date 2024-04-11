#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int T;
LL sol(LL n){
	if(n==0)return 0;
	if(n==4)return 3;
	if(n/2%2==0){
		return sol(n-2)+1;
	}else{
		return sol(n/2-1)+n/2;
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
		LL n;
		scanf("%lld",&n);
		if(n&1){
			printf("%lld\n",n-sol(n-1));
		}else{
			printf("%lld\n",sol(n));
		}
	}
	return 0;
}
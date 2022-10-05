#include<bits/stdc++.h>
using namespace std;
int a[1100000];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		long long n;
		scanf("%lld",&n);
		if(n&1ll){
			printf("2\n");
			continue;
		}
		int o=0;
		for(;;o++){
			if((n>>o)&1ll)break;
		}
		long long u=(n>>o);
		if(u>=(1ll<<(o+1))+1){
			printf("%lld\n",(1ll<<(o+1)));
			continue;
		}
		if(u==1){
			printf("-1\n");
			continue;
		}
		printf("%lld\n",u);
	}
	return 0;
}
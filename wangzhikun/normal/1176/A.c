#include <stdio.h>

int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		int ans = 0;
		long long x = -1,nx;
		scanf("%lld",&nx);
		while(x!=1 && x!=nx){
			x = nx;
			if(nx%2 == 0){
				nx/=2;
				ans+=1;
			}
			if(nx%3 == 0){
				nx = nx*2/3;
				ans+=1;
			}
			if(nx%5 == 0){
				nx = nx*4/5;
				ans+=1;
			}
		}
		if(x == nx && x!=1)ans = -1;
		printf("%d\n",ans);
	}
	return 0;
}
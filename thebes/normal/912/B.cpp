#include <bits/stdc++.h>
using namespace std;

long long x, y;

int main(){
	scanf("%lld%lld",&x,&y);
	for(int p=60;p>=0;p--){
		if((1LL<<p)&x){
		    if(y>=2) printf("%lld\n",(1LL<<(p+1))-1);
		    else printf("%lld\n",x);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}
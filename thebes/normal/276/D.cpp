#include <bits/stdc++.h>
using namespace std;

long long x, y;

int main(){
	scanf("%lld%lld",&x,&y);
	for(int p=60;p>=0;p--){
		bool a = (1LL<<p)&x;
		bool b = (1LL<<p)&y;
		if(a != b){
			printf("%lld\n",(1LL<<(p+1))-1);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}
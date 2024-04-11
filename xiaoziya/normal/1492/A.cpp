#include<stdio.h>
#include<iostream>
using namespace std;
int T;
long long p,a,b,c;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&p,&a,&b,&c);
		printf("%lld\n",min(((p-1)/a+1)*a,min(((p-1)/b+1)*b,((p-1)/c+1)*c))-p);
	}
	return 0;
}
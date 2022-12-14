#include <cstdio>
#include <iostream>
using namespace std;
void test(){
	int l,r,b,c,n,lim;
	long long m;
	scanf("%d%d%lld",&l,&r,&m);
	lim=r-l;
	for(int a=l-1; ++a<=r; ){
		n=m/a,
		b=m%a;
		if(n&&b<=lim){
			c=l,b+=l;
			printf("%d %d %d\n",a,b,c);
			return;
		}
		if(b>=a-lim){
			++n,b+=r-a,c=r;
			printf("%d %d %d\n",a,b,c);
			return;
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	for(++t; --t; test());
	return 0;
}
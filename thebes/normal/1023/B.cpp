#include <bits/stdc++.h>
using namespace std;

long long n, k, a, b, t;
int main(){
	scanf("%lld%lld",&n,&k);
	a = 1, b = k-1;
	t = max(0LL,b-n);
	a += t; b -= t;
	if(a>=b) printf("0\n");
	else if((a+b)&1) printf("%lld\n",(b-a+1)/2);
	else printf("%lld\n",(b-a)/2);
	return 0;
}
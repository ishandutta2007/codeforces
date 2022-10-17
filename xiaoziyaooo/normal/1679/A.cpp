#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int maxn=500005;
int T;
long long n,ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		if(n<4||n&1){
			puts("-1");
			continue;
		}
		n>>=1;
		long long a=n/3;
		while((n-3*a)%2)
			a--;
		printf("%lld ",a+(n-3*a)/2);
		long long b=n/2;
		while((n-2*b)%3)
			b--;
		printf("%lld\n",b+(n-2*b)/3);
	}
	return 0;
}
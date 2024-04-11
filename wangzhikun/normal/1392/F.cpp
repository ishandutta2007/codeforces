#include <stdio.h>
long long s,n,a;
int main(){
	scanf("%lld",&n),s=n-n*(n-1)/2-1;
	for(int i=0;i<n;i++)scanf("%lld",&a),s+=a;
	for(long long i=s/n;i<s/n+n;i++)printf("%lld ",i-(i>s/n+s%n));
}
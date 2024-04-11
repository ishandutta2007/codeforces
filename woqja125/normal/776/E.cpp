#include<stdio.h>
const int MOD = 1000000007;
long long pi(long long x){
	long long i, re=x;
	for(i=2; i*i <= x; i++){
		if(x%i == 0){
			while(x%i == 0) x/=i;
			re = re / i * (i-1);
		}
	}
	if(x != 1) re = re / x * (x-1);
	return re;
}
int main(){
	long long n, k;
	scanf("%lld%lld", &n, &k);
	k = (k+1)/2;
	for(int i=1; i<=k; i++)
	{
		n = pi(n);
		if(n==1) break;
	}
	printf("%d", n%MOD);
	return 0;
}
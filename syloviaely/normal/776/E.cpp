#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
long long phi(long long k1){
	long long ans=1;
	for (int i=2;1ll*i*i<=k1;i++)
		if (k1%i==0){
			ans*=(i-1); k1/=i;
			while (k1%i==0){
				k1/=i; ans*=i;
			}
		}
	return ans*max(1ll,k1-1);
}
long long n,k;
const int mo=1e9+7;
long long get(long long k1,long long k2){
	if (k1==1) return 1; 
	if (k2==1) return phi(k1);
	if (k2%2==0) return get(k1,k2-1);
	return get(phi(k1),k2-1);
}
int main(){
	scanf("%I64d%I64d",&n,&k);
	printf("%I64d\n",get(n,k)%mo);
	return 0;
}
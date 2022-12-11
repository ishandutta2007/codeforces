#include<bits/stdc++.h>
using namespace std;
long long n,mo=1e9+7;
long long po(long long x,long long y,long long mod){
	long long res=1;
	while(y){
		if(y&1)res*=x,res%=mod;
		x*=x;
		x%=mod;
		y>>=1;
	}
	return res;
}
int main(){
	scanf("%lld",&n);
	printf("%lld",(po(4ll,(po(2ll,n,mo-1)+mo-1-2ll)%(mo-1),mo)*6ll)%mo);
	return 0;
}
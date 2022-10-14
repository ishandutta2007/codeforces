#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,md=1000000007;
int pow(int x, long long k){
	if(k==0) return 1;
	int ans=1;
	if(k&1) ans=x;
	int y=pow(x,k>>1);
	y=1ll*y*y%md;
	return 1ll*y*ans%md;
}
int main(){
	scanf("%lld",&n);
	if(n==0)printf("1");
	else printf("%i",1ll*pow(2,n-1)*(pow(2,n)+1)%md);
}
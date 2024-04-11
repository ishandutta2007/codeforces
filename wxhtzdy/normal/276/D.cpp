#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll l,r;scanf("%lld %lld",&l,&r);
	for(int i=60;~i;i--)if((l&(1LL<<i))!=(r&(1LL<<i)))return 0*printf("%lld",(1LL<<(i+1))-1);
	printf("0");
	return 0;
}
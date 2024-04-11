#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
long long n, x, ans=1LL<<60;
ll s(ll x){
	ll r = 0;
	while(x){
		r += x%10;
		x /= 10;
	}
	return r;
}

int main(){
	scanf("%lld",&n);
	x = sqrt(n);
	for(int i=0;i<1000000&&x>0;i++){
		if(x*x+s(x)*x==n) ans=x;
		x--;
	}
	printf("%lld\n",(ans==1LL<<60)?-1:ans);
	return 0;
}
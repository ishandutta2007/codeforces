#include <bits/stdc++.h>
using namespace std;

long long n, a, b, c, d, ans;

int main(){
	scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
	d = min(b-c,a); ans += max(0LL,(n-b)/d); n-=ans*d;
	if(n >= b){ans++; n-=d;}
	ans += n/a;
	printf("%lld\n",ans);
	return 0;
}
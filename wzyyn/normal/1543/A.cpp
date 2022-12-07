#include<bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	ll a,b;
	scanf("%lld%lld",&a,&b);
	if (a==b) puts("0 0");
	else{
		ll p=abs(a-b);
		printf("%lld %lld\n",p,min(a%p,p-a%p));
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
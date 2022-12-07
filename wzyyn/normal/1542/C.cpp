#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
void solve(){
	ll n,ans,v=1;
	scanf("%lld",&n);
	ans=n;
	for (int i=2;;i++){
		ll d=i/gcd(v,i);
		ans+=n;
		n/=d;
		v*=d;
		if (!n) break;
	}
	cout<<ans%1000000007<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
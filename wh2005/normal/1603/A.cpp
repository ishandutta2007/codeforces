#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e6+9;
int T,n;
ll a[N];
ll gcd(ll x,ll y){
	if(!y) return x;
	return gcd(y,x%y);
}
ll lcm(ll x,ll y){
	return x/gcd(x,y)*y;
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		ll t=1;int flag=1;
		for(int i=1;i<=n;i++){
			t=lcm(i+1,t);
			if(t>1e9) break;
			if(a[i]%t==0) flag=0;
		}
		if(!flag) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,m,ans;
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}

ll sec(ll idx,ll u){
	if (idx==1){
		return (u-1)/(n/ans);
	}	
	else{
		return (u-1)/(m/ans);
	}
}
int main(){
	scanf("%lld%lld",&n,&m);
	ans=gcd(n,m);
	int q;
	scanf("%d",&q);
	while(q--){
		ll u,v,w,x;
		cin>>u>>v>>w>>x;
		if (sec(u,v)==sec(w,x)){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
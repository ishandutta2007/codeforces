#include<cstdio>
#define ll long long

ll n,m,q;

inline ll gcd(ll x,ll y){
	if(!y)
		return x;
	return gcd(y,x%y);
}

int main(){
	scanf("%I64d%I64d%I64d",&n,&m,&q);
	ll g=gcd(n,m);
	n/=g;
	m/=g;
	for(ll i=1;i<=q;i++){
		ll s1,s2,e1,e2;
		scanf("%I64d%I64d%I64d%I64d",&s1,&s2,&e1,&e2);
		s2=s1==1?(s2-1)/n+1:(s2-1)/m+1;
		e2=e1==1?(e2-1)/n+1:(e2-1)/m+1;
		if(s2==e2)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
#include<bits/stdc++.h>
#define ll long long

int T;

ll n;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		ll tmp=1;
		while(!(n&1))
			tmp<<=1,n>>=1;
		if(n==1)
			puts("-1");
		else
			printf("%lld\n",std::min(tmp<<1,n));
	}
}
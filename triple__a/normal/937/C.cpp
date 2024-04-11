#include "bits/stdc++.h"
using namespace std;

typedef long long LL;

int main(){
	LL k,d,t,T,ms,ans=0;
	bool fg=false;
	scanf("%lld%lld%lld",&k,&d,&t);
	ms=2*t;
	T=k+(d-k%d)%d;
	ans=(ms/(T+k))*T;
	ms=ms%(T+k);
	if (ms<=2*k){
		ans+=ms/2;
		fg=ms%2;
	}
	else{
		ans+=ms-k;
	}
	printf("%lld",ans);
	if (fg){
		printf(".5");
	}
	return 0;
}
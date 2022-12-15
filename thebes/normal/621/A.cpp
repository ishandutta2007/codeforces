#include <bits/stdc++.h>
using namespace std;

long long ans, N, i, s, x, mx = 1<<30;

int main(){
	for(scanf("%lld",&N),i=0;i<N;i++){
		scanf("%lld",&x);
		if(x%2==0) ans+=x;
		else{mx = min(mx,x); s++; ans+=x;}
	}
	printf("%lld\n",(s%2)?ans-mx:ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

long long N, s, i, x, y, w;

int main(){
	for(scanf("%lld",&N),i=0;i<N;i++){
		scanf("%lld",&x);
		s += x;
	}
	for(x=0,i=0;i<N;i++){
		scanf("%lld",&w);
		if(w > x){y=x; x=w;}
		else if(w > y)y=w;
	}
	printf("%s",(x+y>=s)?"YES":"NO");
	return 0;
}
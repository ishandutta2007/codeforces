#include <bits/stdc++.h>
using namespace std;

bitset<1000006> p;
int N, i; long long x, y;
void sieve(){
	p[1].flip();
	for(int i=2;i<=1000000;i++){
		if(p[i]) continue;
		for(int j=2*i;j<=1000000;j+=i)
			p[j] = 1;
	}
}

int main(){
	sieve();
	for(scanf("%d",&N);i<N;i++){
		scanf("%lld",&x);
		y = (int) sqrt(x+0.0);
		if(y*y == x) printf("%s\n",(p[y])?"NO":"YES");
		else printf("NO\n");
	}
	return 0;
}
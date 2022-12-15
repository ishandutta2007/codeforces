#include <bits/stdc++.h>
using namespace std;

long long a, b, n, m, x, y, t;

int main(){
	scanf("%lld%lld%lld%lld",&a,&b,&n,&m);
	t = a/b; x=(a-t*b)*m; y=((t+1)*b-a)*n;
	printf("%lld\n",min(x,y));
	return 0;
}
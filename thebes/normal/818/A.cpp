#include <bits/stdc++.h>
using namespace std;

long long n, m, a, b, c;

int main(){
	scanf("%lld%lld",&n,&m);
	a = n/2.0/(m+1);
	printf("%lld %lld %lld\n",a,a*m,n-a*(m+1));
	getchar(); getchar();
}
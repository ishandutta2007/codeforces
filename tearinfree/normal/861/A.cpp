#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef pair<int,int> ip;

lli a,b;
int main() {
	scanf("%lld%lld",&a,&b);

	lli m=1;
	for(int i=0;i<b;i++) m*=10;
	lli t=__gcd(m,a);
	t=a/t*m;
	
	printf("%lld\n",t);
	return 0;
}
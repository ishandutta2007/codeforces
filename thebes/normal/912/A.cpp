#include <bits/stdc++.h>
using namespace std;

long long x, y, z, A, B, a, b, c; 

int main(){
	scanf("%lld%lld%lld%lld%lld",&A,&B,&x,&y,&z);
	A -= 2*x; A -= y; B -= y; B -= 3*z;
	printf("%lld\n",-min(0LL,A)-min(0LL,B));
	return 0;
}
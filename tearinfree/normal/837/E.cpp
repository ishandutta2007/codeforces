#include <cstdio>
#include <vector>

using namespace std;
typedef long long lli;

vector<lli> div;

lli gcd(lli a,lli b) {
	while(b) {
		lli tmp=a%b; a=b;b=tmp;
	}
	return a;
}
lli f(lli a,lli b) {
	if(b==0) return 0;
	lli g=gcd(a,b);
	lli al=a/g, be=b/g;
	if(be==1) return 1;
	if(al==1) return be;

	lli mx=0;
	for(int i=2;i*i<=al&&i<=1000000;i++) {
		if(al%i==0) {
			mx=std::max(mx,i*(be/i));
			mx=std::max(mx,(al/i)*(be/(al/i)));
		}
	}
	mx=std::max(mx,al*(be/al));
	return f(a,mx*g)+(b-mx*g)/g;
}
int main() {
	lli a,b;
	scanf("%lld %lld",&a,&b);
	printf("%lld\n",f(a,b));
	return 0;
}
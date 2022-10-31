#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll s,x;

int main() {
	scanf("%lld%lld",&s,&x);
	ll has = 0;
	int num = 0;
	ll could = 0;
	for (int i=0;i<40;i++) {
		if (x&(1LL<<i)) {
			has+=1LL<<i;
			num+=1;
		} else {
			could+=1LL<<(i+1);
		}
	}
	if (has>s) return printf("0\n"), 0;
	has = s-has;
	if ((has&could)==has) {
		bool zero = 1;
		for (int i=0;i<40;i++) {
			if (has&(1LL<<(i+1))) zero = 0;
		}
		printf("%lld\n",(1LL<<num)-2*zero);
	} else return printf("0\n"), 0;

	return 0;
}
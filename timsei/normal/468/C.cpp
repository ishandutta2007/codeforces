#include <bits/stdc++.h>
using namespace std;

#define ll __int128

ll cxt = 1;
long long n, ret;

int main() {
	cin >> n;
	cxt = cxt * 10;
	cxt = cxt * (long long)(1e18);
	long long ret = 1, dog = 1e18;
	ret = ret + (ll)dog * 45 * 19 % n;
	ret = ret % n;
	if(ret == 0) {
		puts("1");
		putchar('1');
		for(int i = 1; i <= 19; ++ i) putchar('0');
		puts("");
		return 0;
	} else {
		printf("%lld\n", n - ret % n + 1);
		putchar('1');
		long long it = 1e18;
		for(int i = 18; i >= 0; -- i) {
			if(n - ret % n < it) {
				putchar('0');
			} else break;
			it = it / 10;
		}
		printf("%lld\n", n - ret % n);
	}
	
}
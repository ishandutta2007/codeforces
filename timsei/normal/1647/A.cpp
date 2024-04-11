#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
	for(cin >> t; t --;) {
		scanf("%d", &n);
		if(n == 1) {
			puts("1");
			continue;
		}
		if(n == 2) {
			puts("2");
			continue;
		}
		if(n % 3 == 0) {
			for(int i = 1; i <= n / 3; ++ i) printf("21");
			puts("");
			continue;
		}
		if(n % 3 == 1) {
			cout << 1;
			for(int i = 1; i <= n / 3; ++ i) printf("21");
			puts("");
		} else {
			putchar('2');
			for(int i = 1; i <= n / 3; ++ i) printf("12");
			puts("");
		}
	}
}
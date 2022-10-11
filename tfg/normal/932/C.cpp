#include <cstdio>
#include <iostream>

int main() {
	int n;
	int a, b;
	std::cin >> n >> a >> b;
	int freq[2];
	for(int i = 0; i * a <= n; i++) {
		int rest = n - i * a;
		if(rest % b == 0) {
			freq[0] = i;
			freq[1] = rest / b;
			break;
		}
		if((i + 1) * a > n) {
			std::cout << "-1\n";
			return 0;
		}
	}
	int c = 1;
	while(freq[0]--) {
		printf("%i%c", c + a - 1, c == n ? '\n' : ' ');
		for(int i = 0; i + 1 < a; i++) {
			printf("%i%c", c + i, c == n ? '\n' : ' ');
		}
		c += a;
	}
	a = b;
	while(freq[1]--) {
		printf("%i%c", c + a - 1, c == n ? '\n' : ' ');
		for(int i = 0; i + 1 < a; i++) {
			printf("%i%c", c + i, c == n ? '\n' : ' ');
		}
		c += a;
	}
}
#include<cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	while (true) {
		++n;
		if (n % 10 != n / 10 % 10 && n % 10 != n / 100 % 10 && n % 10 != n / 1000 && n / 10 % 10 != n / 100 % 10 && n / 10 % 10 != n / 1000 && n / 100 % 10 != n / 1000) {
			printf("%d\n", n);
			return 0;
		}
	}
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

using namespace std;

int main() {
	long long n;
	scanf("%I64d", &n);
	long long pow = 1;
	while (n % pow == 0) {
		pow *= 3;
	}
	printf("%I64d", n / pow + 1);
	return 0;
}
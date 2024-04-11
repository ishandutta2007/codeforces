#include <cstdio>
#include <string>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
// #include <isstream>
using namespace std;

int main() {
	int n, a = 0, b = 0;
	string S1, S2;
	scanf("%d", &n);
	while (n--) {
		cin >> S1 >> S2;
		if (S2 == "soft")
			a += 1;
		else
			b += 1;
	}
	for (int k = 1; k <= 100; k++) {
		if ((a <= (k * k / 2) && b <= ((k * k + 1) / 2)) || (b <= (k * k / 2) && a <= ((k * k + 1) / 2))) {
			printf("%d\n", k);
			return 0;
		}
	}
}
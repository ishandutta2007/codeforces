#include <bits/stdc++.h>
using namespace std;
char s[1000020];
int p = 1000000007, z, t = 1;
int main() {
	scanf("%s", s);
	for (int i = 0; s[i]; i++) {
		if (s[i] == 'a') {
			t = t * 2 % p;
		} else {
			z = (z + t - 1) % p;
		}
	}
	printf("%d\n", z);
	return 0;
}
#include<cstdio>
#include<iostream>
using namespace std;

int main() {
	long long a;
	int cnt = 0;
	cin >> a;
	while (a) {
		if (a % 10 == 4 || a % 10 == 7) ++ cnt;
		a /= 10;
	}
	if (cnt == 4 || cnt == 7) printf("YES\n"); else puts("NO");
	return 0;
}
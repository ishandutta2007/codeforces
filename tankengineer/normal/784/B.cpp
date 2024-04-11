#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int table[] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1, 1, 2, 0, 1, 0, 0};
int main() {
	int n;
	scanf("%d", &n);
	int ans = 0;
	if (n == 0) {
		++ans;
	}
	while (n) {
		ans += table[n % 16];
		n /= 16;
	}
	
	printf("%d\n", ans);
	return 0;
}
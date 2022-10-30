#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	char s[55];
	scanf("%d", &n);
	int x = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s);
		if (s[0] == '+' || s[1] == '+') ++x; else --x;
	}
	printf("%d\n", x);
	return 0;
}
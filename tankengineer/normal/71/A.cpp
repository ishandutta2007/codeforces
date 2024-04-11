#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		char s[105];
		scanf("%s", s);
		int l = strlen(s);
		if (l > 10) {
			printf("%c%d%c\n", s[0], l - 2, s[l - 1]);
		} else {
			printf("%s\n", s);
		}
	}
	return 0;
}
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	char s[505];
	scanf("%s", s);
	for (int i = 0; s[i]; ++i) {
		if (s[i] == 'H' || s[i] == 'Q' || s[i] == '9') {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
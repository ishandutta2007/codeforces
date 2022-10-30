#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	char s[105];
	scanf("%s", s);
	int ans = 0;
	for (int i = 0; s[i]; ++i) {
		++ans;
		for (int j = 0; j < i; ++j) {
			if (s[j] == s[i]) {
				--ans;
				break;
			}
		}
	}
	puts(ans % 2 ? "IGNORE HIM!" : "CHAT WITH HER!");
	return 0;
}
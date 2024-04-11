#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	char s[105];
	scanf("%s", s);
	int l = strlen(s);
	for (int i = 0; i < l; ++i) {
		for (int j = i + 1; j < l; ++j) {
			if (s[i] == '+' || s[j] == '+') {
				continue;
			}
			if (s[i] > s[j]) {
				swap(s[i], s[j]);
			}
		}
	}
	printf("%s\n", s);
	return 0;
}
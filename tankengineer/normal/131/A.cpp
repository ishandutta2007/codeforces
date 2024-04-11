#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

int l;
bool flag = false;
char s[105];

int main() {
	scanf("%s", s);
	l = strlen(s);
	for (int i = 1; i < l; ++i) {
		if (s[i] < 'A' || s[i] > 'Z') flag = true;
	}
	if (!flag) {
		for (int i = 0; i < l; ++i) {
			if (s[i] >= 'A' && s[i] <= 'Z') {
				s[i] = s[i] - 'A' + 'a';
			} else {
				s[i] = s[i] - 'a' + 'A';
			}
		}
	}
	printf("%s\n", s);
	return 0;
}
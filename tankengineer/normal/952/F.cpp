#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int gt(char *s) {
	int ret = (int)(*s) - '0';
	++s;
	while (*s != '+' && *s != '-' && *s != 0) {
		ret = ret * 10 + *s - '0';
		++s;
	}
	return ret;
}

int go(char *s) {
	if (*s == 0) {
		return 0;
	} else {
		int cur = 0, l = strlen(s);
		cur = gt(s);
		for (int i = 0; i < l; ++i) {
			if (s[i] == '+') {
				cur += gt(s + i);
			} else if (s[i] == '-') {
				cur -= gt(s + i);
			}
		}
		return cur;
	}
}

int main() {
	char s[105];
	scanf("%s", s);	
	printf("%d\n", go(s));
}
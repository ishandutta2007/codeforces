#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int L = 100005;

char s[L], t[L];

void canonicalize(char s[L]) {
	int l = strlen(s);
	reverse(s, s + l);
	for (int i = l; i < L; ++i) {
		s[i] = '0';
	}
	for (int i = L - 1; i - 2 >= 0; --i) {
		if (s[i] == '0' && s[i - 1] == '1' && s[i - 2] == '1') {
			s[i] = '1';
			s[i - 1] = '0';
			s[i - 2] = '0';
			for (int j = i; s[j] == '1' && s[j + 1] == '1' && j + 2 < L; j += 2) {
				s[j + 2] = '1';
				s[j] = '0';
				s[j + 1] = '0';
			}
		}
	}
}

int main() {
	scanf("%s%s", s, t);
	canonicalize(s);
	canonicalize(t);
	int ret = 0;
	for (int i = L - 1; i >= 0; --i) {
		if (s[i] != t[i]) {
			ret = s[i] < t[i] ? -1 : 1;
			break;
		}
	}
	printf("%c\n", ret ? (ret < 0 ? '<' : '>') : '=');
	return 0;
}
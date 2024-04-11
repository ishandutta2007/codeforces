#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char s1[55], s2[55];

int go(char ch1, char ch2) {
	if (ch1 == '8') {
		return 0;
	} else if (ch1 == '(') {
		return 1;
	} else {
		return 2;
	}
}


int main() {
	scanf("%s%s", s1, s2);
	int n = strlen(s1);
	int cnt = 0;
	for (int i = 0; i < n; i += 2) {
		int c1 = go(s1[i], s1[i + 1]),
			c2 = go(s2[i], s2[i + 1]);
		if (c1 == c2) {
			continue;
		}
		if (c2 == (c1 - 1 + 3) % 3) {
			++cnt;
		} else {
			--cnt;
		}
	}
	if (cnt > 0) {
		printf("TEAM 1 WINS\n");
	} else if (cnt == 0) {
		printf("TIE\n");
	} else {
		printf("TEAM 2 WINS\n");
	}
	return 0;
}
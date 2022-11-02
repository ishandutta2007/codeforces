#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int L = 100005;

char s[L];

int main() {
	scanf("%s", s);
	int l = strlen(s), ans = 0;
	for (int i = 0; i < l; ++i) {
		int d1 = ('@' < s[i]) && ('[' > s[i]),
			d2 = ('`' < s[i]) && ('{' > s[i]);
		int id = 0;
		if (s[i] >= 'a' && s[i] <= 'z') {
			id = s[i] - 'a' + 1;
		} else if (s[i] >= 'A' && s[i] <= 'Z') {
			id = s[i] - 'A' + 1;
		}
		ans += (id * d1) - (id * d2);
	}
	printf("%d\n", ans);
	return 0;
}
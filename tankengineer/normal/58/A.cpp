#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

void find(char *s, int &i, char ch) {
	int l = strlen(s);
	if (i >= l || i == -1) {
		i = -1;
		return;
	}
	while (i < l && s[i] != ch) ++i;
	if (i >= l) {
		i = -1;
	}
}

int main() {
	char s[105];
	scanf("%s", s);
	int i = 0;
	find(s, i, 'h');
	find(s, i, 'e');
	find(s, i, 'l');
	if (i != -1) find(s, ++i, 'l');
	find(s, i, 'o');
	puts(i == -1 ? "NO" : "YES");
	return 0;
}
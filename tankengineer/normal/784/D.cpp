#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;

char buf[11];

const int table[] = {8, -1, -1, 3, 6, 9, 4, 7, 0, 5};

int sym(int a) {
	return table[a];
}

int main() {
	scanf("%s", buf);
	int l = strlen(buf);
	for (int i = 0; i < l; ++i) {
		if (sym(buf[i] - '0') != (buf[l - i - 1] - '0')) {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}
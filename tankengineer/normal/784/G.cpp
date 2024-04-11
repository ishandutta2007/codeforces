#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

char buf[10000];

void printc(int num) {
	for (int i = 0; i < num; ++i) {
		putchar('+');
	}
	puts("++++++++++++++++++++++++++++++++++++++++++++++++.>");
}
int main() {
	int ans = 0;
	scanf("%s", buf);
	for (int i = 0, tmp = 0, lastop = 0; i <= strlen(buf); ++i) {
		if (buf[i] >= '0' && buf[i] <= '9') {
			tmp = tmp * 10 + (buf[i] - '0');
		} else {
			if (lastop) {
				ans -= tmp;
			} else {
				ans += tmp;
			}
			tmp = 0;
			if (buf[i] == '+') {
				lastop = 0;
			} else {
				lastop = 1;
			}
		}
	}
	if (ans >= 100) {
		printc(ans / 100);
	}
	if (ans >= 10) {
		printc(ans / 10 % 10);
	}
	printc(ans % 10);
	return 0;
}
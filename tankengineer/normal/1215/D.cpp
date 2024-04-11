#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

const int N = 2 * 100005;

int n;

char s[N];

int main() {
	scanf("%d%s", &n, s);
	n /= 2;
	int cnt = 0, sum = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '?') {
			++cnt;
		} else {
			sum += s[i] - '0';
		}
	}
	for (int i = n; i < 2 * n; ++i) {
		if (s[i] == '?') {
			--cnt;
		} else {
			sum -= s[i] - '0';
		}
	}
	if (sum % 9 == 0 && sum / 9 == -cnt / 2) {
		printf("Bicarp\n");
	} else {
		printf("Monocarp\n");
	}
	return 0;
}
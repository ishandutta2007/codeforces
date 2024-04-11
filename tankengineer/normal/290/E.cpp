#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000005;
char s[N];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	int cntq = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'Q') {
			++cntq;
		}
	}
	if (cntq == 0) {
		puts("Yes");
		return 0;
	}
	int numq = 0;
	while (numq * numq < cntq) {
		++numq;
	}
	if (cntq != numq * numq) {
		puts("No");
		return 0;
	}
	if ((n + numq) % (numq + 1) != 0) {
		puts("No");
		return 0;
	}
	int len = (n + numq) / (numq + 1);
	int sth = 0;
	while (s[sth] == 'H') {
		++sth;
	}
	if (sth % 2 != 0) {
		puts("No");
		return 0;
	}
	string prog, ans, ori(s);
	for (int i = 0; i < len; ++i) {
		prog += s[sth / 2 + i];
	}
	for (int i = 0; i < prog.size(); ++i) {
		if (prog[i] == 'H') {
			ans += 'H';
		} else {
			ans += prog;
		}
	}
	puts(ans == ori ? "Yes" : "No");
	return 0;
}
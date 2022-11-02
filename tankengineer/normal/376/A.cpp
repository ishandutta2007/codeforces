#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

string s;

int main() {
	cin >> s;
	long long left = 0, right = 0, sum = 0, len = 0;
	int i = 0;
	while (s[i] != '^') {
		if (s[i] != '=') {
			sum += s[i] - '0';
		}
		left += sum;
		++i;
	}
	++i;
	while (i < (int)s.size()) {
		++len;
		if (s[i] != '=') {
			right += len * (s[i] - '0');
		}
		++i;
	}
	if (left == right) {
		puts("balance");
	} else if (left < right) {
		puts("right");
	} else {
		puts("left");
	}
	return 0;
}
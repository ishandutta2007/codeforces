#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

int n, m;

char s[N];

long long cal1() {
	long long ret = 0;
	for (int i = 0; i + 1 < n; ++i) {
		if (s[i] != s[i + 1]) {
			ret += (long long)(m - 1) * (n - i - 1);
		}
	}
	return ret;
}

long long cal2() {
	long long ret = 0;
	for (int i = n - 1; i > 0; --i) {
		if (s[i] != s[i - 1]) {
			ret += (long long)(m - 1) * i;
		}
	}
	return ret;
}

long long cal3() {
	long long ret = 0, cur = 0, last = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (i + 2 < n && s[i] != s[i + 1] && s[i] == s[i + 2]) {
			cur = last + 1;
		} else if (i + 1 < n && s[i] != s[i + 1]) {
			cur = 2;
		} else {
			cur = 1;
		}
		last = cur;
		ret += cur - 1;
	}
	return ret;
}

long long cal0() {
	return n * (m - 1);
}

int main() {
	scanf("%d%d%s", &n, &m, s);
	cout << cal1() + cal2() - cal3() + cal0() << endl;
	return 0;
}
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int length(long long a) {
	int ret = 0;
	while (a) {
		a /= 10;
		++ret;
	}
	return ret;
}

long long power(long long l) {
	long long ret = 1;
	for (int i = 0; i < l; ++i) {
		ret *= 10;
	}
	return ret;
}

long long ans(long long w, long long m, long long k) {
	long long l = length(m), p = power(l);
	long long num = p - m, maxm = w / (l * k);
	long long t = min(num, maxm);
	w -= t * (l * k);
	long long ret = t;
	if (num < maxm) {
		ret += ans(w, p, k);
	}
	return ret;
}

int main() {
	long long w, m, k;
	cin >> w >> m >> k;
	cout << ans(w, m, k) << endl;
	return 0;
}
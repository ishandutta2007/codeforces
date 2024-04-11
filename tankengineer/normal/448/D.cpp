#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

long long n, m, k;

long long cal(long long a) {
	long long ret = 0;
	for (int i = 1; i <= n; ++i) {
		ret += min(a / i, m);
	}
	return ret;
}

int main() {
	cin >> n >> m >> k;
	long long l = 1, r = n * m + 1;
	while (l < r) {
		long long m = l + r >> 1;
		if (cal(m) < k) {
			l = m + 1;
		} else {
			r = m;
		}
	}
	cout << l << endl;
	return 0;
}
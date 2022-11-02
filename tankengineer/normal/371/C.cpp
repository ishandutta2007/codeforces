#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100 + 1;
char s[N];

long long cnt[3];

long long has[3], p[3], r;

bool check(long long k) {
	long long sum = 0;
	for (int i = 0; i < 3; ++i) {
		sum += max(0ll, cnt[i] * k - has[i]) * p[i];
	}
	return sum <= r;
}

int main() {
	scanf("%s", s);
	int l = strlen(s);
	for (int i = 0; i < l; ++i) {
		if (s[i] == 'B') {
			++cnt[0];
		} else if (s[i] == 'S') {
			++cnt[1];
		} else {
			++cnt[2];
		}
	}
	cin >> has[0] >> has[1] >> has[2];
	cin >> p[0] >> p[1] >> p[2];
	cin >> r;
	long long left = 0, right = 10000000000000ll;
	while (left < right) {
		long long mid = left + right + 1 >> 1;
		if (check(mid)) {
			left = mid;
		} else {
			right = mid - 1;
		}
	}
	cout << left << endl;
	return 0;
}
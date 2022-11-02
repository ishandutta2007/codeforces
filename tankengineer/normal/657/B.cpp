#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200005;

int n;

long long k;

long long a[N];

long long b[N];

const long long INF = 1ll << 60;

int main() {
	cin >> n >> k;
	long long left = 0;
	int first = -1, last = -1;;
	for (int i = 0; i <= n; ++i) {
		cin >> a[i];
		left += a[i];
		b[i] = left % 2;
		if (b[i]) {
			last = i;
		}
		if (b[i] && first == -1) {
			first = i;
		}
		left -= b[i];
		left /= 2;
	}
	if (left != 0) {
		b[n + 1] = left;
		last = n + 1;
		if (first == -1) {
			first = n;
		}
	}
	long long cur = 0;
	for (int i = last; i >= first; --i) {
		cur = cur * 2 + b[i];
		if (cur > INF || cur < -INF) {
			puts("0");
			return 0;
		}
	}
	long long ans = 0;
	for (int i = first; i >= 0; --i) {
		if (cur > INF || cur < -INF) {
			break;
		}
		if (a[i] - cur <= k && a[i] - cur >= -k) {
			++ans;
		}
		if (i == n && a[i] - cur == 0) {
			--ans;
		}
		cur = cur * 2;
	}
	cout << ans << endl;
	return 0;
}
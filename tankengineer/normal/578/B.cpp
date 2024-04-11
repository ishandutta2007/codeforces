#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200005;

long long n, k, x;

long long a[N], sum[N], sum1[N];

long long ans, pow;

int main() {
	cin >> n >> k >> x;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	pow = 1;
	for (int i = 0; i < k; ++i) {
		pow *= x;
	}
	sum[0] = 0;
	for (int i = 0; i < n; ++i) {
		sum[i + 1] = sum[i] | a[i];
	}
	sum1[n] = 0;
	for (int i = n - 1; i >= 0; --i) {
		sum1[i] = sum1[i + 1] | a[i];
	}
	ans = 0;
	for (int i = 0; i < n; ++i) {
		ans = max(ans, sum[i] | (a[i] * pow) | sum1[i + 1]);
	}
	cout << ans << endl;
	return 0;
}
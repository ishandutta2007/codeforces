#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 2000005 * 2;

long long n, ans, num[N], sum[N];

int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
	  cin >> num[i];
	}
	sort(num + 1, num + 1 + n);
	for (int i = 1; i <= n; ++i) {
	  sum[i] = num[n - i + 1] + sum[i - 1];
	}
	int t = 1;
	long long ans = 0;
	while (t <= n) {
	  ans += sum[t];
	  t <<= 2;
	}
	cout << ans << endl;
	return 0;
}
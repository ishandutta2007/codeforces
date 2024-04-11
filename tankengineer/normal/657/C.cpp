#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 200005;

int k, n, b, c;

int m;

int a[N];

int main() {
	scanf("%d%d%d%d", &n, &k, &b, &c);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		a[i] += 1000000000;
	}
	sort(a, a + n);
	reverse(a, a + n);
	long long ans = 1ll << 60;
	if (5 * c <= b) {
		long long sum = 0;
		for (int i = 0; i < k - 1; ++i) {
			sum += a[i];
		}
		for (int i = 0; i + k <= n; ++i) {
			sum += a[i + k - 1];
			ans = min(ans, ((long long)a[i] * k - sum) * c);
			sum -= a[i];
		}
	} else {
		reverse(a, a + n);
		for (m = 0; m < 5; ++m) {
			long long sum = 0;
			priority_queue<long long> heap;
			for (int i = 0; i < n; ++i) {
				int bb = a[i], d = (m + 5 - a[i] % 5) % 5;
				bb = (bb + d) / 5;
				long long cc = d * c - (long long)bb * b;
				heap.push(cc);
				sum += cc;
				while (heap.size() > k) {
					sum -= heap.top();
					heap.pop();
				}
				if (heap.size() == k) {
					ans = min(ans, sum + (long long)k * bb * b);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
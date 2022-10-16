#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int N = 100;

int n, k, a[N], d[N], sum, res;

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
		d[i%k] += a[i];
	}

	for(int i = 0; i < k; ++i)
		res = max(res, abs(sum - d[i]));
	cout << res;
}
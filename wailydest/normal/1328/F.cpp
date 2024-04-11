#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() 
{
	int n, k;
	scanf("%d%d", &n, &k);
	int arr[200000];
	for (int i = 0; i < n; ++i) scanf("%d", arr + i);
	sort(arr, arr + n);
	long long ans = LLONG_MAX;
	int same = 1;
	for (int i = 1; i < n; ++i) {
		if (arr[i] == arr[i - 1]) ++same;
		else {
			if (same >= k) ans = 0;
			same = 1;
		}
	}
	if (same >= k) ans = 0;
	long long sum = 0;
	int amt = 1;
	int i = 1, j;
	while (arr[i] == arr[0]) ++i;
	while (i < n) {
		sum += (long long)i * (arr[i] - arr[i - 1] - 1);
		amt = 1;
		j = i + 1;
		while (j < n && arr[j] == arr[i]) {
			++amt;
			++j;
		}
		if (j >= k) {
			ans = min(ans, max(k - amt + sum, (long long)0));
			break;
		}
		sum += i;
		i = j;
	}
	sum = 0;
	amt = 1;
	i  = n - 2;
	while (arr[i] == arr[n - 1]) --i;
	while (i >= 0) {
		sum += (long long)(n - i - 1) * (arr[i + 1] - arr[i] - 1);
		amt = 1;
		j = i - 1;
		while (j >= 0 && arr[j] == arr[i]) {
			++amt;
			--j;
		}
		if ((n - j - 1) >= k) {
			ans = min(ans, max(k - amt + sum, (long long)0));
			break;
		}
		sum += (n - i - 1);
		i = j;
	}
	if (k > n / 2 + 1) {
		sum = 0;
		int m = (n - 1) / 2;
		for (int i = 0; i < m; ++i) sum += arr[m] - arr[i];
		k -= m + 1;
		long long sum2 = 0;
		for (int i = n - 1; k > 0 && i > m; --i) {
			if (arr[i] != arr[m]) sum2 += arr[i] - arr[m] - 1;
			else --k;
		}
		ans = min(ans, k <= 0 ? sum : sum + sum2 + k);
	}
	printf("%lld\n", ans);
	return 0;
}
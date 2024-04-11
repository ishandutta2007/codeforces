#include <iostream>
#include <algorithm>
using namespace std;
long long n, r, avg, ans;
pair<long long, long long> a[100020];
int main() {
	cin >> n >> r >> avg;
	avg *= n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].second >> a[i].first;
		avg -= a[i].second;
		a[i].second = r - a[i].second;
	}
	sort(a, a + n);
	if (avg < 0) {
		avg = 0;
	}
	for (int i = 0; i < n; i++) {
		long long t = min(a[i].second, avg);
		avg -= t;
		ans += t * a[i].first;
	}
	cout << ans << endl;
	return 0;
}
#include <iostream>
#include <algorithm>
//#define int long long
#include <set>

using namespace std;

signed main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	multiset <int> now;
	pair <int, int> arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].second >> arr[i].first;
	}
	long long maxi = 0, s = 0;
	sort(arr, arr + n, greater <pair <int, int>>());
	for (int i = 0; i < n; i++) {
		if (now.size() < k) {
			s += arr[i].second;
			now.insert(arr[i].second);
		} else if (*now.begin() < arr[i].second) {
			s -= *now.begin();
			now.erase(now.begin());
			s += arr[i].second;
			now.insert(arr[i].second);
		}
		maxi = max(maxi, ((long long) arr[i].first) * s);
	}
	cout << maxi << endl;
	return 0;
}
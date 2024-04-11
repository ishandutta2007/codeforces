#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

pair<pair<int, int>, int> a[100020];
stack<pair<pair<int, int>, int> >s;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first.second >> a[i].first.first >> a[i].second;
	}
	sort(a, a + n);
	reverse(a, a + n);
	long long sum = 0;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		while (s.size() > 0 && s.top().first.second >= a[i].first.first) {
			sum -= s.top().second;
			s.pop();
		}
		s.push(a[i]);
		sum += s.top().second;
		if (ans < sum) {
			ans = sum;
		}
	}
	cout << ans << endl;
	return 0;
}
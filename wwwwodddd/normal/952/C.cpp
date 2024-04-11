#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
bool check() {
	for (int i = 1; i < a.size(); i++) {
		if (abs(a[i] - a[i - 1]) >= 2) {
			return false;
		}
	}
	return true;
}
int main() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	while (a.size() > 0) {
		if (!check()) {
			printf("NO\n");
			return 0;
		}
		a.erase(max_element(a.begin(), a.end()));
	}
	printf("YES\n");
	return 0;
}
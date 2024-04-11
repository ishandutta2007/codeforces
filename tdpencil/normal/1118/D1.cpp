#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> a;

bool can(int i) {
	long long sum = 0; // there can be a bug
	for (int j = 0; j < n; ++j) {
		sum += max(a[j] - j / i, 0);
	}
	return sum >= m;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n >> m;
	
	a = vector<int>(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a.rbegin(), a.rend());
	
	int l = 1, r = n;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (can(mid)) r = mid;
		else l = mid;
	}
	
	if (can(l)) cout << l << endl;
	else if (can(r)) cout << r << endl;
	else cout << -1 << endl;
	
	return 0;
}
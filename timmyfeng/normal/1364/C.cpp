#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<bool> cnt(n + 1);
	for (int i = 1; i <= n; ++i ){
		cin >> a[i];
		cnt[a[i]] = true;
	}
	
	int cur = 1;
	for (int i = 1; i <= n; ++i) {
		while (cnt[cur]) {
			++cur;
		}
		if (a[i] != a[i - 1]) {
			cout << a[i - 1] << ' ';
		} else {
			cout << cur++ << ' ';
		}
	}
	cout << '\n';
}
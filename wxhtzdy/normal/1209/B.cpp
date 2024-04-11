#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<bool> state(n);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		state[i] = (s[i] == '1' ? true : false);
		cnt += state[i] == true;
	}
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
	}
	for (int i = 1; i <= 10000; i++) {
		int tr = 0;
		for (int j = 0; j < n; j++) {
			if (b[j] <= i && (i == b[j] || (i - b[j]) % a[j] == 0)) {
				if (state[j] == false) {
					state[j] = true;
					tr++;
				} else {
					state[j] = false;
				}
			} else {
				if (state[j] == true) {
					tr++;
				} 
			}
		}
		cnt = max(tr, cnt);
	}
	cout << cnt;
	return 0;
}
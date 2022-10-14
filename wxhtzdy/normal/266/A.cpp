#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int k;
		for (int j = i; j < n; j++) {
			if (s[i] == s[j]) {
				k = j;
			} else {
				break;
			}
		}
		ans += k - i;
		i = k;
	}
	cout << ans;
}
#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int n = s.size();

	string ans;

	int i = 0;
	int j = n - 1;
	while (i + 1 < j - 1) {
		for (int k = 0; k < 2; ++k) {
			for (int l = 0; l < 2; ++l) {
				if (s[i + k] == s[j - l]) {
					ans += s[i + k];
					goto done;
				}
			}
		} done:

		i += 2;
		j -= 2;
	}

	cout << ans;
	if (i <= j) {
		cout << s[i];
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
}
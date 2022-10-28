#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	while (n--) {
		int l;
		string s;
		cin >> l >> s;

		string ans;
		int i = 0;
		while (i < l && s[i] == '0') {
			ans += s[i];
			++i;
		}
		int j = l - 1;
		while (j >= 0 && s[j] == '1') {
			ans += s[j];
			--j;
		}

		if (i < j) {
			ans = '0' + ans;
		}
		cout << ans << "\n";
	}
}
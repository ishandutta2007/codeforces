#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	string s;
	cin >> n >> s;

	string ans = "";
	string vow = "aeiouy";
	for (int i = 0; i < n; ++i) {
		ans += s[i];
		if (count(vow.begin(), vow.end(), s[i])) {
			while (i + 1 < n && count(vow.begin(), vow.end(), s[i + 1])) {
				++i;
			}
		}
	}
	cout << ans << '\n';
}
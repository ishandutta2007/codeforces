#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);
	int n, k;
	string s;
	cin >> n >> k >> s;
	int ava = 0;
	while (k--) {
		char a;
		cin >> a;
		ava |= 1 << (a - 'a');
	}
	
	long long len = 0, ans = 0;
	for (auto i : s) {
		if (ava & (1 << (i - 'a'))) {
			++len;
		} else {
			ans += len * (len + 1) / 2;
			len = 0;
		}
	}
	ans += len * (len + 1) / 2;
	cout << ans << '\n';
}
#include <bits/stdc++.h> 
using namespace std;

string ans, a, b;
int cnt[10];
bool ok;

void dfs(int ndx, bool lesser) {
	if (ndx == (int)a.size()) {
		cout << ans << '\n';
		ok = true;
	}
	for (char c = lesser ? '9' : b[ndx]; c >= '0' && !ok; --c) {
		if (!cnt[c - '0'])
			continue;
		--cnt[c - '0'];
		ans += c;
		dfs(ndx + 1, lesser || c < b[ndx]);
		ans.pop_back();
		++cnt[c - '0'];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	if (a.size() < b.size()) {
		sort(a.begin(), a.end(), greater<char>());
		cout << a << '\n';
		return 0;
	}

	for (auto i : a) {
		++cnt[i - '0'];
	}

	dfs(0, false);
}
#include <bits/stdc++.h> 
using namespace std;

const int MX = 100 + 1;

vector<int> pos[MX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int s;
		cin >> s;
		pos[s].push_back(i);
	}

	int cnt = 0;
	string ans(n, 'A');
	for (int i = 1; i < MX; ++i) {
		if (pos[i].size() == 1u) {
			ans[pos[i][0]] = 'A' + cnt % 2;
			++cnt;
		}
	}

	if (cnt % 2) {
		int ndx = 0;
		while (ndx < MX && pos[ndx].size() <= 2u) {
			++ndx;	
		}
		if (ndx < MX) {
			ans[pos[ndx][0]] = 'B';
		} else {
			cout << "NO" << '\n';
			return 0;
		}
	}
	cout << "YES" << '\n';
	cout << ans << '\n';
}
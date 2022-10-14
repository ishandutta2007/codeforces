#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		int len = s.length();
		int n;
		cin >> n;
		vector<int> a(n);
		int cnt = n;
		vector<int> count(26, 0);
		for (int i = 0; i < len; i++) {
			count[(int)(s[i] - 'a')]++;
		}
		vector<bool> was(n, false);
		char answer[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int j = 26;
		while (cnt > 0) {
			int tr = 0;
			vector<int> ind;
			for (int i = 0; i < n; i++) {
				if (a[i] == 0 && was[i] == false) {
					ind.push_back(i);
					was[i] = true;
					tr++;
					cnt--;
				}
			}
			j--;
			while (j >= 0 && count[j] < tr) {
				j--;
			}
			for (int i = 0; i < n; i++) {
				if (a[i] == 0) {
					continue;
				}
				for (int r = 0; r < (int)ind.size(); r++) {
					a[i] -= abs(i - ind[r]);
				}
			}
			for (int i = 0; i < (int)ind.size(); i++) {
				answer[ind[i]] = (char)(j + 'a');
			}
		}
		for (int i = 0; i < n; i++) {
			cout << answer[i];
		}
		cout << endl;
	}
	return 0;
}
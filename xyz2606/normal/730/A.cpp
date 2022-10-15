#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int a[N], A[N];
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int M = 101;
	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
		A[i] = a[i];
		M = min(M, a[i]);
	}
	int cnt = 0;
	for (int i = 1; i <= n; ++ i) {
		cnt += a[i] - M;
	}
	if (cnt == 0) {
		cout << M << endl << 0 << endl;
		return 0;
	}
	vector<string> ans;
	//int cntc = 0;
	while (*max_element(a + 1, a + 1 + n) > M) {
		/*if (++ cntc > 20) break;
		cout << M << endl;
		for (int i = 1; i <= n; ++ i) cout << a[i] << " "; cout << endl;*/
		vector<pair<int, int>> tot;
		for (int i = 1; i <= n; ++ i) if (a[i] > M || (M == 0 && a[i] == 0)) {
			tot.push_back(make_pair(a[i] - M, i));
		}
		sort(tot.begin(), tot.end(), greater<pair<int, int>>());
		if (tot.size() == 1) {
			if (ans.empty() || ans.back()[tot[0].second - 1] == '1') {
				M --;
				continue;
			}
			else {
				ans.back()[tot[0].second - 1] = '1';
				a[tot[0].second] --;
				if (a[tot[0].second] < 0) a[tot[0].second] = 0;
			}
		}
		else {
			string s = "";
			for (int i = 1; i <= n; ++ i) {
				if (i == tot[0].second || i == tot[1].second) s += '1'; else s += '0';
			}
			a[tot[0].second] --;
			a[tot[1].second] --;
			if (a[tot[0].second] < 0) a[tot[0].second] = 0;
			if (a[tot[1].second] < 0) a[tot[1].second] = 0;
			ans.push_back(s);
		}
	}
	cout << M << endl << ans.size() << endl;
	for (string &s : ans) {
		cout << s << endl;
		for (int i = 0; i < n; ++ i) if (s[i] == '1') {
			A[i + 1] --;
			A[i + 1] = max(0, A[i + 1]);
		}
	}
	for (int i = 1; i <= n; ++ i) assert(A[i] == A[1]);
}
#include <bits/stdc++.h> 
using namespace std;

vector<string> qry(int n) {
	vector<string> res(n * (n + 1) / 2);
	cout << "? " << 1 << ' ' << n << endl;
	for (auto& i : res) {
		cin >> i;
		sort(i.begin(), i.end());
	}
	sort(res.begin(), res.end());
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	if (n == 1) {
		string ans = qry(n)[0];
		cout << "! " << ans << endl;
		return 0;
	}

	vector<string> qry1 = qry(n);
	vector<string> qry2 = qry(n - 1);
	vector<string> suf(n);
	set_symmetric_difference(qry1.begin(), qry1.end(), qry2.begin(), qry2.end(), suf.begin());
	sort(suf.begin(), suf.end(), [](const string& a, const string& b) {
		return a.size() < b.size();
	});

	string ans = suf[0];
	for (int i = 1; i < n; ++i) {
		set_symmetric_difference(suf[i].begin(), suf[i].end(), suf[i - 1].begin(), suf[i - 1].end(), back_inserter(ans));
	}
	reverse(ans.begin(), ans.end());
	cout << "! " << ans << endl;
}
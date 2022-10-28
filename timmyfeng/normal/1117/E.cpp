#include <bits/stdc++.h>
using namespace std;

const int AL = 26;

template <typename F>
string qry(int n, F f) {
	cout << "? ";
	for (int i = 0; i < n; ++i) {
		cout << f(i);
	}
	cout << endl;
	string res;
	cin >> res;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string t;
	cin >> t;
	int n = t.size();

	string s1 = qry(n, [](int i) {
		return (char)('a' + i / (AL * AL));
	});
	string s2 = qry(n, [](int i) {
		return (char)('a' + i / AL % AL);
	});
	string s3 = qry(n, [](int i) {
		return (char)('a' + i % AL);
	});

	string ans(n, 0);
	for (int i = 0; i < n; ++i) {
		int ndx = (s1[i] - 'a') * AL * AL + (s2[i] - 'a') * AL + (s3[i] - 'a');
		ans[ndx] = t[i];
	}
	cout << "! " << ans << '\n';
}
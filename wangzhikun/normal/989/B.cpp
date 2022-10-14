#include <bits/stdc++.h>
#define endl '\n'
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define finish(x) return cout << x << endl, 0
using namespace std;

string s, t;
int n, p;

bool isperiod() {
	for (int i = p; i < n; i++)
		if (t[i] != t[i - p]) return false;
	return true;
}

int main() {
	fast;
	cin >> n >> p >> s;

	t = s;
	for (auto &i : t)
		if (i == '.') i = '0';
	if (!isperiod()) finish(t);

	// attempt 2
	int i = 0;
	while (i < n && s[i] != '.') i++;
	if (i + p < n) {
		t[i] = '1';
		finish(t);
	}
	i = n - 1;
	while (i >= 0 && s[i] != '.') i--;
	if (i - p >= 0) {
		t[i] = '1';
		finish(t);
	}

	finish("No");
}
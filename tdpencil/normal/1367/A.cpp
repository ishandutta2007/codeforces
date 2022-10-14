#include <bits/stdc++.h>
using namespace std;

void solve() {
	string s;
	cin >> s;

	string t;
	t += s[0];
	for(int i=1; i < s.size() - 1; i+=2) {
		t += s[i];
	}

	t += s[int(s.size()) - 1];

	cout <<t << '\n';
}
int main() {
	int t;
	cin >> t;

	while(t--)
		solve();
}
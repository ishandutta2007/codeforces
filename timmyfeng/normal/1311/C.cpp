#include <bits/stdc++.h>
using namespace std;

int freq[26];
int ps[200001];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		memset(ps, 0, sizeof ps);
		memset(freq, 0, sizeof freq);
		int n, m;
		string s;
		cin >> n >> m >> s;
		while (m--) {
			int a;
			cin >> a;
			++ps[a];
		}
		++ps[n];
		for (int i = n - 1; i; --i) {
			ps[i] += ps[i + 1];
		}

		for (int i = 0; i < n; ++i) {
			freq[s[i] - 'a'] += ps[i + 1];
		}
		for (int i = 0; i < 26; ++i) {
			cout << freq[i] << ' ';
		}
		cout << '\n';
	}
}
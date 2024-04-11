#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
		string s; cin >> s;
		int p; cin >> p;

		int sum = 0;
		for (auto c : s) {
			sum += c - 'a' + 1;
		}

		vector<bool> deleted(s.size(), false);
		for (char c = 'z'; c >= 'a'; --c) {
			for (int i = s.size() - 1; i >= 0; --i) {
				if (s[i] == c && sum > p) {
					sum -= c - 'a' + 1;
					deleted[i] = true;
				}
			}
		}

		string answer;
		for (int i = 0; i < (int) s.size(); ++i) {
			if (!deleted[i]) answer += s[i];
		}

		cout << answer << "\n";
    }
}
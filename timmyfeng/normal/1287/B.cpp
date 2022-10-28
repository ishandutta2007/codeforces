#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	set<string> s;
	vector<string> cards(n);
	for (auto &i : cards) {
		cin >> i;
		s.insert(i);
	}

	long long sol = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			string tgt = cards[i];
			for (int l = 0; l < k; l++) {
				if (cards[j][l] != cards[i][l]) {
					tgt[l] = 'S' + 'E' + 'T' - cards[j][l] - cards[i][l];
				}
			}
			sol += s.count(tgt);
		}
	}
	cout << sol / 3 << "\n";
}
#include <bits/stdc++.h>
using namespace std;

int pos[10];

void play(const vector<int>& a) {
	cout << "next";
	for (auto i : a) {
		cout << " " << i;
	}
	cout << endl;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (auto j : s) {
			pos[j - '0'] = i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	do {
		play({0, 1});
		play({1});
	} while (pos[0] != pos[1]);

	while (pos[0] != pos[2]) {
		play({0, 1, 2, 3, 4, 5, 6, 7, 8, 9});
	}

	cout << "done" << endl;
}
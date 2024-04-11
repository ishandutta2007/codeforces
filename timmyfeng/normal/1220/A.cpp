#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;

	int zero = count(s.begin(), s.end(), 'z');
	int one = count(s.begin(), s.end(), 'n');

	for (int i = 0; i < one; ++i) {
		cout << 1 << " ";
	}
	for (int i = 0; i < zero; ++i) {
		cout << 0 << " " ;
	}
	cout << "\n";
}
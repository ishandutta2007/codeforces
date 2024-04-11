#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		string s;
		cin >> n >> s;
		int calc_left = 0, calc_right = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '<') calc_left++;
			else break;
		}
		for (int i = n - 1; i >= 0; i--) {
			if (s[i] == '>') calc_right++;
			else break;
		}
		cout << min(calc_left, calc_right) << endl;
	}
	return 0;
}
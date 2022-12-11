#include <iostream>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if (n == k) {
		for (int i = 0; i < n; i++) cout << "0";
		return 0;
	}
	string s = "";
	s.resize(n);
	for (int i = 0; i < (int) s.length(); i++) s[i] = '0';
	int rest = (n - k) / 2;
	s[k + rest - 1] = '1';
	rest++;
	for (int i = k - 1; i >= 0; i--) {
		s[i] = s[i + rest];
	}
	cout << s << endl;
	return 0;
}
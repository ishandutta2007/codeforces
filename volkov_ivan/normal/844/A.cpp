#include <iostream>
#include <set>

using namespace std;

int main() {
	string s;
	int k;
	cin >> s >> k;
	if (s.size() < k) {
		cout << "impossible" << endl;
		return 0;
	}
	set <char> chars;
	for (int i = 0; i < s.size(); i++) {
		chars.insert(s[i]);
	}
	cout << max(0, int(k - chars.size())) << endl;
	return 0;
}
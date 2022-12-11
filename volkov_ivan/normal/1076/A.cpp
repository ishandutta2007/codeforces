#include <iostream>

using namespace std;

int main() {
	//freopen("/Users/ivanvolkov/Desktop/inp.in", "r", stdin);
	int n;
	cin >> n;
	string s;
	cin >> s;
	bool flag = 0;
	for (int i = 0; i < s.length(); i++) {
		if (!flag && i == (int) s.length() - 1) break;
		if (!flag && s[i + 1] < s[i]) {
			flag = 1;
		} else {
			cout << s[i];
		}
	}
	cout << endl;
	return 0;
}
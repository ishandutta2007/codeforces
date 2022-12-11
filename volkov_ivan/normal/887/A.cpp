#include <iostream>

using namespace std;

int main() {
	char c;
	bool poss = 0;
	int cnt = 0;
	while (cin >> c) {
		//if (c == 'z') break;
		if (c == '1') {
			poss = 1;
		} else {
			if (poss) {
				cnt++;
			}
		}
	}
	cout << ((cnt >= 6) ? "YES" : "NO") << endl;
	return 0;
}
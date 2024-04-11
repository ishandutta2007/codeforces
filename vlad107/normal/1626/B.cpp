#include <iostream>
#include <string>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		int posBig = -1;
		int posSmall = -1;
		for (int i = 0; i + 1 < s.size(); i++) {
			int u = s[i] - '0';
			int v = s[i + 1] - '0';
			if (u + v >= 10) {
				posBig = i;
			} else if ((v != 0) && (posSmall == -1)) {
				posSmall = i;
			}
		}
		if (posBig != -1) {
			int u = (s[posBig] - '0') + (s[posBig + 1] - '0');
			s[posBig] = char(u / 10 + '0');
			s[posBig + 1] = char(u % 10 + '0');
			cout << s << "\n";
		} else {
			if (posSmall == -1) posSmall = (int)s.size() - 2;
			int u = (s[posSmall] - '0') + (s[posSmall + 1] - '0');
			s[posSmall] = char(u + '0');
			s.erase(posSmall + 1, 1);
			cout << s << "\n";
		}
	}
	return 0;
}
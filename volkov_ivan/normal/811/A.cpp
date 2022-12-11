#include <iostream>

using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	long long cnt = 1;
	while (true) {
		if (a < cnt) {
			cout << "Vladik" << endl;
			return 0;
		}
		if (b <= cnt) {
			cout << "Valera" << endl;
			return 0;
		}
		a -= cnt;
		b -= (cnt + 1);
		cnt += 2;
	}
}
#include <iostream>
#include <math.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	int now = 0, s, d, m;
	for (int i = 0; i < n; i++) {
		cin >> s >> d;
		if (s > now) {
			now = s;
			continue;
		}
		if ((now - s) % d == 0) {
			now = s + ((now - s) / d + 1) * d;
		} else {
			now = s + ceil(double(now - s) / d) * d;
		}
	}
	cout << now << endl;
	return 0;
}
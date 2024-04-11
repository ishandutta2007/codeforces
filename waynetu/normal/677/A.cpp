#include <iostream>
using namespace std;

int main() {
	int n, h, a;
	int w = 0;
	cin >> n >> h;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		if (a > h) {
			w += 2;
		} else {
			w++;
		}
	}
	cout << w << endl;
	return 0;
}
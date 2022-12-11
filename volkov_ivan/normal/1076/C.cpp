#include <iostream>
#include <cmath>

using namespace std;

int main() {
	//freopen("/Users/ivanvolkov/Desktop/inp.in", "r", stdin);
	int t;
	cin >> t;
	cout.precision(15);
	for (int i = 0; i < t; i++) {
		int d;
		cin >> d;
		int D = d * d - 4 * d;
		if (D < 0) {
			cout << "N" << endl;
			continue;
		}
		long double x = (d + sqrt(D)) / 2;
		cout << fixed << "Y " << x << ' ' << d - x << endl;
	}
	return 0;
}
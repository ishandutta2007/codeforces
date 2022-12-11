#include <iostream>
#include <cmath>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, x, y, d;
		cin >> n >> x >> y >> d;
		if ((x - y) % d == 0) {
			cout << abs((x - y) / d) << endl;
			continue;
		} 
		int v = INF;
		if ((y - 1) % d == 0) v = min(v, (int) ceil(((long double) (x - 1)) / d) + (y - 1) / d);
		if ((n - y) % d == 0) v = min(v, (int) ceil(((long double) (n - x)) / d) + (n - y) / d);
		if (v != INF) cout << v << endl;
		else cout << "-1" << endl;
	}
	return 0;
}
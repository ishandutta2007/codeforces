#include <iostream>

using namespace std;

int main() {
	long long test;
	cin >> test;
	for (int i = 0; i < test; i++) {
	long long s, a, b, c;
	cin >> s >> a >> b >> c;
	long long t = s / c;
	long long ans = t + (t / a) * b;
	cout << ans << endl;
	}
	return 0;
}
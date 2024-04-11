#include <iostream>
using namespace std;
long long n, x, z = 1;
int main() {
	cin >> n >> x;
	while (x % 2 == 0) {
		x /= 2;
		z++;
	}
	cout << z << endl;
	return 0;
}
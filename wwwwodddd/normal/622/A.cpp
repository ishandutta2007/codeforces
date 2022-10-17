#include <iostream>
using namespace std;
long long n;
int main() {
	cin >> n;
	n--;
	for (int i = 0; i <= n; i++) {
		n -= i;
	}
	cout << n + 1;
}
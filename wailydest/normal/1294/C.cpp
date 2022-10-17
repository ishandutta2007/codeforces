#include <iostream>
#include <cmath>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	int n, a;
	int i;
	while (t--) {
		cin >> n;
		a = 1;
		for (i = 2; i <= sqrt(n) && n % i; ++i);
		if (!(n % i)) {
			a = i;
			n /= a;
			for (i = 2; (i < sqrt(n) && n % i) || i == a || a == n / i; ++i);
			if (!(n % i) && (1 != ((n /= i), n)) && i != n) {
				cout << "YES\n" << a << ' ' << i << ' ' << n << '\n';
				continue;
			}
		}
		cout << "NO\n";
	}
	return 0;
}
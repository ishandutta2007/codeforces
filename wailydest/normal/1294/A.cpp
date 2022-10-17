#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	
	int a, b, c, n;
	while (t--) {
		cin >> a >> b >> c >> n;
		if (b < c) swap(b, c);
		if (a < b) swap(a, b);
		n -= a - b + a - c;
		if (n % 3 || n < 0) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}
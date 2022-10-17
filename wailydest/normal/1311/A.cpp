#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	
	int a, b;
	while (t--) {
		cin >> a >> b;
		if (a == b) cout << 0;
		else if (a > b) {
			if (a % 2 == b % 2) cout << 1;
			else cout << 2;
		}
		else if (a < b) {
			if (a % 2 != b % 2) cout << 1;
			else cout << 2;
		}
		cout << '\n';
	}
	return 0;
}
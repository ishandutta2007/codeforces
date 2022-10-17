#include <iostream>
using namespace std;

int main() 
{
	int t, n, current;
	
	cin >> t;
	bool haseven, hasodd;
	while (t--) {
		haseven = hasodd = false;
		cin >> n;
		for (int i = 0; i < n; ++i) {
			cin >> current;
			if (current % 2) hasodd = true;
			else haseven = true;
		}
		if (hasodd && (haseven || n % 2)) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
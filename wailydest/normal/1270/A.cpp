#include <iostream>
using namespace std;

int main() 
{
	int t, n, k1, k2, num;
	bool is_yes;
	cin >> t;
	while (t--) {
		is_yes = false;
		cin >> n >> k1 >> k2;
		while (k1--) {
			cin >> num;
			if (num == n) {
				cout << "YES\n";
				is_yes = true;
			}
		}
		while (k2--) cin >> num;
		if (!is_yes) {
			cout << "NO\n";
		}
	}
	return 0;
}
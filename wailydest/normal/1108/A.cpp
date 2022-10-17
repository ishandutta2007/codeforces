#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	int l1, l2, r1, r2;
	while (t--) {
		cin >> l1 >> r1 >> l2 >> r2;
		cout << l1 << ' ' << (l2 == l1 ? r2 : l2) << '\n';
	}
	return 0;
}
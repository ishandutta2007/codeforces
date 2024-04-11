#include <iostream>
using namespace std;

int main() 
{
	int t;
	cin >> t;
	
	int n;
	int arr[100];
	int x;
	bool isfalse;
	while (t--) {
		isfalse = false;
		cin >> n;
		cin >> x;
		int mod2 = x % 2;
		while (--n) {
			cin >> x;
			if (x % 2 != mod2) isfalse = true;
		}
		if (isfalse) cout << "NO";
		else cout << "YES";
		cout << '\n';
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {              
		int n;
		cin >> n;   
		int x = n / 2;
		if (n % 2 == 0) {
		 	x--;
		}
		cout << x << endl;
	}	
}
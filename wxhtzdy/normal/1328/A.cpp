#include <bits/stdc++.h>

using namespace std;

int main () {
 	int tt;
 	cin >> tt;
 	while (tt--) {
 	 	int a, b;
 	 	cin >> a >> b;
 	 	int x = b - a % b;
 	 	if (x == b) {
 	 	 	x = 0;
 	 	}
 	 	cout << x << endl;
 	}
}
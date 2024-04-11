#include <bits/stdc++.h>

using namespace std;

int main() {      
	int n;
	cin >> n;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
	 	int x, y;
	 	cin >> x >> y;
		if (x > y) {
			a++;
		} else {
		 	if (x < y) {
		 	 	b++;
		 	}
		}
	}
	if (a > b) {
		cout << "Mishka";
	} else {
	 	if (a < b) {
	 	 	cout << "Chris";
	 	} else {
	 	 	cout << "Friendship is magic!^^";
	 	}
	}
}
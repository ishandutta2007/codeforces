#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	bool ok = false;
	for (int i = 0; i < n; i++) {
	 	int x;
	 	cin >> x;
	 	if (x == 1) {
	 	 	ok = true;
	 	}
	}
	if (ok == true) {
	  cout << "HARD";
	} else {
	  cout << "EASY";
	}
}
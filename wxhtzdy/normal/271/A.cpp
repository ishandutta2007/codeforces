#include <bits/stdc++.h>

using namespace std;

bool ok(int n) {
	vector<int> cnt(10, 0);
	while (n > 0) {
		cnt[n % 10]++;
		n /= 10; 	
	}
	for (int i = 0; i < 10; i++) {
	 	if (cnt[i] > 1) {
	 	 	return false;
	 	}
	}
	return true;
}

int main() {
 	int n;
 	cin >> n;
 	n++;
 	while (ok(n) == false) {
 	 	n++;
 	}   
 	cout << n;
}
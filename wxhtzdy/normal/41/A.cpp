#include <bits/stdc++.h>

using namespace std;

int main() {
 	string a, b;
 	cin >> a >> b;
 	int n = (int) a.length(), m = (int) b.length();
 	if (n != m) {
 	 	cout << "NO";
 	 	return 0;
 	}
 	bool ok = true;
 	for (int i = 0; i < n; i++) {
 	 	if (a[i] != b[n - i - 1]) {
 	 	  ok = false;
 	 	}
 	}
 	if (ok == false) {
 	 	cout << "NO";
  }	else {
   	cout << "YES";
  }
}
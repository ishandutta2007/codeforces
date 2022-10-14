#include <bits/stdc++.h>

using namespace std;

int main() { 
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a = 0, b = 0;
	for (int i = 0; i < n; i++) {
	 	if (s[i] == 'L') {
	 	 	a++;
	 	} else {
	 	 	b++;
	 	}
	}
	cout << a + b + 1;
}
#include <bits/stdc++.h>

using namespace std;

int main() { 
	int n;
	cin >> n;   
	string s;
	cin >> s;
	map<int, int> m;
	for (int i = 0; i < n; i++) {
		int x = (int) s[i];
		if (s[i] < 'a') {
		 	x += (int) ('a' - 'A');
		}
		m[x]++;
	}
	bool ok = true;
	for (int i = 0; i < 26; i++) {
	 	if (m[i + (int) 'a'] == 0) {
	 		ok = false; 	
	 	}
	}
	cout << (ok ? "YES" : "NO");	
}
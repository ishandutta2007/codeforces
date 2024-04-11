#include <bits/stdc++.h>

using namespace std;

int main() {                                      
	int tt;
	cin >> tt;
	while (tt--) {
	 	string s;
	 	cin >> s;
	 	int n = (int) s.length();
	 	int res = 0;
	 	vector<bool> was(n, false);
	 	for (int i = 0; i < n - 2; i++) {
	 	 	if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o') {
	 	 		res++;
	 	 		was[i + 1] = true;
	 	  }	
	 	}
	 	for (int i = 0; i < n - 2; i++) {
	 	 	if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') {
	 	 		res++;
	 	 		was[i + 1] = true;
	 	  }	
	 	}
	 	for (int i = 0; i < n - 4; i++) {
	 	 	if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' && s[i + 3] == 'n' && s[i + 4] == 'e') {
	 	 	 	res--;
	 	 	 	was[i + 1] = false;
	 	 	 	was[i + 3] = false;
	 	 	 	was[i + 2] = true;
	 	 	}
	 	}
	 	cout << res << endl;
	 	for (int i = 0; i < n; i++) {
	 		if (was[i] == true) {
	 		 	cout << i + 1 << " ";
	 		}
	 	}
	 	cout << endl;
	}
}
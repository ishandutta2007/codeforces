#include <bits/stdc++.h>

using namespace std;

int main() {                 
	string s;
	getline(cin, s);
	int cnt = 0;
	vector<bool> was(26, false);
	for (int i = 0; i < (int) s.length(); i++) {
	 	if (s[i] < 'a' || s[i] > 'z') {
	 	 	continue;
	 	}
	 	int x = (int) (s[i] - 'a');
	 	if (was[x] == false) {   	
	 	 	cnt++;
	 	 	was[x] = true;
	 	}
	}
	cout << cnt;
}
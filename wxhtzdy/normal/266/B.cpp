#include <bits/stdc++.h>

using namespace std;

int main() {
 	int n, x;
 	cin >> n >> x;
 	string s;
 	cin >> s;
 	while (x--) {
 		for (int i = 0; i < n - 1; i++) {
	 	  if (s[i] == 'B' && s[i + 1] == 'G') {
	 	   swap(s[i], s[i + 1]);
	 	   i++;
	 	  }
 		}
 	}	
 	cout << s << endl;
}
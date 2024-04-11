#include <bits/stdc++.h>

using namespace std;

int main() {
 	string s;
 	cin >> s;
 	int cnt = 0;
 	for (int i = 0; i < (int) s.length(); i++) {
 	 	if (s[i] < 'a') {
 	 	 	cnt++;
 	 	}
 	}
 	if (cnt > (int) s.length() - cnt) {
 	 	for (int i = 0; i < (int) s.length(); i++) {
 	 	 	if (s[i] >= 'a') {
 	 	 	 s[i] -= ('a' - 'A');
 	 	 	}
 	 	}
 	} else {
 	  for (int i = 0; i < (int) s.length(); i++) {
 	   	if (s[i] < 'a') {
 	   	 	s[i] += ('a' - 'A');
 	   	}
 	  }
 	}
 	cout << s;
}
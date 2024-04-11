#include <bits/stdc++.h>

using namespace std;

int main () {
 	int tt;
 	cin >> tt;
 	while (tt--) {
 		string s;
 		cin >> s;
 		int n = (int) s.length();         
 		vector<int> cnt(3, 0);
 		for (int i = 0; i < n; i++) {
 		 	if (s[i] == 'R') {
 		 	 	cnt[0]++;
 		 	} else {
 		 	  if (s[i] == 'P') {
 		 	   	cnt[1]++;
 		 	  } else {
 		 	   	cnt[2]++;
 		 	  }
 		 	}	
 		}
 		if (cnt[0] >= cnt[1] && cnt[0] >= cnt[2]) {
 		 	for (int i = 0; i < n; i++) {
 		 		cout << 'P';
 		 	}
 		} else {
 		 	if (cnt[1] >= cnt[0] && cnt[1] >= cnt[2]) {
 		 	 	for (int i = 0; i < n; i++) {
 		 	 	 	cout << 'S';
 		 	 	}
 		 	} else {
 		 	 	for (int i = 0; i < n; i++) {
 		 	 		cout << 'R';
 		 	 	}
 		 	}
 		}
 		cout << '\n';
 	}
}
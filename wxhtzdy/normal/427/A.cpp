#include <bits/stdc++.h>

using namespace std;

int main() {                                 
	int n;
	cin >> n;  
	int cnt = 0, ans = 0;
	for (int i = 0; i < n; i++) {
	 	int x;
	 	cin >> x;
	 	if (x > -1) {
	 	  cnt += x;
	 	} else {
	 	 	if (cnt > 0) {
	 	 	 	cnt--;
	 		} else {
	 		 	ans++;
	 		}
	 	}
	}
	cout << ans;
}
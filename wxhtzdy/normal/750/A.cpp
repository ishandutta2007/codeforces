#include <bits/stdc++.h>

using namespace std;

int main() {                                 
	int n, k;
	cin >> n >> k;
	int m = 4 * 60 - k, cnt = 0;
	for (int i = 1; i <= n; i++) {
	  if (m >= i * 5) {
	   	cnt++;
	   	m -= i * 5;
	  } else {
	   	break;
	  }
	}
	cout << cnt;	
}
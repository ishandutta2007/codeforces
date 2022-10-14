#include <bits/stdc++.h>

using namespace std;

int main() {                  
	int n, m;
	cin >> n >> m;
	bool ok = false;
	for (int i = 0; i < n; i++) {
	  for (int j = 0; j < m; j++) {
	   	char c;
	   	cin >> c;
	   	if (c != 'B' && c != 'W' && c != 'G') {
	   	  ok = true;
	   	}
	  }
	}
	cout << (ok ? "#Color" : "#Black&White");	
}
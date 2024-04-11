#include <bits/stdc++.h>

using namespace std;

int main() {              
	int n;
	cin >> n;
	cout << (n - n % 2) / 2 << endl;
	for (int i = 0; i < (n - n % 2) / 2; i++) {
	  if (n % 2 == 1 && i == (n - n % 2) / 2 - 1) {
	  	cout << 3 << " ";
	  } else {
	   	cout << 2 << " ";
	  }
	}	
}
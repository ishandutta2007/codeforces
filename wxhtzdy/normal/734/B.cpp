#include <bits/stdc++.h>

using namespace std;

int main() {        
	vector<int> a(4);
	for (int i = 0; i < 4; i++) {
	  cin >> a[i];
	}	
	long long sum = 0;
	while (a[0] > 0 && a[2] > 0 && a[3] > 0) {
	 	sum += 256;
	 	a[0]--;
	 	a[2]--;
	 	a[3]--;
	}
	while (a[0] > 0 && a[1] > 0) {
	 	sum += 32;
	 	a[0]--;
	 	a[1]--;
	}
	cout << sum;
}
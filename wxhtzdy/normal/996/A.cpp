#include <bits/stdc++.h>

using namespace std;

int main() {                  
	int n;
	cin >> n;
	vector<int> a = {1 , 5, 10, 20, 100};
	int cnt = 0;
	while (n > 0) {
	 	for (int i = 4; i >= 0; i--) {
	 	 	if (n >= a[i]) {
	 	 	 	n -= a[i];
	 	 		break;
	 	 	}     
	 	}
	 	cnt++;
	}
	cout << cnt;
}
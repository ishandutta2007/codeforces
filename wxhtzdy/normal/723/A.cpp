#include <bits/stdc++.h>

using namespace std;

int main() {                                 
	vector<int> a(3);
	for (int i = 0; i < 3; i++) {
	 	cin >> a[i];	
	}
	sort(a.begin(), a.end());
	cout << a[2] - a[0];
}
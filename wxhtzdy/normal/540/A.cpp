#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	int res = 0;
	for (int i = 0; i < n; i++) {
	  int x = (int) a[i] - '0', y = (int) b[i] - '0';
	  res += min(abs(x - y), 9 - abs(x - y) + 1);
	}	
	cout << res;
}
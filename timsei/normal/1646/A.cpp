#include <bits/stdc++.h>
using namespace std;


#define int long long
const int N = 1e6 + 5;

int n, s;

main() {
	int t;
	for(cin >> t; t --;) {
		cin >> n >> s;
		cout << s / (n * n) << endl;
	}
}
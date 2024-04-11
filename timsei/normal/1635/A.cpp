#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, t, x;

int main() {
	for(cin >> t; t --;) {
		scanf("%d", &n); int a = 0;
		for(int i = 1; i <= n; ++ i) scanf("%d", &x), a |= x;
		cout << a << endl;
		
	}
}
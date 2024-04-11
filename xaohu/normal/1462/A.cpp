#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int>
typedef long long ll;	
using namespace std;

int T, n, b[305];

int main() { 
	cin >> T;
	while (T--) {
		cin >> n;
		rep(i, 0, n)
			cin >> b[i];
		rep(i, 0, n) {
			if (i % 2 == 0)
				cout << b[i / 2] << " ";
			else
				cout << b[n - 1 - i / 2] << " ";
		}
		cout << "\n";
	}
	return 0;
}
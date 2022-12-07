#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int>
typedef long long ll;	
using namespace std;

int T, n;

int main() { 
	cin >> T;
	while (T--) {
		cin >> n;
		rep(i, n + 1, 2 * n + 1)
			cout << 2 * i << " ";
		cout << "\n";
	}
	return 0;
}
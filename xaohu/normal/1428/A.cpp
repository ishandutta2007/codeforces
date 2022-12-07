#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;
using namespace std;

int T, a, b, c, d;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> T;
	while (T--) {
		cin >> a >> b >> c >> d;
		cout << abs(a - c) + abs(b - d) + (a == c || b == d ? 0 : 2) << endl;
	}

	return 0;
}
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
typedef long long ll;
using namespace std;
int n, x, y;

int main() {
	cin >> n >> x >> y;
	int can = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		can += (a <= x);
	}
	if (x > y)
		cout << n << endl;
	else
		cout << (can + 1) / 2 << endl;
	return 0;
}
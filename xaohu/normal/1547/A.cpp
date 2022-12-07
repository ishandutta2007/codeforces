#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define vi vector<int> 
typedef long long ll;	
using namespace std;

int dis(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}

void solve() {
	int xa, ya, xb, yb, xc, yc;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;

	int d = dis(xa, ya, xb, yb);

	if (xa != xb && ya != yb)
		cout << d << endl;
	else if (dis(xa, ya, xc, yc) + dis(xb, yb, xc, yc) != d)
		cout << d << endl;
	else
		cout << d + 2 << endl;
}

int main() {
	int T;
	cin >> T;
	while (T--)
		solve();
	return 0;
}
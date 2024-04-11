#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int a, b, c, d, n;
ll ans;
int main() {
	cin >> n >> a >> b >> c >> d;
	for (int i = 1; i <= n; ++i) {
		int A = i, B = A + b - c, D = A + a - d, E = a + B - d;
		if (B >= 1 && B <= n && D >= 1 && D <= n && E >= 1 && E <= n) ++ans;
	}
	ans = ans * n;
	cout << ans << endl;
}
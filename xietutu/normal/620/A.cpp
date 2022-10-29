#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int x1, y1, x2, y2;
int main() {
	cin >> x1 >> y1 >> x2 >> y2;
	LL tx = abs(x1 - x2), ty = abs(y1 - y2);
	LL t = min(tx, ty);
	cout << tx + ty - t << endl;
}
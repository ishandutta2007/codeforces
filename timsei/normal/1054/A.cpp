#include <bits/stdc++.h>
using namespace std;

int x, y, z, t1, t2, t3;

int main() {
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	int A = abs(x - y) * t1, B = t3 * 3 + t2 * abs(z - x) + t2 * abs(x - y);
	if(A < B) puts("NO");
	else puts("YES");
}
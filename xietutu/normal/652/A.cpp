#include <bits/stdc++.h>
using namespace std;
long long h1, h2, a, b;
bool flag;
int main() {
	cin >> h1 >> h2 >> a >> b;
	for (int i = 0; i <= 200000; ++i) {
		if (i == 0) h1 += 8 * a;
		else h1 += 12 * a;
		if (h1 >= h2) {
			printf("%d\n", i);
			flag = true;
			break;
		}
		h1 -= 12 * b;
	}
	if (!flag) printf("-1\n");
}
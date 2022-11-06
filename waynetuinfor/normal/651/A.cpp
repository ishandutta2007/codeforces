#include <bits/stdc++.h>
using namespace std;

int a1, a2, t;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a1 >> a2;
	while (a1 && a2) {
		if (a1 < 2 && a2 < 2) break; 
		if (a1 < a2) a1++, a2 -= 2;
		else a2++, a1 -= 2;
		++t;
	}
	cout << t << '\n';
	return 0;
}
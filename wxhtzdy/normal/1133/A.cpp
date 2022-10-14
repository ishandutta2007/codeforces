#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a, b;
	cin >> a >> b;
	int k1 = (int)(a[0] - '0') * 10 + (int)(a[1] - '0');
	k1 *= 60;
	k1 += (int)(a[3] - '0') * 10 + (int)(a[4] - '0');
	int k2 = (int)(b[0] - '0') * 10 + (int)(b[1] - '0');
	k2 *= 60;
	k2 += (int)(b[3] - '0') * 10 + (int)(b[4] - '0');
	int k = (k1 + k2) / 2;
	if (k / 60 < 10) cout << 0;
	cout << k / 60 << ':';
	k %= 60;
	if (k < 10) cout << 0;
	cout << k;
	return 0;
}
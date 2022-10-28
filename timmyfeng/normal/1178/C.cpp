#include <bits/stdc++.h> 
using namespace std;

const int M = (119 << 23) + 1;

int mul(int a, int b) {
	return 1LL * a * b % M;
}

int mod_pow(int a, int b) {
	int res = 1;
	while (b) {
		if (b % 2) {
			res = mul(res, a);
		}
		a = mul(a, a);
		b /= 2;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int w, h;
	cin >> w >> h;
	cout << mod_pow(2, w + h) << "\n";
}
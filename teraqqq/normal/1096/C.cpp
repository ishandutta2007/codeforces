#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int MOD = 998244353;
const int N = 2e5;
const int K = 10;

int t, ang;

int gcd(int a, int b) {
	while(b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}

	return a;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	for(cin >> t; t--;) {
		cin >> ang;

		int g = gcd(ang, 180);
		int q = 180 / gcd(ang, 180);
		int p = ang / gcd(ang, 180);
		int a = 1;
		while((a*q-2)*180 < ang*a*q) ++a;
		cout << q*a << endl;
	}
}
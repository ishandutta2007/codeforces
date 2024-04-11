#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, k;
int a[32], b;

bool solve() {
	for(int i = 0; n != 0; ++i) {
		b += (a[i] = n % 2);
		n /= 2;
	}

	if(b > k) return false;
	for(int i = 31; i > 0 && b != k; --i) {
		int da = min(k-b, a[i]);
		a[i] -= da;
		a[i-1] += da*2;
		b += da;
	}

	return b == k;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;

	if(solve()) {
		cout << "YES" << endl;
		for(int i = 0, x = 1; i < 32; ++i) {
			while(a[i]--)
				cout << x << ' ';
			x *= 2;
		}
		cout << endl;
	}
	else cout << "NO" << endl;
}
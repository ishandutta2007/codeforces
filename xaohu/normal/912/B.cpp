#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

ll n, k;

int main() {
	cin >> n >> k;
	if (k == 1)
		cout << n;
	else {
		per(i, 0, 60)
			if (n >> i & 1) {
				cout << (1ll << (i + 1)) - 1;
				break;
			}
	}
	return 0;
}
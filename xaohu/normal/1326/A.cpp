#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; a <= i; i--)
#define sz(x) (int)x.size()
using namespace std;
typedef long long ll;	

int T, n;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> T;
	while (T--) {
		cin >> n;
		if (n == 1) {
			cout << "-1\n";
		}
		else {
			cout << 2;
			while (n > 1) {
				cout << 9;
				n--;
			}
			cout << endl;
		}
	}
	return 0;
}
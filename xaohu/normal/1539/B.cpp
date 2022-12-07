#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
using namespace std;

int n, q, a[111000];
string s;
 
int main() {
	cin >> n >> q >> s;
	rep(i, 1, n) a[i] = a[i - 1] + (s[i - 1] - 'a' + 1);
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << a[r] - a[l - 1] << endl;
	}
	return 0;
}
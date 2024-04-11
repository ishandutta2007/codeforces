#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;
 
int n, a = 1, b = 2, value, ans[5123];

int ask(int x, int y) {
	cout << "? " << x << " " << y << endl;
	cin >> x;
	return x;
}
 
int main() {
	cin >> n;
	value = ask(1, 2);
	rep(i, 3, n) {
		int q = ask(i, a);
		if (q != value) {
			if (q < value) {
				b = i;
				value = q;
			}
		}
		else {
			a = i;
			value = ask(a, b);
		}
	}
	while (1) {
		int c = rand() % n + 1;
		if (c == a || c == b)
			continue;
		int qa = ask(c, a);
		int qb = ask(c, b);
		if (qa != qb) {
			if (qb < qa)
				a = b;
			break;
		}
	}
	rep(i, 1, n)
		if (i != a)
			ans[i] = ask(i, a);
	cout << "! ";
	rep(i, 1, n) 
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}
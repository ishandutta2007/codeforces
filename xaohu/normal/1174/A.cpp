#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;

int n, a[2005];

int main() {
	cin >> n;
	rep(i, 1, 2 * n)
		cin >> a[i];
	sort(a + 1, a + 2 * n + 1);
	if (a[1] == a[2 * n])
		return cout << "-1\n", 0;
	rep(i, 1, 2 * n)
		cout << a[i] << " ";
	return 0;
}
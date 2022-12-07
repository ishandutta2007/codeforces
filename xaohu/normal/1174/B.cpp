#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;

int n, a[100111], cnt[2];

int main() {
	cin >> n;
	rep(i, 1, n) {
		cin >> a[i];
		cnt[a[i] % 2]++;
	}
	if (min(cnt[0], cnt[1]))
		sort(a + 1, a + n + 1);
	rep(i, 1, n)
		cout << a[i] << " ";
	return 0;
}
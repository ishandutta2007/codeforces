#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, i, ans = 1111111111, a,p;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> a;
		if (i < n / 2)
			p = a / (n - 1 - i);
		else
			p = a / i;
		if (p < ans)
			ans = p;
	}
	cout << ans << endl;
}
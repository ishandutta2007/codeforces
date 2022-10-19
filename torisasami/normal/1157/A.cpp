#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, ans = 0;
	cin >> n;
	while (1) {
		if (n / 10 != 0)
			ans += 10 - n % 10;
		else
			ans += 9;
		n /= 10;
		if (n == 0)
			break;
		n++;
		while (n % 10 == 0)
			n /= 10;
	}
	cout << ans << endl;
}
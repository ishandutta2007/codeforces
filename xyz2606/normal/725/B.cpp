#include<bits/stdc++.h>
using namespace std;
int main() {
	long long n;
	char c;
	cin >> n >> c;
	long long ans(0);
	ans += (n - 1) / 4 * 16;
	n = (n - 1) % 4;
	if(n >= 2) {
		n -= 2;
	}
	if(n == 1) {
		ans += 7;
	}
	ans += c == 'f' ? 1 : c == 'e' ? 2 : c == 'd' ? 3 : c == 'a' ? 4 : c == 'b' ? 5 : 6;
	cout << ans << endl;
}
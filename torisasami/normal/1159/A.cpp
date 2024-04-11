#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int ans = 0, n, i;
	char s[1111];
	cin >> n >> s;
	for (i = 0; i < n; i++) {
		if (s[i] == '-') {
			if (ans > 0)
				ans--;
		}
		else
			ans++;
	}
	cout << ans << endl;
}
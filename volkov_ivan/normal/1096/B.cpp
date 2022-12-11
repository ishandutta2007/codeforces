#include <iostream>

using namespace std;

const long long M = 998244353;

int main() {
	int n;
	string s;
	cin >> n >> s;
	long long ans = 0;
	char left = s[0], right = s[n - 1];
	long long cnt_left = 1, cnt_right = 1;
	for (int i = 1; i < n; i++) {
		if (s[i] == left) cnt_left++;
		else break;
	}
	for (int i = n - 2; i >= 0; i--) {
		if (s[i] == right) cnt_right++;
		else break;
	}
	if (left != right) {
		cout << cnt_left + cnt_right + 1 << endl;
		return 0;
	}
	ans += (cnt_left + 1) * (cnt_right + 1);
	cout << ans % M << endl;
	return 0;
}
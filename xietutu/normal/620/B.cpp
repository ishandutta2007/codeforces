#include <bits/stdc++.h>
using namespace std;
const int nums[10] = {6,2,5,5,4,5,6,3,7,6};
int a, b, ans;
inline int calc(int x) {
	int ret = 0;
	while (x) {
		ret += nums[x % 10];
		x /= 10;
	}
	return ret;
}
int main() {
	cin >> a >> b;
	for (int i = a; i <= b; ++i)
		ans += calc(i);
	cout << ans << endl;
}
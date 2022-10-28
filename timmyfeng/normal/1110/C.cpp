#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> ans(26);
	ans[1] = 0;
	ans[2] = 1;
	ans[3] = 1;
	ans[4] = 5;
	ans[5] = 1;
	ans[6] = 21;
	ans[7] = 1;
	ans[8] = 85;
	ans[9] = 73;
	ans[10] = 341;
	ans[11] = 89;
	ans[12] = 1365;
	ans[13] = 1;
	ans[14] = 5461;
	ans[15] = 4681;
	ans[16] = 21845;
	ans[17] = 1;
	ans[18] = 87381;
	ans[19] = 1;
	ans[20] = 349525;
	ans[21] = 299593;
	ans[22] = 1398101;
	ans[23] = 178481;
	ans[24] = 5592405;
	ans[25] = 1082401;

	int q;
	cin >> q;
	while (q--) {
		int a;
		cin >> a;
		if (a & (a + 1)) {
			cout << (1 << (32 - __builtin_clz(a))) - 1 << "\n";
		} else {
			cout << ans[__builtin_ctz(a + 1)] << "\n";
		}
	}
}
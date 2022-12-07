#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
 
using namespace std;

int n, x, ban[1 << 20], last;
vector<int> ans;

int main() {
	cin >> n >> x;
	ban[0] = 1;
	rep(i, 1, (1 << n) - 1) {
		if (ban[(i ^ x)]) continue;
		ban[i] = 1;
		ans.push_back((i ^ last));
		last = i;
	}
	cout << ans.size() << "\n";
	for (auto e : ans)
		cout << e << " ";
	return 0;
}
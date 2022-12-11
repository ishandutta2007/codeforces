#include <iostream>
#define int long long

using namespace std;

int get_2(int l, int r) {
	int len = r - l + 1;
	if (l % 2 == 1) return(1 * (len / 2));
	else return (-1 * (len / 2)); 
}

signed main() {
	int q;
	int l, r;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		int len = (r - l + 1);
		if (len % 2 == 0) {
			cout << get_2(l, r) << '\n'; 
		}
		else {
			int ans = get_2(l + 1, r);
			if (l % 2 == 1) ans += -l;
			else ans += l;
			cout << ans << '\n';
		}
	}
	return 0;
}

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
int k;

bool find(int x) {
	int ans=0;
	while(x) {
		ans += x%10;
		x /= 10;
	}
	return ans == 10;
}
void solve() {
	cin >> k;
	int res = 1;

	while(k > 0) {
		++res;
		if(find(res)) k--;
	}

	cout << res << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int t = 1;
	//cin >> t;
	int i = 1;
	while(t--) {
		solve();
		++i;
	}
}
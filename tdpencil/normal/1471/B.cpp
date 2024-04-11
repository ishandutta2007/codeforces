#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn = 2e5;
int a[mxn];
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		for(int i=0; i < n; i++) cin >> a[i];
		ll c=0, ep=0, cp=0;
		for(int i=0; i < n; i++) {
			int cnt=1;
			for(int x=a[i]; x % k == 0; x /= k) cnt++;
			if(i == 0 || cnt < c) {
				c=cnt;
				ep=cp;
			}
			cp += a[i];
		}

		cout << c * cp + ep << "\n";

	}
}
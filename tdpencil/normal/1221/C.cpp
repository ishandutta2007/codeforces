#include <bits/stdc++.h>

using namespace std;

int main(){
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i){
		int c, m, x;
		cin >> c >> m >> x;
		int l = 0, r = min(c, m);
		int ans = 0;
		while (l <= r){
			int mid = (l + r) / 2;
			if (c + m + x - 2 * mid >= mid){
				l = mid + 1;
				ans = mid;
			}
			else{
				r = mid - 1;
			}
		}
		cout << ans << "\n";
	}
}
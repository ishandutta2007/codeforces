#include<bits/stdc++.h>

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a, a + n);
		int ans = 0; 
		int trsize = 0, mini = 0;
		for(int i = 0; i < n; ++i) {
			mini = a[i];
			trsize++;
			if(trsize >= mini) {
				ans++;
				trsize = 0;
			}
		}
		cout << ans << endl;
	}
}
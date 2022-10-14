#include <bits/stdc++.h>

using namespace std;

int main() {
	
	int t;
	scanf("%d", &t);
	
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		
		int a[n];
		
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
	
		map<int, int> cnt;
		for (int i = 0; i < n / 2; i++)
			cnt[a[i] + a[n - i - 1]]++;
		
		vector<int> pref(2 * k + 5);
		for (int i = 0; i < n / 2; i++) {
			pref[min(a[i], a[n - i - 1]) + 1]++;
			pref[max(a[i], a[n - i - 1]) + k + 1]--;
		}
		
		vector<int> change(2 * k + 5);
		for (int i = 1; i <= 2 * k; i++)
			change[i] = change[i - 1] + pref[i];
		
		int mn = 2 * n;
		for (int x = 1; x <= 2 * k; x++) {
			int cr = change[x] - cnt[x];
			cr += (n / 2 - change[x]) * 2;
			mn = min(mn, cr);
		}
		
		printf("%d\n", mn);
	}
	
	return 0;
}
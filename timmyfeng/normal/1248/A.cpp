#include <bits/stdc++.h>
using namespace std;
int freq[2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		freq[0] = freq[1] = 0;
		while (n--) {
			int a;
			cin >> a;
			++freq[a % 2];
		}
		long long ans = 0;
		int m;
		cin >> m;
		while (m--) {
			int b;
			cin >> b;
			ans += freq[b % 2];
		}
		cout << ans <<'\n';
	}
}
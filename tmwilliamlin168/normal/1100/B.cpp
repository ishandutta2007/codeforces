#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 100;

int n, m, ok, num, cnt[N];

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	while(m--) {
		cin >> num;
		if(cnt[num] == 0)
			ok++;
		cnt[num]++;
		cout << (ok == n);
		if(ok == n)
			for (int i = 1; i <= n; i++) {
				if(cnt[i] == 1)
					ok--;
				cnt[i]--;
			}
	}
	return 0;
}
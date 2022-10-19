#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int t, n, m, cnt[N], x, cnt2[N];

int main() {
	cin >> n;
	int m = -n;
	for(int i = 1; i <= n; ++ i) {
		scanf("%d", &x);
		++ cnt[x];
	}
	n = 1e6;
	for(int i = 1; i <= n; ++ i) {
		for(int j = i; j <= n; j += i) cnt2[i] += cnt[j];
	}
	
	for(int i = 1; i <= n; ++ i) {
		bool ok = 1;
		for(int j = i * 2; j <= n;j += i) {
			if(cnt2[j] == cnt2[i]) ok = 0;
		}
		if(ok && cnt2[i]) ++ m;
	}
	cout << m << endl;
}
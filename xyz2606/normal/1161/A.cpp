#include<bits/stdc++.h>
using namespace std;
const int N(222222);
int mx[N], mn[N];
int main() {
	int n, k;
	cin >> n >> k;
	for(int i(1); i <= n; i++) {
		mn[i] = k + 10;
		mx[i] = -10;
	}
	for(int i(0); i < k; i++) {
		int x;
		scanf("%d", &x);
		mn[x] = min(mn[x], i);
		mx[x] = max(mx[x], i);
	}
	int ans = 0;
	for(int i(1); i <= n; i++) {
		if(mx[i] == -10) ans++;
	}
	for(int i(1); i < n; i++) {
		if(mn[i] > mx[i + 1]) ans++;
		if(mn[i + 1] > mx[i]) ans++;
	}
	cout << ans << endl;
}